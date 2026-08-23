class Solution {
public:

    int firstoccurence(vector<int>& nums,int target){

    int low=0;
    int high=nums.size()-1;
    int ans=-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==target){
            ans=mid;
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
           high=mid-1;
    }
    }
    return ans;
    }

    int lastoccurence(vector<int>& nums,int target){

    int low=0;
    int high=nums.size()-1;
    int ans=-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==target){
            ans=mid;
            low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
           high=mid-1;
    }
    }
    return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
     /*int f = -1;
        int l= -1;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == target){

                if(f == -1)
                    f = i;

                l = i;
            }
        }

    
    return {f,l};
    */
    return{firstoccurence(nums,target), lastoccurence(nums,target)};
   
    }
};