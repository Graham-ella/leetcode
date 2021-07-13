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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //巧用三目运算符
        ListNode* rs = new ListNode(-1);//储存结果链表的头
        ListNode* tempResult = rs;//用来往后添加节点
        int carry = 0;//进位标志
        while(l1||l2){
            int a1 = (l1)?l1->val:0;//l1对于和的贡献
            int a2 = (l2)?l2->val:0;//l2对于和的贡献
            int sum = a1 + a2 + carry;
            carry = (sum>=10)?1:0;
            tempResult->next = new ListNode(sum%10);
            tempResult = tempResult->next;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        //用来处理最后可能存在的进位
        if(carry){
             tempResult->next = new ListNode(1);
             tempResult = tempResult->next;
        }
        return rs->next;
    }
     
};
