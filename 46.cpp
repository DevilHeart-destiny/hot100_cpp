/**
114. 二叉树展开为链表
提示
给你二叉树的根结点 root ，请你将它展开为一个单链表：
展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。

示例 1：
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
示例 2：
输入：root = []
输出：[]
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
        void flatten(TreeNode* root) {
            vector<TreeNode*> res;
            pre_tranverse(root,res);
            int len = res.size();
            for(int i = 1; i < len; i++)
            {
                TreeNode* pre = res[i-1];
                TreeNode* cur = res[i];
                pre->left = nullptr;
                pre->right = cur;
            }
        }
    private:
        void pre_tranverse(TreeNode* root, vector<TreeNode*>& res)
        {
            if(root == nullptr) return;
            res.emplace_back(root);
            pre_tranverse(root->left,res);
            pre_tranverse(root->right,res);
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
   TreeNode* root = new TreeNode(0);
   root->left = new TreeNode(2);
   root->right = new TreeNode(5);
   root->left->left = new TreeNode(9);
   s.flatten(root);
   vector<int> res;
   tranverse(root,res);
   for(auto& n : res)
   {
       cout << n << ' ';
   }
   return 0;
}