/**
31. 下一个排列
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。
必须 原地 修改，只允许使用额外常数空间。

示例 1：
输入：nums = [1,2,3]
输出：[1,3,2]
示例 2：
输入：nums = [3,2,1]
输出：[1,2,3]
示例 3：
输入：nums = [1,1,5]
输出：[1,5,1]
 
提示：
1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /**
        1、先找出最大的索引 k 满足 nums[k] < nums[k+1]，如果不存在，就翻转整个数组；
        2、再找出另一个最大索引 l 满足 nums[l] > nums[k]；
        3、交换 nums[l] 和 nums[k]；
        4、最后翻转 nums[k+1:]。
        */
       if(nums.size() < 2) return;
       int firstIndex = -1;
       for(int i = nums.size()-2; i >= 0; i--)
       {
        if(nums[i] < nums[i+1])
        {
            firstIndex = i;
            break;
        }
       }
       if(firstIndex == -1)
       {
        reverse(nums.begin(),nums.end());
        return;
       }
       int secondIndex = -1;
       for(int i = nums.size()-1; i >= 0; i--)
       {
        if(nums[i] > nums[firstIndex])
        {
            swap(nums[i],nums[firstIndex]);
            break;
        }
       }
       reverse(nums.begin()+firstIndex+1,nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    s.nextPermutation(nums);
    for(auto r : nums)
    {
        cout << r << ' ';
    }
    return 0;
}