/*
Intuition we need all the nodes one by one and in sorted order, which can be achieved by min heap
Approach push all nodes into the min heap and then take out one single at a time create a new linked list
Complexity
Time complexity: O(nk) + O(nklognk)
Space complexity: O(nk)
Code
*/
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
    class Compare{
        public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        //pushing all nodes into the priority queue
        for(int i=0; i<lists.size(); i++){
            ListNode* head = lists[i];
            while(head!=NULL){
                ListNode* curr = head;
                head= head->next;
                curr->next = NULL;
                pq.push(curr);
            }
        }

        //now take out all the nodes from the priority queu and create a final listnode
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;
        }
        return head->next;
    }
};
