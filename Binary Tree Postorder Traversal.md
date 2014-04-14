Binary Tree Postorder Traversal 
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
return `[3,2,1]`.
**Note:** Recursive solution is trivial, could you do it iteratively?

迭代法求二叉树后序遍历，中序遍历顺序是左子树、右子树、根结点。算法如下：
1. 当前结点指向根节点
2. 若当前结点不为空，则若当前结点右孩子不为空，将右孩子结点压栈，将当前结点压栈，令当前结点指向其左孩子，进入2
3. 栈顶元素出栈，当前结点指向出栈结点
4. 若当前结点的右孩子与栈顶元素相同，则栈顶元素出栈，将当前结点压栈，之后令当前结点指向其右孩子；否则，输出当前结点值，令当前结点为空
5. 若栈不为空，进入2
```cpp
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> order;
        if (root == NULL) return order;
        
        stack<TreeNode*> st;
        TreeNode* p = root;
        do {
            while (p) {
                if (p->right) st.push(p->right);
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            if (p->right && p->right == st.top()) {
                st.pop();
                st.push(p);
                p = p->right;
            } else {
                order.push_back(p->val);
                p = NULL;
            }
        } while (!st.empty());
        return order;
    }
};
```
另外，本题还有一种更为简单的方法，但是需要用到两个栈，空间开销较大。如果我们将前序遍历顺序稍微修改一下，变成先根、右孩子、左孩子，可以看出一颗二叉树的变化后的前序遍历序列刚好是后序遍历序列的逆序，例如：

          1
         / \
        2   3
       /\   /\
      4  5 6  7
前序遍历序列为：`1, 3, 7, 6, 2, 5, 4`
后序遍历序列为：`4, 5, 2, 6, 7, 3, 1`
所以我们可以按照前序遍历的方法，对二叉树做一次变化后的前序遍历，一个栈用来保存遍历的中间状态，一个栈用来保存结果，然后将结果栈元素一个个地出栈便可以获得最终的后序遍历序列。
代码如下：
```cpp
void PostOrderTraverse(Node* root) {
  if (!root) return;
  stack<Node*> first;
  stack<Node*> second;
  first.push(root);
  Node* p;
  while (!first.empty()) {
    p = first.top();
    first.pop();
    second.push(p);
    if (p->lchild) first.push(p->lchild);
    if (p->rchild) first.push(p->rchild);
  }
  while (!second.empty()) {
    p = second.top();
    second.pop();
    Visit(p);
  }
}
```
    

