/**
437. 路径总和 III
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

示例 1：
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
示例 2：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
 */
#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>

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
    unordered_map<long long, int> prefix;
    int dfs(TreeNode* root, int targetsum, long long curr)
    {
        if(!root) return 0;
        int ret = 0;
        curr += root->val;
        if(prefix.find(curr - targetsum) != prefix.end())
        {
            ret += prefix[curr - targetsum];
        }

        prefix[curr]++;
        ret += dfs(root->left,targetsum,curr);
        ret += dfs(root->right,targetsum,curr);
        prefix[curr]--;

        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root,targetSum,0);
    }

};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(2);
    int k = 4;
    cout << s.pathSum(root,k) << endl;
    return 0;
}