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
    TreeNode* createParentMapping(TreeNode* root, int start,
                                  unordered_map<TreeNode*, TreeNode*> &nodeToParent) {
        TreeNode* res = nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->val == start) {
                res = front;
            }
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    int burnTree(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &nodeToParent) {
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(root);
        visited.insert(root);

        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                // left child
                if (front->left && !visited.count(front->left)) {
                    q.push(front->left);
                    visited.insert(front->left);
                    flag = true;
                }

                // right child
                if (front->right && !visited.count(front->right)) {
                    q.push(front->right);
                    visited.insert(front->right);
                    flag = true;
                }

                // parent
                if (nodeToParent.count(front) && !visited.count(nodeToParent[front])) {
                    q.push(nodeToParent[front]);
                    visited.insert(nodeToParent[front]);
                    flag = true;
                }
            }
            if (flag) ans++;
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode = createParentMapping(root, start, nodeToParent);
        return burnTree(targetNode, nodeToParent);
    }
};