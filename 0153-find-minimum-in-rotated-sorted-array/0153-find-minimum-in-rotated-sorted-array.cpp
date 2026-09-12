class Solution {
public:
    int mini(vector<int> nums , int n)
    {
       int low = 0;
       int high = n -1;
       int ans = INT_MAX;
       while(low<=high)
       {
        int mid = (low + high)/2;

        if(nums[low]<=nums[mid])
        {
          ans = min(nums[low], ans);
          low = mid + 1;

        }
        else
        {
          ans = min(nums[mid],ans);
          high = mid - 1;
        }
       }

       return ans;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
         

        return mini(nums,n);
    }
};