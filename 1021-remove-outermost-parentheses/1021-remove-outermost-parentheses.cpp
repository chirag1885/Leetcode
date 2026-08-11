class Solution {
public:
    string removeOuterParentheses(string s) {
        int temp = 0;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (temp > 0) ans.push_back(s[i]);
                temp++;
            } else { // ')'
                temp--;
                if (temp > 0) ans.push_back(s[i]);
            }
        }

        return ans;
    }
};