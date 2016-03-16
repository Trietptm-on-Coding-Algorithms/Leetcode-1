/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
       if (nullptr == root) {
           return 0;
       }
       
       int max1 = 0, max2 = 0;
       
       if (nullptr != root->left) {
           max1 += rob(root->left->right) + rob(root->left->left);
           max2 += rob(root->left);
       }
       
       if (nullptr != root->right) {
           max1 += rob(root->right->left) + rob(root->right->right);
           max2 += rob(root->right);
       }
       
       return max(max1 + root->val, max2);
    }
};