class Solution {
public:

    void dfs(int city, vector<vector<int>>& isConnected,
             vector<bool>& vis)
    {
        vis[city] = true;

        for(int j = 0; j < isConnected.size(); j++)
        {
            if(isConnected[city][j] == 1 && !vis[j])
            {
                dfs(j, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();

        vector<bool> vis(n, false);

        int province = 0;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                province++;
                dfs(i, isConnected, vis);
            }
        }

        return province;
    }
};