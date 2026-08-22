class Solution {
public:
    bool checkDivisibility(int n) {
        int number = n ;
        int sum = 0;
        int product = 1;

        while(number>0)
        {
          int digit = number%10;
          sum = sum + digit;
          product = product * digit;
          number = number / 10;
        }
      
        cout << sum ; 
        cout << product;
        if( n % (product + sum) == 0)
        {
           return true;
        }

        return false;
    }
};