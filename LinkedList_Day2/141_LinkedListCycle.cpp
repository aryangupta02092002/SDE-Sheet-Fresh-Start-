//Link: https://leetcode.com/problems/linked-list-cycle/description/
/*
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/


//Brute force
/*
Using hashing
Using set data structure
Maintain a set ds, where keep on checking whether a node present or not, if present return true else keep on inserting.
TC: O(N)
SC: O(N)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> st;
        while(head != NULL){
            if(st.find(head) != st.end()){
                return true;
            }
            st.insert(head);
            head = head->next;
        }
        return false;
    }
};


//Optimized
/*
Using Tortoise-Hare Algorithm
Using two pointers fast and slow, and check whether slow is equals to fast or not, return true if equals.
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
