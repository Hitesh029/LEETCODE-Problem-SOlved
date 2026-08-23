class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix(n);
        vector<int> ans(n);

        prefix[0] = nums[0];

        for(int i = 1; i < n; i++)
            prefix[i] = max(prefix[i - 1], nums[i]);

        int suffixMin = nums[n - 1];

        ans[n - 1] = prefix[n - 1];

        for(int i = n - 2; i >= 0; i--){

            suffixMin = min(suffixMin, nums[i + 1]);

            if(prefix[i] > suffixMin)
                ans[i] = ans[i + 1];
            else
                ans[i] = prefix[i];
        }

        return ans;
    }
};