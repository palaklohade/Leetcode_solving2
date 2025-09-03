class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int case1 = dp[n - 2];

        vector<int> dp1(n, 0);
        dp1[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        int case2 = dp1[n - 1];

        return max(case1, case2);
    }
};