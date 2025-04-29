/**
169. 多数元素
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1：
输入：nums = [3,2,3]
输出：3
示例 2：
输入：nums = [2,2,1,1,1,2,2]
输出：2
 
提示：
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //摩尔投票算法是基于这个事实：每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，就是出现次数大于总数一半的那个。
        int vote = 0;
        int candidate = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(vote == 0) candidate = nums[i];
            vote += nums[i] == candidate ? 1 : -1;
        }
        return candidate;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int num;
    while(cin >> num)
    {
        nums.emplace_back(num);
        if(cin.get() == '\n') break;
    }
    cout << s.majorityElement(nums) << endl;
    return 0;
}
