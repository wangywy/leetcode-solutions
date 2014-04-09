Populating Next Right Pointers in Each Node II
===
> Follow up for problem "Populating Next Right Pointers in Each Node".

> What if the given tree could be any binary tree? Would your previous solution still work?
> **Note:**
>
- You may only use constant extra space.

> For example,
Given the following perfect binary tree,
> 
        1
       /  \
      2    3
     / \    \
    4  5     7
>After calling your function, the tree should look like:
>
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4-> 5 -> 7 -> NULL

这道题中的树结构不再是I中所规定的完美二叉树，而是任意的二叉树。解决思路跟I相同，有两个地方需要注意：

- 不能直接将一个结点的左孩子直接链接到其右孩子，因为这两个孩子不一定会存在，所以需要对每一个孩子单独判断
- 当一层遍历结束，准备开始下一层开始遍历时，下一层开始的结点应该是该层第一个不为NULL的结点

代码如下：
```
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        
        TreeLinkNode* head = root;
        while (true) {
            TreeLinkNode* cur = head;
            TreeLinkNode* last = NULL;
            while (cur) {
                if (cur->left) {
                    if (last) last->next = cur->left;
                    last = cur->left;
                }
                if (cur->right) {
                    if (last) last->next = cur->right;
                    last = cur->right;
                }
                cur = cur->next;
            }
            if ((head = getNextHead(head)) == NULL) break;
        }
    }
    
    TreeLinkNode* getNextHead(TreeLinkNode* head) {
        if (head == NULL) return NULL;
        if (head->left) return head->left;
        if (head->right) return head->right;
        return getNextHead(head->next);
    }
};
```
