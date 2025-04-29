/**
131. 分割回文串
给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

示例1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例2：
输入：s = "a"
输出：[["a"]]
 
提示：
1 <= s.length <= 16
s 仅由小写英文字母组成
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    bool ishuiwen(string& s, int start, int end)
    {
        for(int i = start, j = end; j > i; i++, j--)
        {
            if(s[i] != s[j]) return false;
        }
        return true;
    }

    void backtracing(string& s, int startIndex)
    {
        if(startIndex >= s.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); i++)
        {
            if(ishuiwen(s,startIndex,i))
            {
                // string str(s[startIndex],s[i]);
                string str = s.substr(startIndex,i-startIndex+1);
                path.push_back(str);
                backtracing(s,i+1);
                path.pop_back();
            }
            else{
                continue;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        backtracing(s,0);
        return res;
    }
};

int main()
{
    Solution s;
    string str = "aab";
    vector<vector<string>> res = s.partition(str);
    for(auto rs : res)
    {
        for(auto r : rs)
        {
            cout << r << ' ';
        }
        cout << endl;
    }
    return 0;
}