class Solution {
public:
    bool rotateString(string s, string goal) {
        string concate = s + s;
        
        if(s.length() != goal.length())
        {
            return false;
        }
        
        
        if(concate.find(goal) != string::npos)
        {
            return true;
        }
        else
        {
            return  false;
        }
    }
};