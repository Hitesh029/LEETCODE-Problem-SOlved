class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size();

        map<vector<int>, int> mp;

        for(auto &row : grid)
        {
            mp[row]++;
        }

        int ans = 0;

        for(int col = 0; col < n; col++)
        {
            vector<int> curr;

            for(int row = 0; row < n; row++)
            {
                curr.push_back(grid[row][col]);
            }

            ans += mp[curr];
        }

        return ans;
    }
};