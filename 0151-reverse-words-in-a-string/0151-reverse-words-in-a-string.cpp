class Solution {
public:
    string reverseWords(string s) {
         string word;
         stringstream ss(s);
         vector<string> str;

         string ans;

   
         while(ss >> word)
         {
            str.push_back(word);
         }

         for(int i = str.size() - 1 ; i >= 0 ; i-- )
         {
              if(!ans.empty()) ans += " ";
              ans += str[i];
         } 

         return ans;
    }
};