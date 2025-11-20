class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char ,int> freq1;
        for(char ch : magazine){
            freq1[ch]++;
        }
        for(char ch : ransomNote){
            if(freq1[ch] == 0) return false;
            freq1[ch]--;
        }
        return true;
    }
};