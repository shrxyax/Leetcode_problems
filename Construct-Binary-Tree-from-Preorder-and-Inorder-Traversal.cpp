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
    TreeNode* buildtree(vector<int>& preorder,int startpre,int endpre,vector<int>& inorder,int startin, int endin,unordered_map<int,int> &mpp )
    {
        if(startpre>endpre || startin> endin) return nullptr;
        TreeNode* root=new TreeNode(preorder[startpre]);
        int inroot= mpp[root->val];
        int leftele= inroot - startin;

        root->left= buildtree(preorder,startpre+1,startpre+leftele,inorder,startin,inroot-1,mpp);
        root->right= buildtree(preorder,startpre+leftele+1,endpre,inorder,inroot+1,endin,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        TreeNode* root= buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};