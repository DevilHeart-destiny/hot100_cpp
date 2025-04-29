/**
2. 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* count = l1;
        int count_1 = 0;
        int count_2 = 0;
        while(count!=nullptr)
        {
            count_1++;
            count = count->next;
        }
        count = l2;
        while(count!=nullptr)
        {
            count_2++;
            count = count->next;
        }
        if(count_1 < count_2) swap(l1,l2);

        ListNode* res = l1;
        while(l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + flag;
            flag = 0;
            if(sum > 9)
            {
                flag = 1;
                sum = sum % 10;
            }
            l1->val = sum;
            if(l1->next == nullptr && flag) l1->next = new ListNode(0);
            l1 = l1->next;
            l2 = l2->next;
        }
 
        if(flag)
        {
            while(l1)
            {
                int sum = l1->val + flag;
                flag = 0;
                if(sum > 9)
                {
                    flag = 1;
                    sum = sum % 10;
                }
                l1->val = sum;
                if(l1->next == nullptr && flag) l1->next = new ListNode(0);
                l1 = l1->next;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
   //  head->next->next = new ListNode(3);
    ListNode* head1 = new ListNode(9);
    ListNode* cur = s.addTwoNumbers(head,head1);
    while(cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    return 0;
}