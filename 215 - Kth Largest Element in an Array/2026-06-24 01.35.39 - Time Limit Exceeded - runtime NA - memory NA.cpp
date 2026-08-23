class Solution {
public:

    int partition(vector<int>& nums,
                  int low,
                  int high)
    {
        int pivot = nums[high];

        int i = low;

        for(int j = low; j < high; j++)
        {
            if(nums[j] <= pivot)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[high]);

        return i;
    }

    int findKthLargest(vector<int>& nums,
                       int k)
    {
        int target =
            nums.size() - k;

        int low = 0;
        int high = nums.size()-1;

        while(true)
        {
            int p =
                partition(
                    nums,
                    low,
                    high);

            if(p == target)
            {
                return nums[p];
            }

            else if(p < target)
            {
                low = p + 1;
            }

            else
            {
                high = p - 1;
            }
        }
    }
};