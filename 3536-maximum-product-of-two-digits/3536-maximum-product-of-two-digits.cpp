class Solution {
public:
    int maxProduct(int n) {
        int product=0;
        int digit;
        vector<int> arr;
        while(n>0)
        {
            digit=n%10;
            arr.push_back(digit);
            n=n/10;

        }

        sort(arr.begin(),arr.end());
        product=arr[arr.size()-1]*arr[arr.size()-2];

    
        return product;
    }
};