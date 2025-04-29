/**
101. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
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
    bool compare(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr) return true;
        else if(left != nullptr && right != nullptr)
        {
            if(left->val != right->val) return false; 
            return compare(left->left,right->right) && compare(left->right,right->left);
        }
        else return false;
    }
    bool isSymmetric(TreeNode* root)
    {
        if(root == nullptr) return false;
        return compare(root->left,root->right);
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(9);
    cout << s.isSymmetric(root) << endl;
    return 0;
}