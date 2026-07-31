class Solution {
public:

    int ways(int index , int amount  ,  vector<int>& coins ,  vector<vector<int>> &dp)  {
        if(index==0){
            return (amount%coins[0]==0);
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int notpick=ways(index-1 , amount , coins , dp );
        int pick=0;
        if(amount>=coins[index]){
            pick=ways(index , amount-coins[index] , coins , dp);
        }
        return dp[index][amount]=notpick+pick;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        return ways(n-1 , amount , coins , dp);
    }
};