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

    ListNode* reversek(ListNode* rev){
        ListNode* temp = rev ;
        ListNode* prev = NULL ;
        while(temp){
            ListNode* curr = temp ;
            temp = temp->next ;
            curr->next = prev ;
            prev = curr ;
        }

        return prev ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL || head->next == NULL) return head ;

        ListNode* temp = head ;

        int count = 0 ;
        ListNode* rev = head ;
        ListNode* dummy = new ListNode(-1);
        ListNode* attach = dummy ;

        while(temp){
            count++;
            if(count == k){
                ListNode* curr = temp ;
                temp = temp->next ;
                curr->next = NULL ;

                ListNode* prev = reversek(rev);

                attach->next = prev ;
                attach = rev ;

                rev->next = temp ;
                rev = temp ;

                count = 0 ;
                continue ;
            }

            temp = temp->next ;

        }

        return dummy->next;


    }
};