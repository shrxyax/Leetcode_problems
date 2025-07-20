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
    TreeNode* build(vector<int>& inorder, int Sinorder, int Einorder,
                    vector<int>& postorder, int Spostorder, int Epostorder,
                    unordered_map<int,int>& mpp)
    {
        if (Sinorder > Einorder || Spostorder > Epostorder) return nullptr;

        TreeNode* root = new TreeNode(postorder[Epostorder]);
        int inroot = mpp[root->val];
        int leftsize = inroot - Sinorder;

        root->left = build(inorder, Sinorder, inroot - 1,
                           postorder, Spostorder, Spostorder + leftsize - 1, mpp);

        root->right = build(inorder, inroot + 1, Einorder,
                            postorder, Spostorder + leftsize, Epostorder - 1, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        TreeNode* root= build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1, mpp);

        return root;
    }
};
