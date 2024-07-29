/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int flag1 = 0 , flag2 = 0 ; 
        ListNode* tempA = headA ;
        ListNode* tempB = headB;

        while(tempA != tempB){
            tempA = tempA->next ;
            if(tempA == NULL && flag1 == 0){
                tempA = headB;
                flag1 = 1 ;
            } 
            tempB = tempB->next ;
            if(tempB == NULL && flag2 == 0){
                tempB = headA;
                flag2 = 1 ;
            } 
        }

        
        return tempA ;
    }
};