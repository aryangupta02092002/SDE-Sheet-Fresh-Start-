//Link: https://leetcode.com/problems/reverse-linked-list/
/*
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

//Iterative solution
//TC: O(N);       SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = NULL;
        while(head != NULL){
            ListNode *tmp = head->next;
            head->next = dummy;
            dummy = head;
            head = tmp;
        }
        return dummy;
    }
};


//Recursive sol
//TC: O(N);     SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *tmp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tmp;
    }
};
