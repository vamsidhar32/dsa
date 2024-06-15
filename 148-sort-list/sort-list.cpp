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
    ListNode* middle(ListNode* head){
        if(head == NULL || head->next == NULL) return head ;
        ListNode* fast = head;
        ListNode* slow = head ;
        fast = fast->next->next ;
        while(fast && fast->next){
            fast = fast->next->next ;
            slow = slow->next ;
        }
        return slow ;
    }
    ListNode* merge(ListNode* sort1, ListNode* sort2){
        ListNode* first = sort1;
        ListNode* second = sort2;
    if(first == NULL) return second ;
    if(second == NULL) return first;

    ListNode* dummy = new ListNode(-1);

    ListNode* prev = dummy ;

    ListNode* l1 = first ;
    ListNode* l2 = second; 

    while(l1 && l2){
        if(l1->val <= l2->val){
            prev->next =l1 ;
            prev = l1;
            l1 = l1->next ;
        }
        else{
            prev->next =l2 ;
            prev = l2;
            l2 = l2->next ;
        }
    }

    if (l1) {
        prev->next = l1;
        prev = l1;
    }

    if(l2){
        prev->next = l2;
        prev = l2;
    }

    return dummy->next;

    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head ;

        ListNode* mid = middle(head);
        ListNode* second = mid->next ;
        mid->next = NULL ;

        ListNode* sort1 = sortList(head);
        ListNode* sort2 = sortList(second);

        ListNode* merged = merge(sort1,sort2);

        return merged;
    }
    
};