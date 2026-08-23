class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       /* sort(nums.begin(), nums.end());
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
        */

        int n=nums.size();

        int i=0;

        while(i<n){
            int correct=nums[i]-1;
            if(nums[i]>0&& nums[i]<=n && nums[i]!=nums[correct]){
                swap(nums[i],nums[correct]);
            }
            else{
                i++;
            }
        }

            for(int i=0; i<n; i++){
                if(nums[i]!=i+1)
                     return i+1;
            }
            return n+1;
        }
    
};