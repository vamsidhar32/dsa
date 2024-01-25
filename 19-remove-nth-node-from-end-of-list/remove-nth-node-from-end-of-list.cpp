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
        if(head == NULL || head->next == NULL){
            return NULL ;
        }
        ListNode* temp = head, *fast = head ,*slow = head ;
        for(int i = 0 ; i<n ; i++){
            fast = fast->next ;
        }
        if(fast == NULL){
            ListNode* x = head ;
            head = head->next;


            x->next = NULL;
            delete x ;

            return head;
        }

        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* x = slow->next ;
        slow->next = slow->next->next;
        x->next = NULL ;
        delete x;

        return head;



        
    }
};