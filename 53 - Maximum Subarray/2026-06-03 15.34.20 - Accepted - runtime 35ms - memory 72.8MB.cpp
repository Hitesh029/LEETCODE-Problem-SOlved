class Solution {
public:

    int crossSum(vector<int>& nums, int left, int mid, int right) {

        int leftSum = INT_MIN;
        int sum = 0;

        for(int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;

        for(int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }

    int solve(vector<int>& nums, int left, int right) {

        if(left == right)
            return nums[left];

        int mid = left + (right - left) / 2;

        int leftAns = solve(nums, left, mid);
        int rightAns = solve(nums, mid + 1, right);
        int crossAns = crossSum(nums, left, mid, right);

        return max({leftAns, rightAns, crossAns});
    }

    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};