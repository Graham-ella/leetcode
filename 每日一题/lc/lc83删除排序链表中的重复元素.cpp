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
        if(!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* cur = head->next;
        while(cur){
            if(cur->val != temp->val){
                temp->next = cur;
                temp = temp->next;
            } 
            cur = cur->next;
        }
        temp->next = nullptr;
        return head;
    }
};
