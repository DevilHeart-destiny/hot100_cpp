/**
236. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，
最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

示例 1：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //只要当前根节点是p和q中的任意一个，就返回（因为不能比这个更深了，再深p和q中的一个就没了）
        if(root == nullptr || root == p || root == q) return root;

        //根节点不是p和q中的任意一个，那么就继续分别往左子树和右子树找p和q
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        //p和q都没找到，那就没有
        if(left == nullptr && right == nullptr) return nullptr;
         //右子树没有p也没有q就返回左子树的结果
        if(left == nullptr && right != nullptr) return right;
         //左子树没有p也没有q，就返回右子树的结果
        if(right == nullptr && left != nullptr) return left;
        //左右子树都找到p和q了，那就说明p和q分别在左右两个子树上，所以此时的最近公共祖先就是root
        return root;
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
     cout << s.lowestCommonAncestor(root,root->left,root->right)->val << endl;
     return 0;
 }