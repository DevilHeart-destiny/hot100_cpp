/**
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：
输入：n = 1
输出：["()"]

提示：
1 <= n <= 8
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> res;
    string path;

    void backtracing(vector<char>& candidates, int left_num, int right_num, int n)
    {
        if(left_num == n && right_num == n)
        {
            res.push_back(path);
            return;
        }
        if(left_num < right_num || left_num > n || right_num > n) return;
        for(int i = 0; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            if(candidates[i] == '(')
            {
                backtracing(candidates,left_num+1,right_num,n);
            }
            else{
                backtracing(candidates,left_num,right_num+1,n);
            }
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<char> candidates = {'(',')'};
        res.clear();
        path.clear();
        backtracing(candidates,0,0,n);
        return res;
    }
};

int main()
{
    Solution s;
    int n = 3;
    vector<string> res = s.generateParenthesis(n);
    for(auto r : res)
    {
        cout << r << ' ';
    }
    return 0;
}