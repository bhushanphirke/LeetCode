class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int j=k+1;

        while(j < nums.size())
        {
             if(nums[j]==nums[k])
             {
                j++;
             }
             else
             {
                k++;
                int temp = nums[j];
                nums[j] = nums[k];
                nums[k]=temp;
                j++;
             }
        }
        return k+1;
    }
};