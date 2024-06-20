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
    class customcomp{
        public:
            bool operator() (ListNode* a , ListNode* b){
                return (a->val > b->val) ;
            }
        };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-10000007);
        ListNode* ans = dummy ;


        priority_queue<ListNode*,vector<ListNode*>,customcomp>pq;

        for(int i = 0 ; i <lists.size(); i++){
            if(lists[i]) pq.push(lists[i]);
        }

        while(!pq.empty()){

            ListNode* top = pq.top();
            pq.pop();

            dummy->next = top;
            dummy = dummy->next ;
            if(top->next) pq.push(top->next);
        }

        return ans->next ;
    }
};