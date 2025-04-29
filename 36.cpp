/**
94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：
输入：root = []
输出：[]
示例 3：
输入：root = [1]
输出：[1]
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        tranverse(root,res);
        return res;
    }
    void tranverse(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr) return;
        tranverse(root->left,res);
        res.push_back(root->val);
        tranverse(root->right,res);
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(9);
    vector<int> res = s.inorderTraversal(root);
    for(auto& n : res)
    {
        cout << n << ' ';
    }
    return 0;
}