/*
牛的，需要多看
用到的知识： 递归 + 倒转链表
麻麻的

这里给出倒转链表的代码：
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur, cur = next;
        }
        return prev;
    }
};

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
    ListNode* mySwap(ListNode* head,int k){
        ListNode* temp = head;
        for(int i = 0;i<k;i++){
            if(temp == nullptr) return head;
            temp = temp -> next;
        }//先确定剩下的链表够不够翻转，不够直接return head

        ListNode* cur = head;
        ListNode* prev = mySwap(temp,k);
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        while(cur!=temp){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = mySwap(head,k);
        return res;
    }
};