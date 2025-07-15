class Solution {
public:
    int func(TreeNode* root, int &maxi) {
        if (root == NULL) return 0;

        // Recursively get max gain from left and right
        int lmax = max(0,func(root->left, maxi));  // ignore negative paths
        int rmax = max(0,func(root->right, maxi));

        // Compute the max path through the current node
        int current = root->val + lmax + rmax;

        // Update the global max if needed
        maxi = max(maxi, current);

        // Return max path going *up* (only one side allowed)
        return root->val + max(lmax, rmax);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        func(root, maxi);
        return maxi;
    }
};
