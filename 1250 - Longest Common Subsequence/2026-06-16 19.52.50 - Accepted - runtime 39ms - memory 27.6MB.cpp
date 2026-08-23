class Solution {
public:

    vector<vector<int>> dp;

    int solve(
        int i,
        int j,
        string& a,
        string& b)
    {
        if(i == a.size() ||
           j == b.size())
        {
            return 0;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(a[i] == b[j])
        {
            return dp[i][j] =
                1 + solve(
                        i+1,
                        j+1,
                        a,
                        b);
        }

        return dp[i][j] =
            max(
                solve(i+1,j,a,b),
                solve(i,j+1,a,b)
            );
    }

    int longestCommonSubsequence(
        string text1,
        string text2)
    {
        dp.assign(
            text1.size(),
            vector<int>(
                text2.size(),
                -1));

        return solve(
            0,
            0,
            text1,
            text2);
    }
};