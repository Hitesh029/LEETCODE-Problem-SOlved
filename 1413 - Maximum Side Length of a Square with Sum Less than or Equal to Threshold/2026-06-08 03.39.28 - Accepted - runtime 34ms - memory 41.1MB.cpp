class Solution {
public:

    bool possible(int len,
                  vector<vector<int>>& prefix,
                  int threshold)
    {
        if(len == 0) return true;

        int m = prefix.size();
        int n = prefix[0].size();

        for(int i = len - 1; i < m; i++)
        {
            for(int j = len - 1; j < n; j++)
            {
                int total = prefix[i][j];

                if(i - len >= 0)
                    total -= prefix[i - len][j];

                if(j - len >= 0)
                    total -= prefix[i][j - len];

                if(i - len >= 0 && j - len >= 0)
                    total += prefix[i - len][j - len];

                if(total <= threshold)
                    return true;
            }
        }

        return false;
    }

    int maxSideLength(vector<vector<int>>& mat,
                      int threshold)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m,
                                   vector<int>(n, 0));


        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                prefix[i][j] = mat[i][j];

                if(i > 0)
                    prefix[i][j] += prefix[i - 1][j];

                if(j > 0)
                    prefix[i][j] += prefix[i][j - 1];

                if(i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }

        int left = 0;
        int right = min(m, n);
        int ans = 0;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(possible(mid, prefix, threshold))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};