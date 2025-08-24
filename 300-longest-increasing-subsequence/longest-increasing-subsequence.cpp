class Solution {
public:
    int lis(vector<int>& nums, int indx, int prev, vector<vector<int>>& dp,
            int n) {
        if (indx == n)
            return 0;

        if (dp[indx][prev + 1] != -1) {
            return dp[indx][prev + 1];
        }

        int nottake = lis(nums, indx + 1, prev, dp, n);
        int take = 0;
        if (prev == -1 || nums[indx] > nums[prev]) {
            take = 1+lis(nums, indx + 1, indx, dp, n);
        }
        return dp[indx][prev+1] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n, -1));

        return lis(nums, 0, -1, dp, n);
    }
};