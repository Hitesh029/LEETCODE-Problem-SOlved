class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        int totalSum = 0;

        for(int num : nums)
        {
            totalSum += num;
        }

        int leftSum = 0;

        for(int num:nums)
        {
            int rightSum =
                totalSum - leftSum - num;

            ans[i] =
                abs(leftSum - rightSum);

            leftSum += num;
        }

        return ans;
    }
};