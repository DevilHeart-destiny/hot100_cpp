/**
108. 将有序数组转换为二叉搜索树
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。

示例 1：
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
示例 2：
输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 */
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return tranverse(nums,0,nums.size()-1);
    }

    TreeNode* tranverse(vector<int>& nums, int left, int right)
    {
        if(left > right)
        {
            return nullptr;
        }

        int mid = (right - left)/2 + left;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = tranverse(nums,left,mid-1);
        node->right = tranverse(nums,mid+1,right);
        return node;
    }
};

void tranverse(TreeNode* root, vector<int>& res)
{
   if(root == nullptr) return;
   tranverse(root->left,res);
   res.push_back(root->val);
   tranverse(root->right,res);
}
int main()
{
   Solution s;
   vector<int> nums = {1,2,3,3,3,6,7};
   TreeNode* r = s.sortedArrayToBST(nums);
   vector<int> res;
   tranverse(r,res);
   for(auto& n : res)
   {
       cout << n << ' ';
   }
   return 0;
}