class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();

        int i = 0;
        int j = 0;

       while(i < n || j < m){
        long long num = 0;
        long long num2 = 0;
         while(i < n && version1[i] != '.'){
             num = num * 10 + (version1[i] - '0');
             i++;
        }

        while(i < n && version1[i] == '.')i++;

         while(j < m && version2[j] != '.'){
             num2 = num2 * 10 + (version2[j] - '0');
             j++;
        }
        while(j < m && version2[j] == '.')j++;
        
        if(num > num2)return 1;
        if(num < num2)return -1;

        }
        return 0;
    }
};