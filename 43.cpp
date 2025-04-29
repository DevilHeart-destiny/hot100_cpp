/**
98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

示例 1：
输入：root = [2,1,3]
输出：true
示例 2：
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
 */
#include<iostream>
#include<vector>
#include<climits>

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
    bool isValidBST(TreeNode* root) {
        return tranverse(root,LONG_MIN,LONG_MAX);
    }
    bool tranverse(TreeNode* node, long long b, long long t)
    {
        if(node == nullptr) return true;
        if(node->val <= b || node->val >= t)
        {
            return false;
        }
        return tranverse(node->left,b,node->val) && tranverse(node->right,node->val,t);
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(9);
    cout << s.isValidBST(root) << endl;
    return 0;
}