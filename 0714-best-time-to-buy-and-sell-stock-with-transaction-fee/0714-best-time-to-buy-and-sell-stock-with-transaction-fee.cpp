class Solution {
public:
    int func(int i , int buy , vector<int> &prices , vector<vector<int>> &dp , int fee){
        if(i==prices.size()){
            return 0;
        }
        long profit=0;
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy){
           int take=-fee-prices[i]+func(i+1 , 0 , prices , dp , fee);
           int nottake=0+func(i+1 , 1 , prices , dp , fee);
            profit=max(take , nottake);
        }
        else{
            int sell=prices[i]+func(i+1 , 1 , prices , dp , fee);
            int notsell=0+func(i+1 , 0 , prices , dp , fee);
            profit=max(sell , notsell);
        }
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size() , vector<int>(2,-1));
        return func(0 , 1 , prices , dp , fee);
    }
};