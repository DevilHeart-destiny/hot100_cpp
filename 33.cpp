/**
148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
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
    ListNode* sortList(ListNode* head) {
        // digui guibing 
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(tmp);
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(left && right)
        {
            if(left->val < right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = left != nullptr? left : right;
        return res->next;
    }
};
 
 int main()
 {
     Solution s;
     ListNode* head = new ListNode(3);
     head->next = new ListNode(2);
     head->next->next = new ListNode(7);
     ListNode* cur = s.sortList(head);
     while(cur)
     {
         cout << cur->val << ' ';
         cur = cur->next;
     }
     return 0;
 }
