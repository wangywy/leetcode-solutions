Triangle
===========
---

> Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

> For example, given the following triangle
>```
    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]
>```
> The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

> Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.  



题目要求从三角顶端到底部的最短路径，一个显而易见的做法是从顶部开始向下遍历每一条可能路径，找出所有路径中最短的那条,
但是显然这样做的时间复杂度是O(2<sup>n</sup>)（每次向下找寻路径时都有两种选择)。
从顶部到底部的最短路径与从底部到顶部的最短路径相同，从三角形的形状特征可以想到，如果我们知道从底部到顶部下面一层（即到达3、4）的路径数，
那么到达顶部的最短路径便是到达[3,4]最短路径再加上2。若想求底部到达[3,4]的最短路径，可以求通过从底部分别到达3和4的路径数，然后取其中较小的一条。
这样，原问题便分解成了两个与原问题相同的子问题（只是规模变小了），即

```        
        [3],
       [6,5],
      [4,1,8]
```
和

```
        [4],
       [5,7],
      [1,8,3]
```
由此可以想到使用递归的方法。但是可以发现，在求解这两个子问题过程中，某些过程被重复计算了，如从底层1->5,底层8->5，
满足应用动态规划的两个条件--最优子结构和重叠子问题。于是可以从底层开始向上遍历每一层，计算到达每一层的最短路径，一直计算到顶层便得到了最后的解。
至于题目中要求的最好能使用O(n)的额外空间，只需要开辟一个长度为n的数组，在遍历到某一层时，数组中保存的是到达其下一层的最短路径距离。

代码如下：

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        vector<int> path = triangle[row-1];
        
        for (int i = row - 2; i>= 0; i--) {
            int col = triangle[i].size();
            for (int j = 0; j < col; j++) {
                path[j] = min(path[j], path[j + 1]) + triangle[i][j];
            }
        }
        return path[0];
    }
};
```