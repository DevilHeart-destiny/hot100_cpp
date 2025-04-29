/**
118. 杨辉三角
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:
输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
示例 2:
输入: numRows = 1
输出: [[1]]

提示:
1 <= numRows <= 30
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> grid(numRows);
        for(int i = 0; i < numRows; i++)
        {
            grid[i].resize(i+1,1);
            for(int j = 1; j < i; j++)
            {
                grid[i][j] = grid[i-1][j-1] + grid[i-1][j];
            }
        }
        return grid;
    }
};

int main()
{
    Solution s;
    int row = 3;
    vector<vector<int>> res = s.generate(row);
    for(auto nums : res)
    {
        for(auto n : nums)
        {
            cout << n << ' ';
        }
        cout << endl;
    }
    return 0;
}