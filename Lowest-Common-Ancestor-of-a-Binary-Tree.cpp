class Solution {
public:
    // Helper to find the path from root to target node
    bool path(TreeNode* root, TreeNode* node, vector<TreeNode*>& ans) {
        if (!root) return false;

        ans.push_back(root);

        if (root == node) return true;

        if (path(root->left, node, ans) || path(root->right, node, ans))
            return true;

        ans.pop_back(); // backtrack
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        path(root, p, pathP);
        path(root, q, pathQ);

        TreeNode* lca = nullptr;
        int i = 0;

        while (i < pathP.size() && i < pathQ.size()) {
            if (pathP[i] == pathQ[i])
                lca = pathP[i];
            else
                break;
            i++;
        }

        return lca;
    }
};
