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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        // p，正在访问的节点，q，刚刚访问的节点
        TreeNode *p = root, *q = nullptr;
        
        do {
            while (p != nullptr) {
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            while (!s.empty()) {
                p = s.top();
                s.pop();
                // 右孩子不存在或已被访问，访问之
                if (p->right == q) {
                    result.push_back(p->val);
                    q = p; // 保存刚访问过的结点
                } else {
                    // 当前结点不能访问，需第二次进栈
                    s.push(p);
                    // 先处理右子树
                    p = p->right;
                    break;
                }
            }
        } while (!s.empty());
        return result;
    }
};
