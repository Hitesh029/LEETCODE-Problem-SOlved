class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int ans=0;
        for(int x:nums){
            int m=k-x;
            if (mp[m]>0){
                ans++;
                mp[m]--;
            }
            else 
               mp[x]++;
        }
        return ans;
    }
};