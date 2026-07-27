class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int maxi=-1;
         int second=-1;
         int index=-1;

         for(int i=0;i<nums.size();i++)
         {
             if(nums[i]>maxi)
             {
                 second= maxi;
                 maxi=nums[i];
                 index++;
               

             }
             else if(nums[i]>second)
             {
                    second = nums[i];
             }
         }

         return ((maxi-1)*(second-1));
    }
};