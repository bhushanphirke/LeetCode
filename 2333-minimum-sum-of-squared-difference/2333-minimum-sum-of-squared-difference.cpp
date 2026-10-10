class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long k = (long long)k1 + k2;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int limit = low;
        long long used = 0;
        long long ans = 0;

        for (int d : diff) {
            int reduced = min(d, limit);
            used += d - reduced;
            ans += 1LL * reduced * reduced;
        }

        long long remaining = k - used;

        if (limit > 0) {
            for (int d : diff) {
                if (remaining == 0)
                    break;

                if (d >= limit) {
                    ans -= 1LL * limit * limit;
                    ans += 1LL * (limit - 1) * (limit - 1);
                    remaining--;
                }
            }
        }

        return ans;
    }
};
