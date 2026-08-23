class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<string,int>map;

        for(int i=0; i<n; i++){
            string row="";
            for(int j=0; j<n; j++){
                row+=to_string(grid[i][j])+ "#";
            }
            map[row]++;
        }

        int ans=0;

        for(int col=0; col<n; col++)
        {
            string curr="";

            for(int row=0; row<n; row++){
                curr+=to_string(grid[row][col])+"#";
            }
            ans+=map[curr];
        }
        return ans;
    }
};