class Solution {
public:
    bool issubstring(const string& repeated , const string& b){
         int n = repeated.size();
        int m = b.size();
        for(int i = 0 ; i + m <= n ; i++){
            int j =0;
            while(j < m && repeated[i+j] == b[j]){
                j++;
            }
            if(j == m)return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        int misrepeat = (m + n - 1 ) / n; 
        string repeated = "";
        for(int i = 0 ; i < misrepeat ; i++){
            repeated += a;
        }

        if(issubstring(repeated, b)){
            return misrepeat;
        }

        repeated += a;
        if(issubstring(repeated, b)){
            return misrepeat + 1;
        }
        return -1;
    }
};