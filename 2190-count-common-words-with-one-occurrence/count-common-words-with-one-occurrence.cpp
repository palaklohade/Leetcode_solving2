class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>cnt1,cnt2;
        for(auto u:words1) cnt1[u]++;
        for(auto u:words2) cnt2[u]++;
        int ans=0;
        for(auto u:words1){
            if(cnt1[u]==1&&cnt2[u]==1){
                ans++;
            }
        }
        return ans;
    }
};