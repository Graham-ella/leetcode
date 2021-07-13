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

        ListNode* rs = new ListNode(-1);//先弄出来个头节点
        ListNode* tempResult = rs;
        int carry = 0;

        while (l1||l2) {//如果两者的next都为空就代表结束了
            if (l1 && l2) {//如果两者都不为空
                int tempVal = (*l1).val + (*l2).val;
             
                if (carry == 1) {
                    tempVal = (*l1).val + (*l2).val + 1;
                    carry = 0;
                }
             
                if (tempVal >= 10) {
                    tempVal %= 10;
                    carry = 1;//进位
                }

                (*tempResult).next = new ListNode(tempVal);
                tempResult = tempResult->next;
                l1 = l1->next;
                l2 = l2->next;

            }

            if (!l1&& l2) {//如果l1没了，l2还有
                //复制l2剩下的就行了
                int tempVal = l2->val;
               
                if (carry == 1) {
                    tempVal = l2->val + 1;
                    carry = 0;
                }
                if (tempVal >= 10) {
                    tempVal %= 10;
                    carry = 1;//进位
                }

                (*tempResult).next = new ListNode(tempVal);
                tempResult = tempResult->next;
                l2 = l2->next;
            }

            if (l1 && !l2) {//如果l2没了，l1还有
               //复制l1剩下的就行了
                int tempVal = l1->val;

                if (carry == 1) {
                    tempVal = l1->val + 1;
                    carry = 0;
                }
                if (tempVal >= 10) {
                    tempVal %= 10;
                    carry = 1;//进位
                }

                (*tempResult).next = new ListNode(tempVal);
                tempResult = tempResult->next;
                l1 = l1->next;
            }
        }

        //最后一位可能有进位
        if (carry == 1) {
            (*tempResult).next = new ListNode(1);
            tempResult = tempResult->next;
        }

        return rs->next;
    }
};