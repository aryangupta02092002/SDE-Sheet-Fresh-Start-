//Link:
/*
*/

//Brute force
/*
Hashing
Using set ds
TC: O(N)
SC: O(N)
*/
ListNode* detectCycle(ListNode* head) {
    unordered_set<ListNode*> st;
    while(head != NULL) {
        if(st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}


//Optimized sol
/*
Slow and fast pointer
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        if(head == NULL || head->next == NULL){
           return NULL;
        }
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                fast = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
