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
    TreeNode* findlargestleft( TreeNode* root)
    {
        while(root->right)
        {
            root=root->right;
        }
        return root;
    }
    TreeNode* helper(TreeNode* root)
    {
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        TreeNode* rightChild= root->right;
        TreeNode* largestleft= findlargestleft(root->left);
        
        largestleft->right= rightChild;

        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return nullptr;
        if(root->val==key) return helper(root);

        TreeNode* dummy =root;
        while(root)
        {
            if(root->val > key)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left= helper(root->left);
                    break;
                }
                else root=root->left;
            }
            else
            {
                if(root->right!=NULL && root->right->val==key)
                {
                    root->right= helper(root->right);
                    break;
                }
                else root=root->right;
            }

        } 
        return dummy;  
    }
};