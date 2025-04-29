/**
23. 合并 K 个升序链表
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
 */


#include<iostream>
#include<vector>
#include<queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    struct status
    {
        int val;
        ListNode* ptr;
        bool operator < (const status& rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue<status> qu;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto& node : lists)
        {
            if(node) qu.push({node->val,node});
        }
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while(!qu.empty())
        {
            cur->next = qu.top().ptr;
            qu.pop();
            cur = cur->next;
            if(cur->next) qu.push({cur->next->val,cur->next});
        }
        return head->next;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(6);
    head->next->next = new ListNode(7);
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(8);
    vector<ListNode*> nums = {head,head1};
    ListNode* cur = s.mergeKLists(nums);
    while(cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    return 0;
}
