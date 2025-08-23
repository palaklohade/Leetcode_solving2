class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro = nums[0];
        int minpro = nums[0];
        int curpro = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(minpro, maxpro);
            }
            maxpro = max(nums[i], maxpro * nums[i]);
            minpro = min(nums[i], minpro * nums[i]);

            curpro = max(curpro, maxpro);
        }
    
    return curpro;
}
}
;