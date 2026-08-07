class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int , int> mpp;
        mpp[0] = 1;
        int prefixsum=0;
        int cnt =0;

        for(int i=0;i<nums.size();i++)
        {
            prefixsum+=nums[i];
            int rem = prefixsum - k;
            
            if(mpp.find(rem) != mpp.end())
            {
                 cnt += mpp[rem];
            }

            mpp[prefixsum] +=1;

        }

        return cnt;

    }
};