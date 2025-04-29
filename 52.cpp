/**
994. 腐烂的橘子
在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

示例 1：
输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：
输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
示例 3：
输入：grid = [[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 */

 #include<vector>
 #include<iostream>
 #include<queue>
 
 using namespace std;
 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0, fresh = 0;
        queue<pair<int,int>> qu;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) qu.push(pair<int,int>(i,j));
            }
        }
        vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        while(!qu.empty())
        {
            int n = qu.size();
            bool rotted = false;
            for(int i = 0; i < n; i++)
            {
                pair<int,int> cur = qu.front();
                qu.pop();
                int curx = cur.first;
                int cury = cur.second;
                for(auto d : dir)
                {
                    int x = curx + d.first;
                    int y = cury + d.second;
                    if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        qu.push({x,y});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if(rotted) min++;
        }
        return fresh == 0 ? min : -1;
    }
};
 
 int main()
 {
     Solution s;
     vector<vector<int>> grid = {{0,2}};
     cout << s.orangesRotting(grid) << endl;
     return 0;
 }