//Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
/*
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

//Brute force
/*
Step 1: Create a new dummy node. It will have the value 0 and will point to NULL respectively. 
This will be the head of the new list. Another pointer to keep track of traversals in the new list.
Step 2:  Find the smallest among two nodes pointed by the head pointer of both input lists, 
and store that data in a new list created.
Step 3: Move the head pointer to the next node of the list whose value is stored in the new list.
Step 4: Repeat the above steps till any one of the head pointers stores NULL. 
Copy remaining nodes of the list whose head is not NULL in the new list.
TC: O(N+M)
SC: O(N+M)
*/


//Optimized - No extra space
/*
Step 1: Create two pointers, say l1 and l2. Compare the first node of both lists and find 
the small among the two. Assign pointer l1 to the smaller value node.
Step 2: Create a pointer, say res, to l1. An iteration is basically iterating through both
lists till the value pointed by l1 is less than or equal to the value pointed by l2.
Step 3: Start iteration. Create a variable, say, temp. It will keep track of the last node sorted list in an iteration. 
Step 4: Once an iteration is complete, link node pointed by temp to node pointed by l2. Swap l1 and l2.
Step 5: If any one of the pointers among l1 and l2 is NULL, then move the node pointed by temp to the next higher value node.
TC: O(N+M)
SC: O(1)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        if(list1->val > list2->val){
            swap(list1, list2);
        }
        ListNode *ans = list1;
        
        while(list1 != NULL && list2 != NULL){
            ListNode *tmp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                tmp = list1;
                list1 = list1->next;
            }
            tmp->next = list2;
            swap(list1, list2);
        }
        return ans;
    }
};
