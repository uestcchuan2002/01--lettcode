#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 1.获取中间节点
     ListNode* middleNode(ListNode* head) {
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            pre = slow; // 记录 slow 的前一个节点
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; // 断开 slow 的前一个节点和 slow 的连接
        return slow;
    }

    // 2.合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // 用哨兵节点简化代码逻辑
        ListNode* cur = &dummy; // cur 指向新链表的末尾
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1; // 把 list1 加到新链表中
                list1 = list1->next;
            } else { // 注：相等的情况加哪个节点都是可以的
                cur->next = list2; // 把 list2 加到新链表中
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2; // 拼接剩余链表
        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* head2 = middleNode(head);
        // 分治
        head = sortList(head);
        head2 = sortList(head2);

        return mergeTwoLists(head, head2);
    }
};