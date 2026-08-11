class Solution {
public:
    string largestOddNumber(string num) {
        int idx=-1;
        string ans="";
        for(int i=num.size()-1 ; i>=0 ; i--){
            int number=int(num[i]);
            if(number%2!=0){
                idx=i;
                break;
            }
       }
       for(int j=0 ; j<=idx ; j++){
            ans+=num[j];
        }
        return ans; 
    }
};