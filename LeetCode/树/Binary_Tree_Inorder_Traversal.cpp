/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<const TreeNode*> stk;
        const TreeNode *p =  root;
        while (!s.empty() || p != nullptr) {
            if (p != nullptr) {
                stk.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* cur = root;
        
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode *p = cur->left;
                while (p->right != nullptr && p->right != cur)
                    p = p->right;
                if (p->right == nullptr) {
                    p->right = cur;
                    cur = cur->left;
                } else { // p->right == cur
                    p->right = nullptr;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
