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
        if(head == NULL || head->next == NULL){
            return head ;
        }
        ListNode* odd = head , *even = head->next , *temp = head->next;

        while(odd && odd->next && even && even->next){
            ListNode* frontodd = odd->next->next ;
            odd->next = frontodd ;
            ListNode* fronteven = even->next->next ;
            even->next = fronteven ;

            odd = odd->next;
            even = even->next;

        }
        if(odd) odd->next = NULL ;
        if(even) even->next = NULL ;

        odd->next = temp;

        return head ;

    }
};