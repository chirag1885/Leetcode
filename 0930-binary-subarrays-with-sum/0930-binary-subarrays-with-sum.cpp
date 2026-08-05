class Solution {
public:

    long long func(vector<int>& nums, int goal){
        int l = 0, r = 0;
        int sum = 0;
        long long count = 0;

        while(r < nums.size()){
            sum += nums[r];

            while(l <= r && sum > goal){
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1);
            r++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal < 0) return 0;

        long long ans = func(nums, goal) - func(nums, goal - 1);
        return (int)ans;
    }
};