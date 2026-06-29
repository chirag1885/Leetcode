class Solution {
public:
int priority(char ch){
    switch( ch){
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
        default: return 0;
    }
}
    int romanToInt(string s) {
        int sum=0;
        for(int i=0 ; i<s.length() ; i++){
        if(i<s.length()-1 && priority(s[i])<priority(s[i+1])){
            sum=sum-priority(s[i]);
        }
        else{
            sum=sum+priority(s[i]);
        }
        }
        return sum;
    }
    
};