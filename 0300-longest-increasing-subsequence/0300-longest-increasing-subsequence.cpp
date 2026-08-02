class Solution {
public:

    int func(int i , int prev_i , vector<int> &nums , vector<vector<int>> &dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev_i+1] !=0) return dp[i][prev_i+1];
        int len=0+func(i+1 , prev_i , nums , dp);
        if(prev_i==-1 || nums[i]>nums[prev_i]){
            len=max(len , 1+func(i+1 , i , nums , dp));
        }
        return dp[i][prev_i+1]=len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));

        for(int i=n-1 ; i>=0 ; i--){
            for(int prev_i=i-1 ; prev_i>=-1 ; prev_i--){
                int len=0+dp[i+1][prev_i+1];
                if(prev_i==-1 || nums[i]>nums[prev_i]){
                    len=max(len , 1+dp[i+1][i+1]);
                }
            dp[i][prev_i+1]=len;
            }
        }

        return dp[0][0];
    }
};