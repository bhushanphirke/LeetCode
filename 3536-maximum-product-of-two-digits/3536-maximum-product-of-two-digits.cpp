class Solution {
public:
    int maxProduct(int n) {
        int first=-1;
        int second=-1;
        int digit;
        
        while(n>0)
        {
            digit=n%10;
            if(digit > first)
            {
              second=first;
              first=digit;
            }
            else if(digit > second && digit <=first)
            {
               second = digit;
            }
            n=n/10;

        }

        return first*second;
    }
};