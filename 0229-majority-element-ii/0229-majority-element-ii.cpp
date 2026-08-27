class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 =0;
        int el1;
        int cnt2 =0;
        int el2;

        for(int i=0;i<nums.size();i++)
        {
           if(cnt1==0 && el2 != nums[i])
           {
              el1 = nums[i];
              cnt1 =1;
           }
           else if(cnt2 == 0 && el1 != nums[i])
           {
              el2 = nums[i];
              cnt2 = 1;
           }
           else if(el1 == nums[i]) cnt1 ++;
           else if(el2 == nums[i]) cnt2 ++;
           else
           {
            cnt1 --;
            cnt2 --;
           }
           
        }

        int count1=0;
        int count2=0;
        for(int i=0;i<nums.size();i++)
        {
             if(nums[i] == el1)
             {
                count1++;
             }
             else if(nums[i] == el2)
             {
                count2++;
             }
        }

        int n = nums.size()/3;
        if(count1 > n && count2 > n)
        {
            return {el1 , el2};
        }
        else if(count1 > n)
        {
             return {el1};
        }
        else if(count2 > n){
            return {el2};
        }
       return {};
    }
};