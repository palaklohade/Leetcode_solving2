class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       set<int>st;
        int n = nums.size();
       for(int i=0 ; i < n ; i++){
        if(nums[i] !=0){
            st.insert(nums[i]);
        }
       }
       return st.size();
    }
};