/**
239. 滑动窗口最大值
提示
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。
示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
 */

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class Solution {
private:
    class myqueue{
    public:
        deque<int> qu;

        myqueue(){}
        void pop(int val)
        {
            if(!qu.empty() && qu.front() == val)
            {
                qu.pop_front();
            }
        }

        void push(int val)
        {
            while(!qu.empty() && val > qu.back())
            {
                qu.pop_back();
            }
            qu.push_back(val);
        }

        int front()
        {
            return qu.front();
        }

    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //单调队列
        myqueue mqu;
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            mqu.push(nums[i]);
        }
        res.push_back(mqu.front());
        for(int i = k; i < nums.size(); i++)
        {
            mqu.pop(nums[i-k]);
            mqu.push(nums[i]);
            res.push_back(mqu.front());
        }
        return res;

    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums,k);
    for(auto& r : res)
    {
        cout << r << ' ';
    }
    return 0;
}