class Solution {
public:
    bool dfs(
        string src,
        string dest,
        unordered_map<string,vector<pair<string,double>>> &graph,
        unordered_set<string>& vis,double& ans, double product
    
    )
    {
        if(src==dest)
        {
            ans=product;
            return true;
        }
        vis.insert(src);
        for(auto& nbr: graph[src]){
            string next=nbr.first;
            double weight=nbr.second;
        
                if(!vis.count(next))
                {
                    if(dfs(next,
                    dest,
                    graph,
                    vis,
                    ans,
                    product*weight)){
                        return true;
                    }
                }
           }
           return false;

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string,vector<pair<string,double>>> graph;

    
    for(int i=0; i<equations.size(); i++){
        string a=equations[i][0];
        string b=equations[i][1];

        double val=values[i];

        graph[a].push_back({b,val});
        graph[b].push_back({a,1.0/val});
    }
    vector<double >result;


    for(auto& q:queries){
        string src=q[0];
        string dest=q[1];
        if(!graph.count(src)||!graph.count(dest))
    {
        result.push_back(-1.0);
        continue;
    }
    double ans=-1.0;

    unordered_set<string> vis;
    dfs(
        src,dest,graph,vis,ans,1.0
    );
     result.push_back(ans);

    }

    return result;

    }
};