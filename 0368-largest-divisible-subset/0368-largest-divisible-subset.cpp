class Solution {
public:

    void func(int i , int prev_i , vector<int> &nums , vector<vector<int>> &dp , vector<int> &ans , vector<int> &temp){
        if(i>=nums.size()){
            if(temp.size()>ans.size()){
                ans=temp;
            }
            return;
        }

        if( prev_i==-1 || nums[i]%nums[prev_i]==0 ){
            temp.push_back(nums[i]);
            func(i+1 , i , nums , dp , ans , temp);
            temp.pop_back();

        }

        func(i+1 , prev_i , nums , dp , ans , temp);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> dp(n,1);
        vector<int> prev_i(n , -1);
        int maxl=0;
        int last_index=0; // last index
        sort(nums.begin() , nums.end());

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev_i[i]=j;
                    }

                    if(dp[i]>maxl){
                        maxl=dp[i];
                        last_index=i;
                    }

                }
            }
        }
        while(last_index!=-1){
            ans.push_back(nums[last_index]);
            last_index=prev_i[last_index];
        }
        return ans;
    }
};