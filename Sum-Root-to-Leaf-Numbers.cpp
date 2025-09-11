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
    void findSum(TreeNode* root, int &sum, int num) {
        if (!root) return;

        // Update number formed so far
        num = num * 10 + root->val;

        // If leaf node → add to sum
        if (!root->left && !root->right) {
            sum += num;
            return;
        }

        // Recurse on both children
        if (root->left) findSum(root->left, sum, num);
        if (root->right) findSum(root->right, sum, num);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        findSum(root, sum, 0);
        return sum;
    }
};
