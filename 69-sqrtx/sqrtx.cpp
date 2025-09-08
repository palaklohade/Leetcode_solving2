class Solution {
public:
    int solve(int& x) {
        int start = 1, end = x;

        int ans = -1;
        while(start <= end) {
            int mid = start + ((end - start) >> 1);

            if (mid == x / mid) return mid;
            else if (mid < x / mid) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }

    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        return solve(x);
    }
};