class Solution {
public:

long long  minsum(int i , int j , vector<vector<int>>& grid , vector<vector<int>> &dp){
    if(i==0 && j==0){
        return grid[0][0];
    }
    if(i<0 || j<0){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    long long  up=grid[i][j]+minsum(i-1 , j , grid , dp);
    long long  left=grid[i][j]+minsum(i , j-1 , grid , dp);
    return dp[i][j]=min(up , left);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= (m>0)? grid[0].size():0;
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return minsum(m-1 , n-1  , grid , dp);
    }
};