class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());

        map<int, int> mpp;
        vector<int> ans;

        for(int i=mn;i<=mx;i++)
        {
           mpp[i]++;
        }

        for(int i=0;i<nums.size();i++)
        {
           mpp[nums[i]]++;
        }

        for(auto it : mpp)
        {
            if(it.second==1)
            {
                 ans.push_back(it.first);
            }
        }

        return ans;

    }
};