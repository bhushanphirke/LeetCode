class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};
        for(int i=0;i<digits.size();i++)
        {
           freq[digits[i]]++;
        }

        int count =0;
        for(int  i=100;i<=999;i++)
        {
           if(i % 2 != 0)
           {
              continue;
           }

           int n = i;
           int a = n % 10;
           n /= 10;
           int b = n % 10;
           n /= 10;
           int c = n % 10;
           n /= 10;

           int need[10] = {};
           need[a]++;
           need[b]++;
           need[c]++;

           bool possible = true;
           for(int i=0;i<=9;i++)
           {
              if(need[i] > freq[i])
              {
                 possible = false;
                 break;
              }
 
           }

           if(possible == true)
           {
              count ++;
           }


        }

        return count;
    }
};