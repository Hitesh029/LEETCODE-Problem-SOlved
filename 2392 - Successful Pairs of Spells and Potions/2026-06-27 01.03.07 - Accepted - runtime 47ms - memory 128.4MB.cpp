class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int m=potions.size();
        vector<int>ans;

        for(int spell:spells){
            int low=0;
            int high=m-1;
            int idx=m;

            while(low<=high){
                int mid=low+(high-low)/2;
                long long product=1LL*spell*potions[mid];

                if(product>=success){
                    idx=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
           ans.push_back(m-idx);

        }
        return ans;
    }
};