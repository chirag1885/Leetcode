class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0 ; int r=0;
        long long count=0; long long total=0;
        unordered_map<char,int>mp;
        long long n=s.size();
        total=(n*(n+1))/2;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp.size()>2){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return total-count;
    }
};