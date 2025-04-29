/**
234. 回文链表
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

示例 1：
输入：head = [1,2,2,1]
输出：true
示例 2：
输入：head = [1,2]
输出：false
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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast != nullptr)
        {
            slow = slow->next;
        }
        ListNode* left = head;
        ListNode* right = reverse(slow);
        while(right != nullptr)
        {
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
 
 int main()
 {
     Solution s;
     ListNode* head = new ListNode(1);
     head->next = new ListNode(2);
    //  head->next->next = new ListNode(3);
     cout << s.isPalindrome(head) << endl;
     return 0;
 }