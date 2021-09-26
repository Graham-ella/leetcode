/*
这题给我自己实在是不会做了估计
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1,head);
        ListNode* p = dummy;
        while(p->next){
            ListNode* q = p -> next;
            while(q && q->val == p->next->val) q = q->next;
            /*
            上面这个循环第一次是肯定成立的 但是为了留住它 我也只希望它循环一次
            这样 q 也就在 p的next的next的位置
            */
            if(p->next->next == q) p = p->next;
            else p->next = q;
        }
        return dummy->next;
    }
};
