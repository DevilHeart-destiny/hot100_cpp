/**
46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：
输入：nums = [1]
输出：[[1]]
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracing(vector<int>& nums, vector<int>& used)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i] == 1) continue;
            used[i] = 1;
            path.push_back(nums[i]);
            backtracing(nums,used);
            path.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(),0);
        path.clear();
        res.clear();
        backtracing(nums,used);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,1};
    vector<vector<int>> res = s.permute(nums);
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