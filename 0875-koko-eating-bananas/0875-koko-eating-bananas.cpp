class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low <= high)
        {
           int mid = (low + high) / 2;
            
           long long total = calculate(piles , mid);

        if(total <= h)
        {
            high = mid -1;
        }
        else
        {
            low = mid +1;
        }


        }

        return low;
    }

    long long calculate(vector<int> &piles , int k)
    {
        long long totalH =0;
        
        for(int i = 0 ;i<piles.size();i++)
        {
            totalH += ceil((double) piles[i] / (double) k);
        } 

        return totalH;
    }
};