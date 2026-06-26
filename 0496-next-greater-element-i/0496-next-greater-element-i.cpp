class Solution {
public:
stack<int> s1;

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int> ans(nums2.size(), 0);
       vector<int> ans2(nums1.size(), 0);

        int j=nums2.size()-1;
        for(int i=nums2.size()-1 ; i>=0 ; i--){
            while(!s1.empty() && s1.top()<nums2[i]){
                s1.pop();
            }
            if(s1.empty()){
                ans[j]=-1;
                j--;
            }
            else{
                ans[j]=s1.top();
                j--;
            }
             s1.push(nums2[i]);
        }
        int y=0;
         for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    ans2[i] = ans[j];
                    break;
                }
            }
        }

        return ans2;
    }
};