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
    void dfs(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>> &nodes) {
        if (!root) return;

        nodes[x][y].insert(root->val);

        dfs(root->left, x - 1, y + 1, nodes);   // left → x-1, y+1
        dfs(root->right, x + 1, y + 1, nodes);  // right → x+1, y+1
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        dfs(root, 0, 0, nodes);

        vector<vector<int>> ans;

        for (auto& [x, levelMap] : nodes) {
            vector<int> col;
            for (auto& [y, vals] : levelMap) {
                col.insert(col.end(), vals.begin(), vals.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
