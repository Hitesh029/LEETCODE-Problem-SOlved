class Solution {
public:
    int maxSubArray(vector<int>& nums) {
 
        int ans = INT_MIN;
        int currentSum=0;

        for(int i=0; i<nums.size(); i++){
            currentSum+=nums[i];
            ans=max(ans,currentSum);
            if(currentSum<0){
                currentSum=0;
                
            }
           
        }
/*
        for(int i=0; i<nums.size(); i++){
          int  sum=0;
            for(int j=i; j<nums.size(); j++){
               
                sum+=nums[j];
                ans=max(ans,sum);

            }
        }

        return ans;
    }
*/

     return ans;
    }
};