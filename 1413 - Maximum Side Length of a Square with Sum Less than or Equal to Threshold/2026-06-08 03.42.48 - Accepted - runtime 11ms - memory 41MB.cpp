class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> pre(m + 1,
                                vector<int>(n + 1, 0));

        // 1-based prefix sum
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                pre[i][j] =
                    mat[i - 1][j - 1]
                    + pre[i - 1][j]
                    + pre[i][j - 1]
                    - pre[i - 1][j - 1];
            }
        }

        int ans = 0;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // only try to increase current answer
                if(i > ans && j > ans)
                {
                    int len = ans + 1;

                    int sum =
                        pre[i][j]
                        - pre[i - len][j]
                        - pre[i][j - len]
                        + pre[i - len][j - len];

                    if(sum <= threshold)
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};