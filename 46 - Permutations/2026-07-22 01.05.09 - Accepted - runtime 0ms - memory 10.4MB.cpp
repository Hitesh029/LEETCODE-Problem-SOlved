class Solution {
public:
    /*
    void solve(vector<int>& nums,
                  vector<int>& temp,
                  vector<int>& used,
                  vector<vector<int>>& ans ){
                    if(temp.size()==nums.size()){
                        ans.push_back(temp);
                        return;
                    }
                    for(int i=0; i<nums.size(); i++){
                        if(used[i])
                           continue;
                        used[i]=1;
                        temp.push_back(nums[i]);

                        solve(nums,temp,used,ans);
                        temp.pop_back();
                        used[i]=0;   
                    }

                  }


*/


    void solve(int index,
               vector<int>& nums,
               vector<vector<int>>& ans){

        if(index == nums.size()){

            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){

            swap(nums[index], nums[i]);

            solve(index + 1, nums, ans);

            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
       
        solve(0,nums,ans);
        return ans;
    }
};