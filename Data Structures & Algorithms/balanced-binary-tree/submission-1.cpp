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
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        
        int leftHeight = maxHeight(root->left);
        int rightHeight = maxHeight(root->right);
        int diff = abs(leftHeight - rightHeight);

        if(diff > 1){
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int maxHeight(TreeNode* root){
        if(!root){
            return 0;
        }

        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
};
