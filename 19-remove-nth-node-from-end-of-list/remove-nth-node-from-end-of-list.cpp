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
        if(head == NULL){
            return NULL;
        }
        ListNode* fast = head ;

        for(int i = 0 ; i < n-1; i++){
            fast = fast->next;
        }
        if(fast ->next == NULL){
            ListNode* temp = head ;

            head = head->next ;
            temp->next = NULL ;
            delete temp ;

            return head;
        }
        ListNode* slow = head;

        while(fast->next->next != NULL){
            fast = fast ->next ;
            slow = slow->next ;

        }

        ListNode* temp = slow->next ;
        slow->next = temp->next ;

        temp->next = NULL ;
        delete temp ;
         
        return head ;


    }
};