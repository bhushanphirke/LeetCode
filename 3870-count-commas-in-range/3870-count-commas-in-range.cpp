class Solution {
public:
    int countCommas(int n) {
        if(n < 1000)
        {
          return 0;
        }

        int n1 = n - 1000;
        return n1 + 1;
    }
};