/**
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
      if(x >= grid.size() || x < 0 || y < 0 || y >= grid[0].size() || grid[x][y] == '0') return;
      grid[x][y] = '0';
      dfs(grid,x-1,y);
      dfs(grid,x,y-1);
      dfs(grid,x+1,y);
      dfs(grid,x,y+1);
    }

    int numIslands(vector<vector<char>>& grid) {
      int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
          for(int j = 0; j < grid[0].size(); j++)
          {
            if(grid[i][j] == '1')
            {
              dfs(grid,i,j);
              count++;
            }
          }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout << s.numIslands(grid) << endl;
    return 0;
}