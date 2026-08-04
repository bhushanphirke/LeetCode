class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      
      int i=0;
      int j=0;
      string ans;

      while(i<word1.length() && j<word2.length())
      {
         ans = ans + word1[i];
         i++;
         ans = ans + word2[j];
         j++;
      }

      while(j<word2.length())
      {
        ans = ans + word2[j];
        j++;
      }

       while(i<word1.length())
      {
        ans = ans + word1[i];
        i++;
      }

      return ans;
    }
};