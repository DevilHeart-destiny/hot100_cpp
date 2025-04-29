/**
79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例 1：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(const vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, int curIndex, string word)
    {
        if(board[x][y] != word[curIndex]) return false;
        if(curIndex == word.size()-1) return true;
        for(auto d : dir)
        {
            int nextx = x + d.first;
            int nexty = y + d.second;
            if(nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size())
            {
                continue;
            }
            if(!visited[nextx][nexty])
            {
                visited[nextx][nexty] = true;
                if(dfs(board,visited,nextx,nexty,curIndex+1,word)) return true;
                visited[nextx][nexty] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        bool res;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    res = dfs(board,visited,i,j,0,word);
                    if(res) return res;
                    visited[i][j] = false;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board1 = {{'A','A'}};
    string word = "AAA";
    cout << s.exist(board1,word) << endl;;
    return 0;
}