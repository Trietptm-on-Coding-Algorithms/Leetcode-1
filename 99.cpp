class Solution {
 public:
  void recoverTree(TreeNode* root) {
    help(root, nodes);

    TreeNode* first, *second;
    for (int i = 0; i < nodes.size(); ++i) {
      if (i == 0 && ) {
        
      }
    }
    
  }

 private:
  vector<TreeNode*> nodes;
  void help(TreeNode* cur, vector<TreeNode*>& nodes) {
    if (cur == NULL) {
      return ;
    }

    help(cur->left, nodes);
    nodes.push_back(nodes);
    help(cur->right, nodes);

    return ;
  }
};
