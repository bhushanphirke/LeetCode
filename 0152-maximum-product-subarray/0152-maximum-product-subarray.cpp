class Solution {
public:
    int maxProduct(vector<int>& nums) {
        

        int pref =1;
        int sufx =1;
        int ans = INT_MIN;
        int n =  nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(pref == 0) pref = 1;
            if(sufx == 0) sufx = 1;

            pref = pref * nums[i];
            sufx = sufx * nums[n-i-1];
            ans = max(ans , max(pref , sufx));
        }

        return ans; 
    }
};