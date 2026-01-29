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

class info{
public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

class Solution {
public:
    info solve(TreeNode* root, int &ans){
        // base case
        if(!root)
            return{INT_MIN, INT_MAX, true, 0};
    
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
    
        info currNode;
        currNode.maxi = max(root->val, right.maxi);
        currNode.mini = min(root->val, left.mini);
    
        if(left.isBST && right.isBST && (root->val > left.maxi && root->val <right.mini)){
            currNode.isBST = true;
            currNode.sum = left.sum + right.sum + root->val;
            ans = max(ans, currNode.sum);
        }
        else{
            currNode.isBST = false;
            currNode.sum = 0;
        }
    
        return currNode;
    }
    int maxSumBST(TreeNode* root) {
        int maxSize = 0;
        info temp = solve(root, maxSize);
        return maxSize;
    }
};