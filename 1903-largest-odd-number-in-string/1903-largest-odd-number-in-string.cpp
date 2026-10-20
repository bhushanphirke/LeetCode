class Solution {
public:
    string largestOddNumber(string num) {
         int n = num.size();
         string ans;
         int index = -1;

        
        for(int i =n-1 ; i >= 0;i--)
        {
            int cti =  num[i] - '0';

            if(cti % 2 == 0)
            { 
                 continue;
            }
            
            index = i;
            break;
        }
   
        for(int i = 0 ;  i <= index ; i++)
        { 
              ans += num[i];
        }


        if(index == -1)
        {
            return "";
        }

        return  ans;
    }
};