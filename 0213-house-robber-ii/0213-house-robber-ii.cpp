class Solution {
public:
int max_money(int i , vector<int> &nums ,vector<int> &dp){
    if(i==0){
        return nums[i];
    }
    if(i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int pick=nums[i]+max_money(i-2 , nums , dp);
    int not_pick=0+max_money(i-1 , nums , dp);
    return dp[i]=max(pick , not_pick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1;
        vector<int>temp2;
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0] , nums[1]);
        }
        for(int i=0 ; i<n ; i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        vector<int>dp1(temp1.size() ,-1 );
        vector<int>dp2(temp2.size() ,-1 );
        int ans1= max_money(temp1.size()-1 , temp1 , dp1);
        int ans2= max_money(temp2.size()-1 , temp2 , dp2);
        return max(ans1 , ans2);
    }
};