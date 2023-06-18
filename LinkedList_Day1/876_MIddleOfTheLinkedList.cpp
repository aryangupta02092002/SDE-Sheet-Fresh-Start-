//Link: https://leetcode.com/problems/middle-of-the-linked-list/description/
/*
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
*/

//Brute force
/*
Traverse through the link to count number of nodes and then another loop which went half of the size of the list
TC: O(N) + O(N/2)
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode *tmp = head;

        while(tmp){
            n++;
            tmp = tmp->next;
        }
        tmp = head;
        for(int i=0; i<n/2; i++){
            tmp = tmp->next;
        }
        return tmp;
    }
};


//Floyd's Algorithm | Tortoise-Hare Algorithm
/*
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
