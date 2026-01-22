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
    void createMapping(vector<int> inorder, map<int, int> &nodeToIndex, int size){
        for(int i=0; i<size; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int> inorder, vector<int> postorder, int n, int &index,
                int inOrderStart, int inOrderEnd, map<int, int> &nodeToIndex){
        // base case
        if(index < 0  || inOrderStart > inOrderEnd)
            return NULL;
        
        int element = postorder[index--];    
        TreeNode* root = new TreeNode(element);
        int pos = nodeToIndex[element];

        root->right = solve(inorder, postorder, n, index, pos+1, inOrderEnd, nodeToIndex);    
        root->left = solve(inorder, postorder, n, index, inOrderStart, pos-1, nodeToIndex);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOderIndex = n-1;
        
        map<int, int> nodeToIndex;
        createMapping (inorder, nodeToIndex, n);

        TreeNode *root = solve(inorder, postorder, n, postOderIndex, 0, n-1, nodeToIndex);
        return root;
    }
};