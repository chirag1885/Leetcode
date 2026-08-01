class Solution {
public:

    int func(int i , int buy , int cap ,  vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(cap==0) return 0;
        long profit=0;
        if(dp[i][buy][cap]!=-1){
            return dp[i][buy][cap];
        }

        if(buy){
            int take=-prices[i]+func(i+1 , 0 , cap , prices , dp);
            int nottake=0+func(i+1 , 1 , cap , prices , dp);
            profit=max(take , nottake);
        }
        else{
            int sell=prices[i]+func(i+1 , 1 , cap-1, prices , dp);
            int notsell=0+func(i+1 , 0 , cap, prices , dp);
            profit=max(sell , notsell);
        }
        return dp[i][buy][cap]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2,vector<int>(k+1,-1)));
        return func(0 , 1 , k , prices , dp);
        
    }
};