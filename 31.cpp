/**
25. K 个一组翻转链表
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode* a = head;
        ListNode* b = head;
        for(int i = 0; i < k; i++)
        {
            if(!b) return head;
            b = b->next;
        }
        ListNode* newhead = reverse(a,b);
        head->next = reverseKGroup(b,k);
        return newhead;
    }

    ListNode* reverse(ListNode* a, ListNode* b)
    {
        ListNode* pre = nullptr;
        ListNode* cur = a;
        ListNode* nxt = a;
        while(cur != b)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    int k = 2;
    ListNode* cur = s.reverseKGroup(head,k);
    while(cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    return 0;
}