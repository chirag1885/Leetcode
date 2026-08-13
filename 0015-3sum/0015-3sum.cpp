
// -4,-1,-1,0,1,2
//          i           
//          j
//             k
// sum=-1<0

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0 ; 
        int target=0;
        int j=0 ; 
        int k=0;
        int n=nums.size();
        vector<vector<int>> ans;
        long long sum=0;
        sort(nums.begin() , nums.end());
        for(int i=0 ; i<n ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            j=i+1;
            k=n-1;
            while(j<k){
            sum=nums[i];
            sum+=nums[j];
            sum+=nums[k];
            if(sum==target){
                vector<int> temp={nums[i] , nums[j] , nums[k]};
                ans.push_back(temp);
                k--;
                j++;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
            else if(sum<target){
                j++;
            }
            else{
                k--;
            }

        }
        }
        return ans;
        }
    
};