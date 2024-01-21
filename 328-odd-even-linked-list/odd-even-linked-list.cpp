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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyeven = new ListNode(-1);
        ListNode* even = dummyeven;
        ListNode* dummyodd  = new ListNode(-1);
        ListNode* odd = dummyodd;
        ListNode* temp = head;
        int flag = -1 ;

        while(temp){
            if(flag == -1){
                odd->next = temp;
                odd = temp;
                flag = 1;
            }
            else if(flag == 1){
                even->next = temp;
                even = temp;
                flag = -1 ;
            }

            temp = temp->next;
        }
        even->next = NULL;
        odd->next = NULL;

        odd->next = dummyeven->next;

        return head;


    }
};