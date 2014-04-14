Binary Tree Preorder Traversal
===
> Given a binary tree, return the preorder traversal of its nodes' values.
> For example,
Given binary tree `{1,#,2,3}`.
> 
    1         
    \        
     2  
     /
    3 
return `[1,2,3]`.
**Note:** Recursive solution is trivial, could you do it iteratively?

此题让求二叉树的前序遍历，递归一下很容易得出结果。题目中也说了递归比较trivial，最好用迭代的方式去做。其实前序遍历的迭代方式也是很简单的，利用一个栈来模拟递归，代码如下：
```
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> order;
        if (root == NULL) {
            return order;
        }
        stack<TreeNode*> st;
        TreeNode* p = root;
        st.push(p);
        while (!st.empty()) {
            p = st.top();
            st.pop();
            order.push_back(p->val);
            if (p->right) st.push(p->right);
            if (p->left) st.push(p->left);
        }
        return order;
    }
};
```

