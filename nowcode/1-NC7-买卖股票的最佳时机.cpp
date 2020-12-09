class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        if(prices.empty())
            return 0;
        
        //把最后的问题看成前一天的问题+今天的解决方案
        int minVal = INT_MAX;
        int profit = 0;
        for(int &i: prices){
            minVal = min(minVal, i);//get min value
            profit = max(i - minVal, profit);//for this min value， find theprofit
        }
        return profit;
    }
};