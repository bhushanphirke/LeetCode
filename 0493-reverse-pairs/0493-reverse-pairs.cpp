class Solution {
public:

    vector<int> temp;

    void merge(vector<int>& nums, int low, int mid, int high) {

        int i = low;
        int j = mid + 1;
        int k = low;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }

        while (i <= mid)
            temp[k++] = nums[i++];

        while (j <= high)
            temp[k++] = nums[j++];

        for (int i = low; i <= high; i++)
            nums[i] = temp[i];
    }

    long long countPairs(vector<int>& nums, int low, int mid, int high) {

        long long cnt = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {

            while (j <= high && 
                   (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            cnt += j - (mid + 1);
        }

        return cnt;
    }

    long long mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        long long cnt = 0;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);

        cnt += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {

        int n = nums.size();

        temp.resize(n);

        return (int)mergeSort(nums, 0, n - 1);
    }
};