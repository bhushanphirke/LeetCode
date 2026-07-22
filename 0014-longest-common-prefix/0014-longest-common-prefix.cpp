class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());
        int n = strs.size();
        int i = 0;
        int k =0;
        int j = n-1;
        string ans;

        int n1 = strs[i].size();
        int len = min(strs[i].size() , strs[j].size());

        while( k < len )
        {
            if(strs[i][k] == strs[j][k])
            {
                ans = ans + strs[i][k];
            }
            else
            {
                return ans;
            }
            k++;
        
        }
        
        return ans;
    }
};