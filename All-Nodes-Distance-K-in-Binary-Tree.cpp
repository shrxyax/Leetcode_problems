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
    void bfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*> mpp,vector<int> &ans,int k,unordered_map<TreeNode*,int> &visited)
    {
        if(!root) return;
        if(visited.find(root)!=visited.end()) return;
        visited[root]=1;
        if(k==0) ans.push_back(root->val);
        if(k<0) return;

        bfs(root->left,mpp,ans,k-1,visited);
        bfs(root->right,mpp,ans,k-1,visited);
        if(mpp.find(root)!=mpp.end())
        {
            bfs(mpp[root],mpp,ans,k-1,visited);
        }


    }
    void mapParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mpp)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* root=q.front();
            q.pop();
            if(root->left!=NULL)
            {
                q.push(root->left);
                mpp[root->left]=root;
            }
            if(root->right!=NULL)
            {
                q.push(root->right);
                mpp[root->right]=root;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,TreeNode*> mpp;
        mapParent(root,mpp);
        vector<int> ans;
        unordered_map<TreeNode*,int> visited;
        bfs(target,mpp,ans,k,visited);
        return ans;
    }
};