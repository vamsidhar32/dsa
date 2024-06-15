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
    ListNode* reversee(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev =NULL;
        ListNode* temp = head ;

        while(temp){
            ListNode* store = temp ;
            temp = temp->next;
            store->next = prev ;
            prev = store ;
        }

        return prev ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head ;

        ListNode* temp = head;
        int count = 0;
        int flag = 0 ;

        ListNode* prev = head;
        ListNode* attach = new ListNode(-1) ;
        ListNode* ret = attach;

        while(temp){
            count++;

            if(count == k ){

                if(flag == 0) {head = temp; flag =1 ;}

                ListNode* revhead = temp ;
                temp = temp->next;
                revhead->next = NULL ;
                revhead = reversee(prev);

                attach->next = revhead ;
                attach = prev;

                //prev->next = temp;
                prev = temp ;

                count = 0;
                continue;

                
            }
            temp = temp->next ;

        }
        attach->next = prev ;

        return ret->next ;
    }
};