class Solution {
public:
    int maxDepth(string s) {
        int left=0;
        int maxi=0; 
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='(') {
                left++;
            }
            else if(s[i]==')'){
                left--;
            }
            maxi=max(maxi , left);
        }  
        return maxi;
    }
};