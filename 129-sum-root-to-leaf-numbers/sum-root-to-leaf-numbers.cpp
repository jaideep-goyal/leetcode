/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int path, int &sum) {
        if (node == nullptr) {
            return;
        }

        path = path * 10 + node->val;

        if (node->left == nullptr && node->right == nullptr) {
            sum += path;
            return;
        }

        dfs(node->left, path, sum);
        dfs(node->right, path, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};