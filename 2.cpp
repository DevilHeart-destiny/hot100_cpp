/**
49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。 

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:
输入: strs = [""]
输出: [[""]]
示例 3:
输入: strs = ["a"]
输出: [["a"]]
 
提示：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashmap;
        for(int i = 0; i < strs.size(); i++)
        {
            string sort_str = strs[i];
            sort(sort_str.begin(),sort_str.end());
            // if(hashmap.find(sort_str)!=hashmap.end())
            // {
                
            //     hashmap.find(sort_str)->second.push_back(strs[i]);
            // }
            // else{
            //     hashmap.insert(pair<string,vector<string>>(sort_str,{strs[i]}));
            // }
            hashmap[sort_str].emplace_back(strs[i]);
        }
        vector<vector<string>> res;
        res.reserve(hashmap.size());
        for(auto& [_,v] : hashmap)
        {
            res.push_back(v);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    for(auto& str : res)
    {
        for(auto& s : str)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}