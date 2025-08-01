class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }

        for(int i = 0 ; i < freq.size() ; i++){
            if(freq[i] == 1){
                return i;
            }
        }
        return -1;
    }
};