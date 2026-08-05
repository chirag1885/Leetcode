class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0 , r=0;
        int maxlen=0; int freq=0;
        vector<int> hash(26, 0);
        while(r<s.size()){
            hash[s[r]-'A']++;
            freq=max(freq , hash[s[r]-'A']);
            while((r-l+1) - freq>k){
                hash[s[l]-'A']--;
                l=l+1;
                freq=0;
                for(int i=0 ; i<26 ; i++){
                    freq=max(freq , hash[i]);
                }
            }
            maxlen=max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};