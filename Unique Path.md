
Unique Paths
=========
---
> A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

> The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

> How many possible unique paths are there?
> 
---
对于m×n的网格，可以用(0, 0),(0, 1)...(m-1, n-1)来表示其中的每一个格子。如果要计算从(0,0)到(m-1, n-1)的不重复路径，由于题目中规定机器人只能向下或向右移动，因此机器人在到达(m-1, n-1)之前，其位置一定是在(m-2, n-1)和(m-1, n-2)两者之一。不难算出，到达(m-1, n-1)的路径数便是到达(m-2, n-1)的路径数加上到达(m-1, n-2)的路径数。用p(m,n)表示机器人从m×n网格左上角移动到右下角可以经过的不同路径数，由此可以得递推公式:  

    p(m, n) = p(m-1,n) + p(m, n-1)  m, n >0

有了递推公式后，想要求解p(m,n)便比较容易了，可以使用递归，也可以使用DP。使用DP方法实现的源代码如下：

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int p[m][n];
        for (int i = 0; i < m; i++) p[i][0] = 1;
        for (int i = 0; i < n; i++) p[0][i] = 1;
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                p[i][j] = p[i][j-1] + p[i-1][j];
            }
        }
        return p[m-1][n-1];
    }
};
```