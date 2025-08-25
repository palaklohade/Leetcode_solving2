class Solution {
public:
    bool canJump(vector<int>& nums) {
        int run = 0;

        for(int i = 0 ; i < nums.size();i++){
            if(i > run){
                return false;
            }
            run = max(run , nums[i] + i);
        }
        return true;
    }
};