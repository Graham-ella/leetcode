/*
lc19. 删除链表的倒数第n个节点
思路：感觉利用双指针算法即可
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* flag = new ListNode(0,head);
        ListNode* left = flag;
        ListNode* right = head;
        for(int i = 0 ; i < n;i++){
            right = right->next;
        }
        while(right){
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        ListNode* res = flag->next;
        delete(flag);
        return  res;
    }
};