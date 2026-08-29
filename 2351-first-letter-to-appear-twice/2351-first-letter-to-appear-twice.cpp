class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> st;
        int ch ;
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s[i])!=st.end())
            {
                ch = i;
                break;
            }

            st.insert(s[i]);
        }

        return s[ch];

    }
};