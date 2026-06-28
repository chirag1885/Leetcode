/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>>ans;
        bool flagl2r=true;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp(size);
            for(int i=0 ; i<size ; i++){
                TreeNode *element=q.front();
                q.pop();

                int index=flagl2r?i:size-1-i;
                temp[index]=element->val;

                if(element->left){
                    q.push(element->left);
                }
                if(element->right){
                    q.push(element->right);
                }
            }
            flagl2r=!flagl2r;
            ans.push_back(temp);
        }
        return ans;
    }
};