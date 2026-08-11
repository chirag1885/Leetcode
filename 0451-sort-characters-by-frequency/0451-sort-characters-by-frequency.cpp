class Solution {
public:
    string frequencySort(string s) {
        map<char , int> mp;
        for(int i=0 ; i<s.size() ; i++){
            mp[s[i]]++;
        }
        vector<pair<char , int>> v(mp.begin() , mp.end());
        sort(v.begin() , v.end() , [](auto &a , auto&b){
            return a.second>b.second;
        });
        string ans="";
        for(int i=0 ; i<v.size() ; i++){
            char first= v[i].first;
            int second=v[i].second;

            while(second>0){
                ans+=first;
                second--;
            }
        }
        return ans;
    }
};



// hash- 26
// store value using for loop
// using for loop- traverse in hash map and find index and element of max count


// vector <char , int> char , count of it then sort that wrt count in decreasing order, 
//talke first =char
// take second =count
//ans.add char->count times. 