class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long  totalhours=0;
        int low=1;
        int high=*max_element(piles.begin(), piles.end());;
        int mid=0;
        int ans=0;
        while(low<=high){
            totalhours=0;
            mid=low+(high-low)/2;
            for(int i=0 ; i<piles.size() ; i++){
                totalhours+=(piles[i]+mid-1)/mid;
            }
            if(totalhours<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};