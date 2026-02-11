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
    bool solve(TreeNode* leftnode, TreeNode* rightnode){
        // base case
        if(leftnode == NULL && rightnode == NULL)
            return true;
        if(!leftnode || !rightnode)
            return false;
        
        if (leftnode->val != rightnode->val) return false;
        
        return solve(leftnode->left, rightnode->right) &&
               solve(leftnode->right, rightnode->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return solve(root->left, root->right);
    }
};