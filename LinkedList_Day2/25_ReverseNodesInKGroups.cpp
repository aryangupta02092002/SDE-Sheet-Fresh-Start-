//Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
/*
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/


/*
The following steps are needed to arrive at the desired output. 
->
Create a dummy node. Point next to this node to head of the linked list provided.
Iterate through the given linked list to get the length of the list.
Create three pointer pre,cur and nex to reverse each group. Why? If we observe output, 
we can see that we have to reverse each group, apart from modifying links of group.
Iterate through the linked list until the length of list to be processed is greater than and equal to given k.
For each iteration, point cur to pre->next and nex to nex->next.
Start nested iteration for length of k.
For each iteration, modify links as following steps:-
cur->next = nex->next
nex->next = pre->next
pre->next = nex
nex = cur->next
Move pre to cur and reduce length by k.
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
    int lengthOfLL(ListNode *head){
        int sz = 0;
        while(head != NULL){
            head = head->next;
            sz++;
        }
        return sz;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int leng = lengthOfLL(head);

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy, *curr, *nex;

        while(leng >= k){
            curr = pre->next;
            nex = curr->next;

            for(int i=1; i<k; i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            leng -= k;
        }

        return dummy->next;
    }
};
