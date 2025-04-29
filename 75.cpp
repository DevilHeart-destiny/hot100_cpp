/**
347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:
输入: nums = [1], k = 1
输出: [1]

提示：
1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 */
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    class mycmp{
    public:
        bool operator()(const pair<int,int>& l, const pair<int,int>& r)
        {
            return l.second > r.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(auto n : nums)
        {
            um[n]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> pq;

        for(const auto& p : um)
        {
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }
        vector<int> res(k);
        for(int i = k-1; i >= 0; i--)
        {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = s.topKFrequent(nums,k);
    for(auto n : res)
    {
        cout << n << ' ';
    }
    return 0;
}