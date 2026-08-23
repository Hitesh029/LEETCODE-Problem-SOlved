class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();


        vector<vector<long long>> maxDP(m,vector<long long>(n));
        vector<vector<long long>> minDP(m,vector<long long>(n));

        maxDP[0][0]=minDP[0][0]=grid[0][0];


        for(int i=1; i<m; i++){
            maxDP[i][0]=minDP[i][0];
            maxDP[i-1][0]*grid[i][0];
        }

        
        for(int j=1; j<n; j++){
            maxDP[0][j]=minDP[0][j];
            maxDP[0][j-1]*grid[0][j];
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                long long a= maxDP[i-1][j]*grid[i][j];
                long long b= minDP[i-1][j]*grid[i][j];
                long long c= maxDP[i][j-1]*grid[i][j];
                long long d= minDP[i][j-1]*grid[i][j];
            }
        }

        long long ans=maxDP[m-1][n-1];

        if(ans<0)
              return -1;
        return ans% 100000007;      
    }
};