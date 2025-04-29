/**
24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：
输入：head = []
输出：[]
示例 3：
输入：head = [1]
输出：[1]
 */

 #include<iostream>

 using namespace std;
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if(head == nullptr || head->next == nullptr) return head;
            ListNode* dum = new ListNode(-1);
            dum->next = head;
            ListNode* cur = dum;
            while(cur->next!=nullptr && cur->next->next!=nullptr)
            {
                ListNode* tmp = cur->next;
                ListNode* tmp1 = cur->next->next->next;
                cur->next = tmp->next;
                cur->next->next = tmp;
                cur->next->next->next = tmp1;
                cur = cur->next->next;
            }
            return dum->next;
        }
    };
 
 int main()
 {
     Solution s;
     ListNode* head = new ListNode(1);
     head->next = new ListNode(2);
     head->next->next = new ListNode(3);
     head->next->next->next = new ListNode(4);
     ListNode* cur = s.swapPairs(head);
     while(cur)
     {
         cout << cur->val << ' ';
         cur = cur->next;
     }
     return 0;
 }