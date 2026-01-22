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
    int findPosition(vector<int> inorder, int element, int size){
        for(int i=0; i<size; i++){
            if(element == inorder[i])
                return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int> inorder, vector<int> preorder, int n, int &index,
                int inOrderStart, int inOrderEnd){
        // base case
        if(index >= n || inOrderStart > inOrderEnd)
            return NULL;
        
        int element = preorder[index++];    
        TreeNode* root = new TreeNode(element);
        int pos = findPosition(inorder, element, n);
            
        root->left = solve(inorder, preorder, n, index, inOrderStart, pos-1);
        root->right = solve(inorder, preorder, n, index, pos+1, inOrderEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preOderIndex = 0;
        TreeNode *root = solve(inorder, preorder, n, preOderIndex, 0, n-1);
        return root;
    }
};