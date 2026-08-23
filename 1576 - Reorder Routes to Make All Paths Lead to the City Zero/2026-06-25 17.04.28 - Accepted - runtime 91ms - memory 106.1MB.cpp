class Solution {
public:
    
    int ans=0;

    void dfs(int node,vector<vector<pair<int,int>>>& adj,vector<bool>& vis){
        vis[node]=true;

        for(auto &it:adj[node]){
            int next=it.first;
            int cost=it.second;

            if(!vis[next]){
                ans+=cost;
                dfs(next,adj,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &edge : connections){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        vector<bool> vis(n,false);

        dfs(0,adj,vis);
        
        return ans;
    }
};