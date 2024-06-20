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
    ListNode* merge(ListNode* list1,ListNode* list2){

        //if(list1 == NULL || list2 == NULL) return NULL ;
        ListNode* dummy  = new ListNode(-10000004);
        ListNode* ans =  dummy ;

        while(list1 && list2){
            if(list1->val <= list2->val){
                dummy->next = list1;
                dummy = dummy->next;

                list1 = list1->next;     
            }

            else if(list2->val < list1->val){
                dummy->next = list2;
                dummy = dummy->next ;

                list2 = list2->next; 
            }

        }
        if(list1) dummy->next = list1; 
        if(list2) dummy->next = list2;

        //dummy->next = NULL ;

        ListNode* temp = ans->next ;
        ans->next = NULL ;
        delete ans;
        return temp;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* dummy = new ListNode(-10000007);
        ListNode* ans = dummy ;
        for(int i = 0 ; i < lists.size(); i++){
            dummy = merge(dummy,lists[i]);
        }
        
        ListNode* temp = ans->next ;

        ans->next = NULL ;
        delete ans ;
        return temp;
        
    }
};