/**
32. 最长有效括号
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

示例 1：
输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：
输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
示例 3
输入：s = ""
输出：0

提示：
0 <= s.length <= 3 * 104
s[i] 为 '(' 或 ')'
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0 || s.size() == 1) return 0;
        vector<int> dp(s.size(),0);
        int res = INT_MIN;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                {
                    dp[i] = 2;//需要先设置为2，防止样例是"()"的情况，这样不会进下面的判断分支
                    if(i >= 2)
                    {
                        dp[i] += dp[i-2];
                    }
                }
                else
                {
                    if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
                    {
                        dp[i] = dp[i-1] + 2;
                        if(i-dp[i-1]-2 >= 0)
                        {
                            dp[i] += dp[i-dp[i-1]-2];
                        }
                    }
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = ")()())";
    cout << s.longestValidParentheses(str) << endl;
    return 0;
}