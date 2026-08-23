class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        /*unordered_map<int, int>mp;
        int ans=0;
        for(int x:nums){
            int m=k-x;
            if (mp[m]>0){
                ans++;
                mp[m]--;
            }
            else 
               mp[x]++;
        }*/



         
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;

        int ans = 0;

        while(left < right)
        {
            int sum =
                nums[left] + nums[right];

            if(sum == k)
            {
                ans++;
                left++;
                right--;
            }
            else if(sum < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return ans;
    }
};