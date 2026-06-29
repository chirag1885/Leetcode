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
        vector<int>ans;
    vector<int> right(TreeNode *root , int level){

        if(root==NULL){
            return ans;
        }
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        right(root->right , level+1);
        right(root->left , level+1);
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        return right(root , 0);
    }
};