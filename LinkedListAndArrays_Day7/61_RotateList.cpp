//Link: https://leetcode.com/problems/rotate-list/description/
/*
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/
/*
Steps to the algorithm:-

Calculate the length of the list.
Connect the last node to the first node, converting it to a circular linked list.
Iterate to cut the link of the last node and start a node of k%length of the list rotated list.
TC: O(length of list) + O(length of list – (length of list%k))
SC: O(1)
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0){
            return head;
        }

        int sz = 1;
        ListNode *tmp = head;
        while(tmp->next != NULL && sz++){
            tmp = tmp->next;
        }

        tmp->next = head;
        k = k%sz;
        k = sz-k;

        while(k--){
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next = NULL;

        return head;
    }
};
