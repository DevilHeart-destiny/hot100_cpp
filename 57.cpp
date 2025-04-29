/** 
17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：
输入：digits = ""
输出：[]
示例 3：
输入：digits = "2"
输出：["a","b","c"]
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> res;
    string path;
    unordered_map<char,vector<char>> um = {{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};

    void backtracing(string digits, int startIndex)
    {
        if(path.size() == digits.size())
        {
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i < digits.size(); i++)
        {
            for(auto zimu : um[digits[i]])
            {
                path.push_back(zimu);
                backtracing(digits,i+1);
                path.pop_back();
            }
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        res.clear();
        path.clear();
        backtracing(digits,0);
        return res;
    }
};

int main()
{
    Solution s;
    string str = "22";
    vector<string> res = s.letterCombinations(str);
    for(auto s : res)
    {
        cout << s << ' ';
    }
    return 0;
}