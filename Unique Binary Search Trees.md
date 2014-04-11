Unique Binary Search Trees
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

给定一个数字n，求出由1, 2 ... n所能构成的二叉搜索树的个数。
一棵二叉搜索树是由根结点以及左右两个子树构成的，取[1, n]中的某一个数字i作为根结点，那么其左子树由[1, i-1]组成，右子树由[i+1,   n]组成。分别求出左右两个子树的个数为l和r，由i作为根结点所能组成的BST个数便是l*r，将所有i = 1, 2, ... n为根结点所构成的BST个数相加，便是所要求的结果。  
从上述分析可以看出，求以i为根结点所组成的BST个数时，需要求出[1, i-1]组成的子树个数和[i+1, n]所构成的子树个数。求[1, i-1]所构成的BST个数显然是当前问题的子问题，而由[i+1, n]所构成的BST个数该如何求解呢？因为这里我们只关心BST的个数，并不在意其具体的树结构，所以[i+1, n]所构成的BST个数其实与[1, n-i]所构成的BST个数相同，由此这两个问题都变成了当前问题的子问题，我们可以使用DP来求解。
设num[n]表示由n个数字构成的BST个数，则`num[n] = sum{ num[i-1] + num[n-i]} , i = 1, 2, ... n`，初始状态num[0] = 1（空树）， num[1] = 1（只有一个结点的树）。

代码如下：
```
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        int num[n+1];
        
        num[0] = 1;
        num[1] = 1;
        for (int i = 2; i <= n; i++) {
            num[i] = 0;
            for (int j = 0; j < i; j++)
                num[i] += num[j] * num[i-j-1];
        }
        return num[n];
    }
};
```
