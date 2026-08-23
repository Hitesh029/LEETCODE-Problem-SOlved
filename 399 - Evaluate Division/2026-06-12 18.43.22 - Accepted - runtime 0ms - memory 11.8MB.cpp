class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    string find(string x)
    {
        if(parent[x] != x)
        {
            string orig = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[orig];
        }
        return parent[x];
    }

    void unite(string a, string b, double value)
    {
        if(!parent.count(a))
        {
            parent[a] = a;
            weight[a] = 1.0;
        }

        if(!parent.count(b))
        {
            parent[b] = b;
            weight[b] = 1.0;
        }

        string rootA = find(a);
        string rootB = find(b);

        if(rootA != rootB)
        {
            parent[rootA] = rootB;

            weight[rootA] =
                value * weight[b] / weight[a];
        }
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries)
    {
        for(int i = 0; i < equations.size(); i++)
        {
            unite(
                equations[i][0],
                equations[i][1],
                values[i]
            );
        }

        vector<double> ans;

        for(auto& q : queries)
        {
            string a = q[0];
            string b = q[1];

            if(!parent.count(a) ||
               !parent.count(b))
            {
                ans.push_back(-1.0);
            }
            else if(find(a) != find(b))
            {
                ans.push_back(-1.0);
            }
            else
            {
                ans.push_back(
                    weight[a] / weight[b]
                );
            }
        }

        return ans;
    }
};