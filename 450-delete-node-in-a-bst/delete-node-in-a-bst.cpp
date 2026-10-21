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
    TreeNode* findminnode(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == nullptr) {
            return root;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root ->val) {
            root->right = deleteNode(root->right , key);
        }
        else {
            //Node found
            //case 1 No Child

            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            //case 2 One Child

            else if (root->left == nullptr) {

                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else {
                TreeNode* minnode = findminnode(root->right);
                root->val = minnode->val;
                root->right = deleteNode(root->right, minnode->val);
            }


        }
        return root;




    }
};