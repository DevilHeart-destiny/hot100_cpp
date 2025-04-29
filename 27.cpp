/**
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            // if(list1==nullptr) return list2;
            // if(list2==nullptr) return list1;
            // if(list1==nullptr && list2==nullptr) return nullptr;
            // ListNode* cur_1 = list1;
            // ListNode* cur_2 = list2;
            // ListNode* res;
            // ListNode* cur;
            // if(cur_1->val <= cur_2->val)
            // {
            //     res = cur_1;
            //     cur = cur_1;
            //     cur_1 = cur_1->next;
            // }
            // else
            // {
            //     res = cur_2;
            //     cur = cur_2;
            //     cur_2 = cur_2->next;
            // }
            // while(cur_1!=nullptr && cur_2!=nullptr)
            // {
            //     if(cur_1->val > cur_2->val) swap(cur_1,cur_2);
            //     cur->next = cur_1;
            //     cur_1 = cur_1->next;
            //     cur = cur->next;
            // }
            // while(cur_1)
            // {
            //     cur->next = cur_1;
            //     cur_1 = cur_1->next;
            //     cur = cur->next;
            // }
            // while(cur_2)
            // {
            //     cur->next = cur_2;
            //     cur_2 = cur_2->next;
            //     cur = cur->next;
            // }
            // return res;

            ListNode* dum = new ListNode(0);
            ListNode* cur = dum;
            while(list1 != nullptr && list2 != nullptr)
            {
                if(list1->val < list2->val)
                {
                    cur->next = list1;
                    list1 = list1->next;
                }
                else{
                    cur->next = list2;
                    list2 = list2->next;
                }
                cur = cur->next;
            }
            cur->next = list1 == nullptr? list2 : list1;
            return dum->next;
        }
    };
 
 int main()
 {
     Solution s;
     ListNode* head = new ListNode(4);
    //  head->next = new ListNode(2);
    //  head->next->next = new ListNode(3);
     ListNode* head1 = new ListNode(1);
     ListNode* cur = s.mergeTwoLists(head,head1);
     while(cur)
     {
         cout << cur->val << ' ';
         cur = cur->next;
     }
     return 0;
 }