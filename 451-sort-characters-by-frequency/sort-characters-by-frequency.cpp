class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<int,int> freq;

        for(char c : s) freq[c]++;
        vector<pair<char,int>> arr(freq.begin() , freq.end());
        sort(arr.begin(),arr.end() , [](auto &a , auto &b){
            return a.second > b.second;
        });

        string ans="";
        for(auto &c : arr){
            ans.append(c.second,c.first);
        }
        return ans;
    }
};