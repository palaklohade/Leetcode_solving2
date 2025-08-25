class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;

        for(int price: prices){
            if(price < minprice){
                minprice = price;
            }else if(price - minprice > maxprofit){
               maxprofit = price - minprice;
            }
        }
        return maxprofit;
    }
};