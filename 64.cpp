/**
74. 搜索二维矩阵
给你一个满足下述两条属性的 m x n 整数矩阵：
每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

示例 1：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int colum = matrix[0].size();
        int x = 0;
        int y = colum-1;
        while(x < row && y >= 0)
        {
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] < target)
            {   
                x++;
            }
            else
            {
                y--;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << s.searchMatrix(matrix,target) << endl;
    return 0;
}