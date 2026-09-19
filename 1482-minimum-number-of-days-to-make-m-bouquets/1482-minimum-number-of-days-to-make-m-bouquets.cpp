class Solution {
public:

    int calculate(vector<int> arr , int k, int m , int j)
    {
       int cnt = 0;
       int B = 0;
       for(int i=0;i<arr.size();i++)
       {
          if(arr[i] <= k)
          {
             cnt++;
          }
          else
          {
            B += (cnt / j);
            cnt = 0;
          }
       }

       B += (cnt / j);
       return B >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high = *max_element(bloomDay.begin() , bloomDay.end());

        if(((long long)m*(long long)k) > n) return -1;
        while(low <= high)
        {
          int mid = (low + high) / 2;
          
        

          if(calculate(bloomDay , mid , m , k))
          {
              high = mid -1;
          }
          else
          {
               low = mid + 1;
          }
          
           
        }


        return low;
    }
};