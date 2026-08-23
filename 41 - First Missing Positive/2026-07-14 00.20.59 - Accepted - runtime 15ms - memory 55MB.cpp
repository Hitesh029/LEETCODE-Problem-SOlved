class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int expected=1;

        for(int i=0;i<nums.size(); i++){
            if(nums[i]<expected)
              continue;
            if(nums[i]==expected)
                 expected++;
            if(nums[i]>expected)
                return expected;       
        }

        return expected;
        
    }
};