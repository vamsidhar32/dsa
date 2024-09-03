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
    ListNode* func(ListNode* head){
        if(head == NULL || head->next == NULL) return head ;
        ListNode* slow = head ;
        ListNode* fast = head ;
        fast = fast->next->next ;

        while(fast&& fast->next){
            fast = fast->next->next ;
            slow = slow->next ;
        }

        return slow ;
    }

    ListNode* merged(ListNode* first , ListNode* second){
        if(first == NULL) return second ;
        if(second == NULL) return first ;

        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy ;

        while(first && second){
            if(first->val <= second->val){
                prev->next = first ;
                prev = first ;
                first = first->next ;
            }
            else if(second->val < first->val){
                prev->next = second ;
                prev = second ;
                second = second->next ;
            }
        }

        if(first) prev->next = first ;
        if(second) prev->next = second ;
        
        ListNode* ret = dummy->next ;


        dummy->next = NULL ;
        delete dummy ;

        return ret ;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head ;

        ListNode* middle = func(head);
        ListNode* second = middle->next ;
        middle->next = NULL ;

        ListNode* fir = sortList(head);
        ListNode* sec = sortList(second);

        return merged(fir,sec);
    }
};