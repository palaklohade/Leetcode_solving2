class Solution {
public:
    string toHex(int num) {
         if(num == 0) return "0"; 
        
        string hex = "0123456789abcdef";
        string result = "";
        unsigned int n = num; 
        
        while(n > 0){
            int digit = n % 16;
            result = hex[digit] + result;
            n /= 16;
        }
        
        return result;
    }
};