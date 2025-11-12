class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        double sum = 0;
        for(int i = 0; i < brackets.size(); i++) {
            
            if(sum + (brackets[i][0] - ((i == 0) ? 0 : brackets[i - 1][0])) >= income) {
                double t = income - sum;
                ans += ((double) t * brackets[i][1]) / 100 * 1.00;
                break;
            }
            if(i == 0) {
                ans += ((double) brackets[i][0] * brackets[i][1]) / 100 * 1.00;
                sum += brackets[i][0];
            }
            else {
                double t = brackets[i][0] -brackets[i - 1][0];
                ans += ((double) t * brackets[i][1]) / 100 * 1.00;
                sum += brackets[i][0] - brackets[i - 1][0];
            }
            cout << sum << endl;
            
            cout << ans << endl;
        }
        
        return ans;
    }
};