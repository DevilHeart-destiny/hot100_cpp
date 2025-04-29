/**
51. N 皇后
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例 1：
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：
输入：n = 1
输出：[["Q"]]
 
提示：
1 <= n <= 9
 */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;


// 超时了
// class Solution {
// public:
//     bool isok(vector<int> grid)
//     {
//         unordered_set<int> us;
//         for(auto num : grid)
//         {
//             if(us.find(num) != us.end()) return false;
//             us.insert(num);
//         }

//         for(long i = 0; i < grid.size()-1; i++)
//         {
//             for(long j = i+1; j < grid.size(); j++)
//             {
//                 if(abs(grid[j] - grid[i]) == j-i) return false;
//             }
//         }
//         return true;
//     }

//     vector<vector<int>> res;
//     vector<int> path;
//     void backtracing(int n, int cur)
//     {
//         if(!isok(path)) return;
//         if(cur == n)
//         {
//             res.push_back(path);
//             return;
//         }
//         for(int i = 0; i < n; i++)
//         {
//             path.push_back(i);
//             backtracing(n,cur+1);
//             path.pop_back();
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         res.clear();
//         path.clear();
//         backtracing(n,0);
//         // for(auto rs: res)
//         // {
//         //     for(auto r : rs)
//         //     {
//         //         cout << r << ' ';
//         //     }
//         //     cout << endl;
//         // }
//         vector<vector<string>> result;
//         vector<string> grid;
//         for(auto r : res)
//         {
//             for(auto num : r)
//             {
//                 string str = "";
//                 for(int i = 0; i < n; i++)
//                 {
//                     if(i == num) str += 'Q';
//                     else str += '.';
//                 }
//                 grid.push_back(str);
//                 str.clear();
//             }
//             result.push_back(grid);
//             grid.clear();
//         }
//         return result;
//     }
// };
class Solution {
public:
    bool isok(const vector<string> board, int x, int y, int n)
    {
        for(int i = 0; i < x; i++)
        {
            if(board[i][y] == 'Q')
            {
                return false;
            }
        }
        for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }
        for(int i = x-1, j = y+1; i >= 0 && j < n; i--, j++)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> res;
    void backtracing(vector<string>& board, int n, int cur)
    {
        if(cur == n)
        {
            res.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(isok(board,cur,i,n))
            {
                board[cur][i] = 'Q';
                backtracing(board,n,cur+1);
                board[cur][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> board(n,string(n,'.'));
        backtracing(board,n,0);
        return res;
    }
};
int main()
{
    Solution s;
    int n = 4;
    vector<vector<string>> res = s.solveNQueens(n);
    cout << res.size() << endl;
    for(auto rs : res)
    {
        for(auto r : rs)
        {
            cout << r << ' ';
        }
        cout << endl;
    }
    return 0;
}