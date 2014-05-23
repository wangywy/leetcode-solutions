Valid Sudoku
===
> Determine if a Sudoku is valid, according to: [Sudoku Puzzles - The Rules](http://sudoku.com.au/TheRules.aspx).
> The Sudoku board could be partially filled, where empty cells are filled with the character `'.'`.
> 
![Alt text](https://lh5.googleusercontent.com/-_SMwS9BYm5Y/U38VvEpJhoI/AAAAAAAAAAg/T9AtnvdK0n4/s250/20140523.png)

> A partially filled sudoku which is valid.

> **Note:**
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

根据数独游戏的规则，每一行的9个元素、每一列的9个元素、以及图中粗线划分出的每个久宫格内的元素均包含1-9，且不能重复。
实现起来也比较简单，如果某个元素不为空，就判断该元素所在行、列、九宫格是否满足规则，只要发现有一个元素不满足规则，就直接返回。
代码如下：
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !isValid(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char> > &board, int row, int col) {
        int x = row/3*3, y = col/3*3;
        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == board[row][col]) return false;
            if (i != row && board[i][col] == board[row][col]) return false;
            int nx = x + i / 3, ny = y + i % 3;
            if (nx == row && ny == col) continue;
            if (board[nx][ny] == board[row][col]) return false;
        }
        return true;
    }
};
```

