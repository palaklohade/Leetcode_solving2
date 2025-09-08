class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isCap = false;
        for(int i = 0; i < word.size(); i++){
            if(isupper(word[i])){
                if(isCap == false && i != 0){
                    return false;
                }
                isCap = true;
            }else{
                if(isCap && i != 1) return false;
                isCap = false;
            }
        }
        return true;
    }
};