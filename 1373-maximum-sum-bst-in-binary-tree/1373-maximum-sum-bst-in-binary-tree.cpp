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
    struct NodeValue {
        int minNode, maxNode, maxSum;

        NodeValue(int minNode, int maxNode, int maxSum) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSum = maxSum;
        }
    };

    int ans = 0;

    NodeValue solve(TreeNode* root) {
        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.maxNode < root->val && root->val < right.minNode) {
            int sum = left.maxSum + right.maxSum + root->val;
            ans = max(ans, sum);

            return NodeValue(min(root->val, left.minNode),
                             max(root->val, right.maxNode),
                             sum);
        }

        return NodeValue(INT_MIN, INT_MAX,
                         max(left.maxSum, right.maxSum));
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};