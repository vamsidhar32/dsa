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
        if(l1 == NULL) return l2 ;
        if(l2 == NULL) return l1 ;

        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy ;

        while(l1 || l2){
            int sum = 0 ;
            if(l1) sum += l1->val ;
            if(l2) sum += l2->val ;
            sum += carry ;

            ListNode* temp = new ListNode(sum % 10);
            prev->next = temp ;
            prev = temp ;

            carry = (sum > 9) ? 1 : 0; 

            if(l1) l1 = l1->next ;
            if(l2) l2 = l2->next ;
        }

        if(carry == 1){
            ListNode* temp = new ListNode(1);
            prev->next = temp ;
            prev = temp ;
        }
        ListNode* ret = dummy->next ;

        dummy->next = NULL;
        delete dummy ;

        return ret ;
    }
};