class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;

        for (int n:nums1){
            arr.push_back(n);
        }
        for (int n: nums2){
            arr.push_back(n);
        }
        sort(arr.begin(), arr.end());
        int a=arr.size();

        if(a%2==1){
            return arr[a/2];
        }
        else{
            return (arr[a/2-1]+arr[a/2])/2.0;
        }
    }

};