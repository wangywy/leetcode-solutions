Unique Binary Search Trees II
===
> Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

> For example,
Given n = 3, there are a total of 5 unique BST's.
> 
    1         3     3      2      1
    \        /     /      / \      \
     3      2     1      1   3      2
     /     /       \                 \
    2     1         2                 3

此题是Unique Binary Search Trees I的拓展，I只要求求出BST的个数即可，此题则要求把所有的树都构建出来。
还是按照I中的思路，取[1, n]中的某一个数字i作为根结点，那么其左子树由[1, i-1]组成，右子树由[i+1,   n]组成。我们可以由此构建若干树，其根结点为i，左右子树分别是[1, i-1]和[i+1, n]所构成的BST的组合。

递归的解法如下：
```
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) { 
          vector<TreeNode*> tree;
          tree.push_back(NULL);
          return tree;
        }
        return makeTrees(1, n);
    }
    
    vector<TreeNode*> makeTrees(int start, int end) {
        vector<TreeNode*> tree;
        if (start > end) {
          tree.push_back(NULL);
          return tree;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> lefts = makeTrees(start, i - 1);
            vector<TreeNode*> rights = makeTrees(i + 1, end);
            for (int l = 0; l < lefts.size(); l++) {
                for (int r = 0; r < rights.size(); r++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lefts[l];
                    root->right = rights[r];
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};
```
另外，我们可以发现，在求解过程会遇到一些重复的子问题，于是我们可以把这些解保存下来，以后直接使用，不再重复计算。
以n=3为例，初始递归参数是(1, 3)：

- 以1作为根结点，那么其左子树为空，右子树为[2，3]构成的BST，这样的树有两个
- 以2作为根结点，左子树只能为1，右子树只能为3
- 以3作为根结点，左子树为[1, 2]构成的BST，右子树为3，而以[1, 2]构成的BST之前已经求过了，可以直接拿过来使用，节省了部分时间。

