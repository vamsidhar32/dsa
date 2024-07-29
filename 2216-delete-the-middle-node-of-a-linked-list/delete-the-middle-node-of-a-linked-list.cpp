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

        if(head == NULL || head->next == NULL) return NULL ;
        ListNode* fast = head ;
        ListNode* slow = head ;


        fast = fast->next->next ;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next ;
            slow = slow->next ;
        }

        ListNode* del = slow->next;
        slow->next = del->next ;

        del->next = NULL ;
        delete del ;

        return head ;
    }
};