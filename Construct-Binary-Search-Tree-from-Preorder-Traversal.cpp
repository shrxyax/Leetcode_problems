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
    int i = 0; // Global index for preorder vector

    TreeNode* func(vector<int>& preorder, int mini, int maxi) {
        if (i >= preorder.size()) return nullptr;
        if (preorder[i] < mini || preorder[i] > maxi) return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = func(preorder, mini, root->val);
        root->right = func(preorder, root->val, maxi);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return func(preorder, INT_MIN, INT_MAX);
    }
};