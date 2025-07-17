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
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty())
        {
            int size= q.size();
            stack<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* root= q.front();
                level.push(q.front()->val);
                q.pop();
                if(root->left!=NULL) q.push(root->left);
                if(root->right!=NULL) q.push(root->right);
            }
            ans.push_back(level.top());
        }
        return ans;
    }
};