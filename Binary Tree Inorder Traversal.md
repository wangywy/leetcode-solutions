Binary Tree Inorder Traversal 
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
return `[1,3,2]`.
**Note:** Recursive solution is trivial, could you do it iteratively?

迭代法求二叉树中序遍历，中序遍历顺序是左子树、根结点、右子树。算法如下：
1.遍历指针指向根节点
2.如果指针不为空或者栈不为空，则指针开始向下一直沿结点的左孩子前进，每经过一个结点便将其压栈
3.栈顶元素出栈并输出此结点的值
4.若此结点是叶子结点，进入3
5.若此结点是非叶结点且其右孩子不为空，那么令遍历指针指向此结点的右孩子，进入2
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> order;
        if (root == NULL) return order;
        
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            order.push_back(p->val);
            p = p->right;
        }
        return order;
    }
};
```

