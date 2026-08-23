class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1)
            return s;

        int n = s.size();
        int cycle = 2 * (numRows - 1);

        string ans;

        for(int row = 0; row < numRows; row++) {

            for(int j = row; j < n; j += cycle) {

                ans += s[j];

                int diagonal =
                    j + cycle - 2 * row;

                if(row != 0 &&
                   row != numRows - 1 &&
                   diagonal < n)
                {
                    ans += s[diagonal];
                }
            }
        }

        return ans;
    }
};