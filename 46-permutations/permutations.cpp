class Solution {
public:

    void backtrack(int start , int n , vector<int>&nums , vector<vector<int>>&result){
        if(start == n){
            result.push_back(nums);
            return;
        }
        for(int i =start ; i < n ; i++){
           swap(nums[start] , nums[i]);
           backtrack(start + 1 , n , nums,result);
           swap(nums[start] , nums[i]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        backtrack(0,n,nums, result);
        return result;
    }
};