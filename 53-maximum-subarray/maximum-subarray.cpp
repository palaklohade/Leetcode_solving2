class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxlength = INT_MIN;
        int sum = 0;

        for(int right = 0 ; right < nums.size() ; right++){
            sum += nums[right];

            maxlength = max(maxlength , sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxlength;
    }
};