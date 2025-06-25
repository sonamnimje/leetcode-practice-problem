class Solution {
public:
    long long countPairs(vector<int>& A, vector<int>& B, long long x) {
        int n = A.size(), m = B.size();
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            int a = A[i];
            if (a == 0) {
                if (x >= 0) count += m;
            } else if (a > 0) {
                int l = 0, r = m - 1, pos = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if ((long long)a * B[mid] <= x) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                count += (pos + 1);
            } else { 
                int l = 0, r = m - 1, pos = m;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if ((long long)a * B[mid] <= x) {
                        pos = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                count += (m - pos);
            }
        }

        return count;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10, high = 1e10, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (countPairs(nums1, nums2, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
