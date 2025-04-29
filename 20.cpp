/**
48. 旋转图像
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       // 类似上一题的解法：四边界
    //    int n = matrix.size();
    //    int l = 0;
    //    int r = n-1;
    //    int t = 0;
    //    int b = n-1;
    //    while(l < r)
    //    {
    //         int i = 0;
    //         while(l+i < r)
    //         {
    //             int tmp = matrix[t][l+i];
    //             matrix[t][l+i] = matrix[b-i][l];
    //             matrix[b-i][l] = matrix[b][r-i];
    //             matrix[b][r-i] = matrix[t+i][r];
    //             matrix[t+i][r] = tmp;
    //             i++;
    //         }
    //         l++;
    //         r--;
    //         t++;
    //         b--;
    //    }

        // 两次翻转
        // shangxia
        int n = matrix.size();
        for(int i = 0; i < n/2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
        //duijiaoxian
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(matrix);
    for(auto m : matrix)
    {
        for(auto n : m)
        {
            cout << n << ' ';
        }
        cout << endl;
    }
    return 0;
}