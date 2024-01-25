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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL ;
        }
        ListNode* fast = head ;
        ListNode* slow  = head ;
        fast = fast->next->next ;

        while(fast && fast->next){
            fast = fast->next->next ;
            slow = slow->next ;

        }   
        ListNode* temp = slow->next ;
        slow->next = slow->next->next ;
        temp->next = NULL ;
        delete temp ;

        return head ;

        

    }
};