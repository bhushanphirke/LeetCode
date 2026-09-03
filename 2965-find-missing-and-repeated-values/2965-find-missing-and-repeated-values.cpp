class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
       int n = grid.size();
       int total = n*n;

       vector<int> freq_arr(total+1,0);

       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
           freq_arr[grid[i][j]]++;
        }
       }

       int repeating = -1;
       int missing = -1;

       for(int i=1;i<=total;i++)
       {
          if(freq_arr[i] == 0)
          {
              missing = i;
          }
        
          if(freq_arr[i] == 2)
          {
              repeating = i;
          }

       }

       return {repeating,missing};
    }
};