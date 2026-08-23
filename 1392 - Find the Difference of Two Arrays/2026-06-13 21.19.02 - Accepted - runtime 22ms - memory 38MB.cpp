class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>sort1(nums1.begin(),nums1.end());
        set<int>sort2(nums2.begin(),nums2.end());
        vector<int>ans1;
        vector<int>ans2;

        for(auto x: sort1){
            if(sort2.find(x)==sort2.end()){
                ans1.push_back(x);
            }
        }
        for(auto x:sort2){
            if(sort1.find(x)==sort1.end()){
                ans2.push_back(x);
            }
        }
        return{ans1,ans2};
      
        
    }
};