/**
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的 回文 子串。

示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：
输入：s = "cbbd"
输出："bb"

提示：
1 <= s.length <= 1000
s 仅由数字和英文字母组成
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;
        int max_len = 0;
        int begin = 0;
        vector<vector<int>> dp(n,vector<int>(n));
        for(int len = 2; len <= n; len++)
        {
            for(int i = 0; i < n; i++)
            {
                int j = len + i - 1;
                if(j >= n)
                {
                    break;
                }
                if(s[i] == s[j])
                {
                    if(j-i < 3)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
                if(dp[i][j] && j-i+1 > max_len)
                {
                    max_len = j-i+1;
                    begin = i;
                }
            }
        }
        return s.substr(begin,max_len);
    }
};

int main()
{
    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}