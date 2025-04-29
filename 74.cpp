/**
215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1:
输入: [3,2,1,5,6,4], k = 2
输出: 5
示例 2:
输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4

提示：
1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void maxHeapify(vector<int>& nums, int cur, int heapsize)
    {
        int l = 2 * cur + 1;
        int r = 2 * cur + 2;
        int largest = cur;
        if(l < heapsize && nums[l] > nums[largest]) largest = l;
        if(r < heapsize && nums[r] > nums[largest]) largest = r;
        if(largest != cur)
        {
            swap(nums[cur],nums[largest]);
            maxHeapify(nums, largest, heapsize);
        } 
    }
    void buildmaxheap(vector<int>& nums, int heapsize)
    {
        for(int i = heapsize / 2 - 1; i >= 0; i--)
        {
            maxHeapify(nums,i,heapsize);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        buildmaxheap(nums,nums.size());
        for(int i = 0; i < k-1; i++)
        {
            swap(nums[0],nums[nums.size()-1-i]);
            maxHeapify(nums,0,nums.size()-1-i);
        }
        return nums[0];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << s.findKthLargest(nums,k) << endl;
    return 0;
}