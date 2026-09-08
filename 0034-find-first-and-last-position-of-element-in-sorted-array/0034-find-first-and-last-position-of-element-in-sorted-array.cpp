
class Solution {
public:

    int first(vector<int> &nums , int n, int x)
    {
       int low =0;
       int high = n-1;
       int ans = n;
       while(low <= high)
       {
          int mid = low + (high - low) / 2;

          if(nums[mid] >= x)
          {
              ans = mid;
              high = mid - 1;
          }
          else
          {
              low = mid +1;
          }
       }
       return ans;
    }
    int last(vector<int> &nums , int n, int x)
    {
        int low =0;
       int high = n-1;
       int ans = n;
       while(low <= high)
       {
          int mid = low + (high - low) / 2;

          if(nums[mid] > x)
          {
              ans = mid;
              high = mid - 1;
          }
          else
          {
              low = mid +1;
          }
       }
       return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
       
       int n = nums.size();
       int lb = first(nums , n , target);
       if(lb == n || nums[lb] != target )
       {
           return {-1,-1};
       }
       int x = last(nums , n , target)-1;
       return {lb , x};
    }
};