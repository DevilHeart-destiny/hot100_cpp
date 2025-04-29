/**
279. 完全平方数
给你一个整数 n ，返回和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4
示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9
 
提示：
1 <= n <= 104
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i-j*j]+1,dp[i]);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    int n = 13;
    cout << s.numSquares(n) << endl;
    return 0;
}