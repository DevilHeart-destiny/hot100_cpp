/**
76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：
对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。

示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 */


#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //sliding window
        if(s.size() < t.size()) return "";
        string res;
        unordered_map<char,int> window,need;
        for(char& c : t)
        {
            need[c]++;
        }

        int left = 0;
        int right = 0;
        int valid = 0;
        int start = 0;
        int len = INT_MAX;
        while(right < s.size())
        {
            char cur = s[right];
            right++;
            if(need.find(cur) != need.end())
            {
                window[cur]++;
                if(window[cur] == need[cur])
                {
                    valid++;
                }
            }

            while(valid == need.size())
            {
                if(right-left < len)
                {
                    start = left;
                    len = right - left;
                }
                char l = s[left];
                left++;
                if(need.find(l) != need.end())
                {
                    if(window[l] == need[l])
                    {
                        valid--;
                    }
                    window[l]--;
                }    
            }    
        }
        return len == INT_MAX? "" : s.substr(start,len);
    }
};

int main()
{
    Solution s;
    string str = "A";
    string t = "A";
    cout << s.minWindow(str,t) << endl;
    return 0;
}