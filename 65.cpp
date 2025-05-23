/**
34. 在排序数组中查找元素的第一个和最后一个位置
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {left_bound(nums,target),right_bound(nums,target)};
    }
    int left_bound(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                right = mid - 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(left >= nums.size() || nums[left] != target) return -1;
        return left;
    }
    int right_bound(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(right < 0 || nums[right] != target) return -1;
        return right;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> res = s.searchRange(nums,target);
    for(auto r : res)
    {
        cout << r << ' ';
    }
    return 0;
}
