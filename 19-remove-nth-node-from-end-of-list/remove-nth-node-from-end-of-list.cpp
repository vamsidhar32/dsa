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
        if(head == NULL) return NULL ;
        if(head->next == NULL) return NULL ;
        ListNode* temp = head ;
        while(n--){
            temp = temp->next ;
        }
        if(temp == NULL) return head->next ;
        temp = temp->next ;
        ListNode* start = head ;
        while(temp){
            start = start->next ;
            temp = temp->next ;
        }

        ListNode* del = start->next;
        start->next = del->next ;
        del->next == NULL ;
        delete del ;

        return head ;

    }
};