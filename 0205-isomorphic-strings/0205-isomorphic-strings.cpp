class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if (s.length() != t.length()) {
            return false;
        }

        map<char, char> mp;
        map<char, bool> used;

        for (int i = 0; i < s.size(); i++) {

            char orig = s[i];
            char replacement = t[i];

            // orig is not mapped yet
            if (mp.find(orig) == mp.end()) {

                // replacement is already mapped to another character
                if (used[replacement]) {
                    return false;
                }

                mp[orig] = replacement;
                used[replacement] = true;
            }

            // orig is already mapped
            else {
                char temp = mp[orig];

                if (replacement != temp) {
                    return false;
                }
            }
        }

        return true;
    }
};