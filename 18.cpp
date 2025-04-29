/**
73. 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

示例 1：
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
 */

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // kongjian O(M+N)
        // int row_cnt = matrix.size();
        // int colum_cnt = matrix[0].size();
        // unordered_set<int> row_index;
        // unordered_set<int> colum_index;
        // for(int i = 0; i < row_cnt; i++)
        // {
        //     for(int j = 0; j < colum_cnt; j++)
        //     {
        //         if(matrix[i][j] == 0)
        //         {
        //             row_index.insert(i);
        //             colum_index.insert(j);
        //         }
        //     }
        // }
        // for(int i = 0; i < row_cnt; i++)
        // {
        //     if(row_index.find(i) != row_index.end())
        //     {
        //         for(int j = 0; j < colum_cnt; j++)
        //         {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
        // for(int i = 0; i < colum_cnt; i++)
        // {
        //     if(colum_index.find(i) != colum_index.end())
        //     {
        //         for(int j = 0; j < row_cnt; j++)
        //         {
        //             matrix[j][i] = 0;
        //         }
        //     }
        // }

        // KONGJIAN O(CHANGSHU)
        int row_cnt = matrix.size();
        int colum_cnt = matrix[0].size();
        bool flag_row = false;
        bool flag_colum = false;
        for(int i = 0; i < row_cnt; i++)
        {
            if(matrix[i][0] == 0) flag_colum = true; 
        }
        for(int i = 0; i < colum_cnt; i++)
        {
            if(matrix[0][i] == 0) flag_row = true;
        }

        for(int i = 1; i < row_cnt; i++)
        {
            for(int j = 1; j < colum_cnt; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < row_cnt; i++)
        {
            for(int j = 1; j < colum_cnt; j++)
            {
                if(!(matrix[i][0] != 0 && matrix[0][j] != 0)) matrix[i][j] = 0;
            }
        }
        if(flag_row)
        {
            for(int i = 0; i < colum_cnt; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(flag_colum)
        {
            for(int i = 0; i < row_cnt; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(matrix);
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