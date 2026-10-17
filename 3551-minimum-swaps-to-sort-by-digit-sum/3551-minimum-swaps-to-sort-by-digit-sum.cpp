class Solution {
public:
    static int getDigitSum(int num) {
        int sum = 0;

        while (num > 0) {
            int digit = num % 10;
            sum += digit;
            num = num / 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);

        auto lambda = [](int num1, int num2) {
            int num1digit = getDigitSum(num1);
            int num2digit = getDigitSum(num2);

            if (num1digit != num2digit) {
                return num1digit < num2digit;
            }

            return num1 < num2;
        };

        sort(begin(sorted), end(sorted), lambda);

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int ex = sorted[i];
            int curr = nums[i];

            if (ex == curr) continue;

            int idx = mpp[ex];

            nums[i] = ex;
            nums[idx] = curr;

            mpp[curr] = idx;
            mpp[ex] = i;

            swaps++;
        }

        return swaps;
    }
};