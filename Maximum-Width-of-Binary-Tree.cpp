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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});  // Start from index 0 to avoid overflow early
        int maxwidth = 0;

        while (!q.empty())
        {
            int size = q.size();
            long long int minIndex = q.front().second;  // Normalize indices for this level
            vector<long long int> level;

            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                long long int line = it.second - minIndex;  // Normalize index to prevent overflow
                level.push_back(line);

                if (node->left != NULL) q.push({node->left, 2 * line + 1});
                if (node->right != NULL) q.push({node->right, 2 * line + 2});
            }

            long long int width = level.back() - level.front() + 1;
            maxwidth = max(maxwidth, (int)width);
        }

        return maxwidth;
    }
};
