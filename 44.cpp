/**
230. 二叉搜索树中第 K 小的元素
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。

示例 1：
输入：root = [3,1,4,null,2], k = 1
输出：1
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
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }

private:
    int k,res;
    void dfs(TreeNode* node)
    {
        if(node == nullptr) return;
        dfs(node->left);
        if(k == 0) return;
        if(--k == 0) res = node->val;
        dfs(node->right);
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    int k = 1;
    cout << s.kthSmallest(root,k) << endl;
    return 0;
}