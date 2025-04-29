/**
54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
 */


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
/**

打印方向	1. 根据边界打印	2. 边界向内收缩	3. 是否打印完毕
从左向右	左边界l ，右边界 r	上边界 t 加 1	是否 t > b
从上向下	上边界 t ，下边界b	右边界 r 减 1	是否 l > r
从右向左	右边界 r ，左边界l	下边界 b 减 1	是否 t > b
从下向上	下边界 b ，上边界t	左边界 l 加 1	是否 l > r
 */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> res;
        int l = 0;
        int r = matrix[0].size()-1;
        int t = 0;
        int b = matrix.size()-1;
        while(true)
        {
            // zuoshang->youshang
            for(int i = l; i <= r; i++)
            {
                res.push_back(matrix[t][i]);
            }
            if(++t > b) break;
            // youshang->youxia
            for(int i = t; i <= b; i++)
            {
                res.push_back(matrix[i][r]);
            }
            if(--r < l) break;
            // youxia->zuoxia
            for(int i = r; i >= l; i--)
            {
                res.push_back(matrix[b][i]);
            }
            if(--b < t) break;
            // zuoxia->zuoshang
            for(int i = b; i >= t; i--)
            {
                res.push_back(matrix[i][l]);
            }
            if(++l > r) break;
        }
        
        return res;
    }
}; 

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = s.spiralOrder(matrix);
    for(auto r : res)
    {
        cout << r << ' ';
    }
    return 0;
}