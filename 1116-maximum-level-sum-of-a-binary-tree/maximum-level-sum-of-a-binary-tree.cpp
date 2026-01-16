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
    int maxLevelSum(TreeNode* root) {
        if(!root)   return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int maxLevel = 1;
        int maxSum = root->val;
        
        while(!q.empty()){
            int size = q.size();
            int sum = 0;

            for(int i=0; i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                sum = sum + frontNode->val;
                if(frontNode->left)
                    q.push(frontNode->left);
                if(frontNode->right)
                    q.push(frontNode->right);
            }
            
            if(sum > maxSum){
                maxSum = sum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};