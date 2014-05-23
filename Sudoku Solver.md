Sudoku Solver
===
> Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution.
>
![](http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

> ![](http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)

> ...and its solution numbers marked in red..

根据数独游戏的规则，每一行的9个元素、每一列的9个元素、以及图中粗线划分出的每个九宫格内的元素均包含1-9，且不能重复。
采用DFS，从左上角开始向下遍历格子，遇到为空的格子（即标识为'.'）时便尝试向格子内填入一个数，这个数得保证满足数独的规则。此格子填完之后，继续递归到向下一行继续填写。如果某一列已经完全填好，就进入相邻的列继续从上往下地填写数字，最右边一列完成填写之后，递归结束。如果在填写某个格子时，无法找到满足规则的数字，那么便回溯到上一个格子并用另外一个有效的数字来填写这个格子，如果无法找到另外一个有效数字的话，就将这个格子恢复到原始的空状态（这一点非常重要），并再次回溯。
代码如下：
```
char nums[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        dfs(board, 0, 0);
    }
    
    bool isValid(char c, int row, int col, vector<vector<char> > &board) {
      int x = row/3*3, y = col/3*3;  
      for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;    
        if (board[i][col] == c) return false;
        if (board[x + i/3][y + i%3] == c) return false;
      }
      return true;
    }
    
    bool dfs(vector<vector<char> > &board, int row, int col) {
      // 一列填写完毕，换到相邻列处理
      if (row >= 9) return dfs(board, 0, col + 1);
      // 最后一列填写完毕
      if (col == 9) return true;
      if (board[row][col] == '.') {
        for (int i = 0; i < 9; i++) {
          if (isValid(nums[i], row, col, board)) {
            board[row][col] = nums[i];
            if (dfs(board, row + 1, col)) {
              return true;
            }
            board[row][col] = '.';
          }
        }
        return false;
      } else {
        return dfs(board, row + 1, col);
      }
    }
};
```

