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
    TreeNode* inordertoBST(int s, int e, vector<int>& nums){
        //base case
        if(s>e){
            return NULL;
        }

        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = inordertoBST(s, mid-1, nums);
        root->right = inordertoBST(mid+1, e, nums);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return inordertoBST(0, n-1, nums);
    }
};