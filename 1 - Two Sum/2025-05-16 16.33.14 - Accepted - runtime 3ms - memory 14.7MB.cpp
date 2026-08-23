class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // stores num -> index
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return { numMap[complement], i };
        }
        numMap[nums[i]] = i;
    }
    return {}; // Guaranteed to find a solution, so this won't be reached
}
};