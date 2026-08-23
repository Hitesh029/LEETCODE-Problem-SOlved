class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0; 
        int ans=0;

        for( int x: gain){
            current+=x;
            ans=max(ans,curr);

        }
        return ans;
    }
};