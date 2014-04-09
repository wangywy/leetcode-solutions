Populating Next Right Pointers in Each Node
===
> Given a binary tree
>
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
    
> Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 
> Initially, all next pointers are set to NULL.

> **Note:**

> - You may only use constant extra space.
> - You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
> 
For example,
Given the following perfect binary tree,
> 
        1
       /  \
      2    3
     / \  / \
    4  5  6  7
>After calling your function, the tree should look like:
>
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

这道题其实就是要求按照二叉树的层级将每一层的结点链接起来组成一个链表。题目有两个限定条件，一是给定的二叉树都是完美的，即所有叶子结点都在同一层并且所有非叶结点都有两个孩子；二是题目要求只能使用常量的额外空间来计算。  
如果没有第二个限定条件，那么可以使用队列对整个树做一个层次遍历(level order traversal)，因为是完美二叉树，所以每一层的结点个数确定，这样只要根据每一层的结点个数做相同次数的出队操作便可以将这一层所有结点链接在一起。但是因为有了第二个限定条件，所以我们不能保存这么多的结点，得考虑其它的做法。
我们还是对树进行层次遍历，但是不再将结点的孩子放入队列中，而是直接在原来的树上进行操作。假设当前遍历到level层的结点p，把p结点左孩子的next指针指向它的右孩子，并把p之前的同一层的结点遍历后生成的链表的最后一个结点链接到p结点的左孩子上，本层遍历完毕后，便进入下一层开始遍历，直到所有树结点遍历完毕。
代码如下：
```
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        
        TreeLinkNode* head = root;
        while (head) {
            TreeLinkNode* cur = head;
            TreeLinkNode* last = NULL;
            while (cur) {
                if (cur->left) {
                    cur->left->next = cur->right;
                    if (last) last->next = cur->left;
                    last = cur->right;
                }
                cur = cur->next;
            }
            head = head->left;
        }
    }
};
```
