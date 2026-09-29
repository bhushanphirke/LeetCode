class Solution {
public:
    int sumof(vector<int> pages, int n)
{
	int sum = 0;

    for(int i=0;i<n;i++)
	{
       sum += pages[i];
	}

	return sum;
}


int students(vector<int> pages , int total)
{
    int stu = 1;
	int stupages = 0;
    int n = pages.size();
	for(int i = 0; i<n ; i++)
	{
	   if(stupages + pages[i] <= total)
	   {
         stupages += pages[i];
	   }
	   else
	   {
          stu++;
		  stupages = pages[i];
	   } 
	   
	}

	return stu;
}

int binary(vector<int> pages , int n , int b )
{
   int low = *max_element(pages.begin() , pages.end());
   int high = sumof(pages , n);
    
	while(low <= high)
	{
      int mid = low + (high - low) / 2;

	  int cnt = students(pages , mid);

	  if(cnt > b)
	  {
         low = mid +  1;

	  }
	  else
	  {
		  high = mid -1;

	  }
       
	
	}
    
	return low;

}


    
    int splitArray(vector<int>& nums, int k) {
         int n = nums.size();
         if(k > n)
         {
             return -1;
         }
         return binary(nums , n ,k);
    }
};