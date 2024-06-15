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
    bool isPalindrome(ListNode* head) {
        if(head == NULL && head->next == NULL) return true;
        ListNode* fast = head ;
        ListNode* slow = head ;
        ListNode* prev = NULL ; 
        while(fast && fast->next){
            fast = fast->next->next;

            ListNode* rev = slow ;
            slow = slow->next ;
            rev->next = prev;
            prev = rev;        
        }

        if(fast == NULL){
            while(slow){
                if(slow->val != prev->val) return false ;
                slow = slow->next ;
                prev = prev->next ;
            }
            return true;
        }

        else if(fast->next == NULL){
            slow = slow->next ;
            while(slow){
                if(slow->val != prev->val) return false ;
                slow = slow->next ;
                prev = prev->next ;
            }
            return true;
        }

        return true ;
    }
};