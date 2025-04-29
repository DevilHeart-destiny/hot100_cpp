/**
19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：
输入：head = [1], n = 1
输出：[]
示例 3：
输入：head = [1,2], n = 1
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* dum = new ListNode(-1);
        dum->next = head;
        ListNode* prev = dum;
        ListNode* fast = head;
        ListNode* slow = head;
        while(n--)
        {
            fast = fast->next;
        }
        while(fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            prev = prev->next;
        }
        prev->next = slow->next;
        delete slow;
        return dum->next;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    int k = 2;
    ListNode* cur = s.removeNthFromEnd(head,k);
    while(cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    return 0;
}