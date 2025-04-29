/**
560. 和为 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
子数组是数组中元素的连续非空序列。

示例 1：
输入：nums = [1,1,1], k = 2
输出：2
示例 2：
输入：nums = [1,2,3], k = 3
输出：2
 */

#include<iostream>
#include<vector>
#include<unordered_map>
 
using namespace std;

class Solution {
public:
    // 前缀表＋哈希表
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int,int> hash;
        int count = 0;
        hash[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            prefix += nums[i];
            if(hash.find(prefix-k) != hash.end())
            {
                count += hash[prefix-k];
            }
            hash[prefix]++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,1,1};
    int target = 2;
    cout << s.subarraySum(nums,target) << endl;
    return 0;
}