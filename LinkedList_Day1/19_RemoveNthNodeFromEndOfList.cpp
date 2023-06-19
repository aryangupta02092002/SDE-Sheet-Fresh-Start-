//Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/*
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

//Brute force
/*
We can traverse through the Linked List while maintaining a count of nodes, let’s say in the variable count, 
and then traversing for the 2nd time for (n – count) nodes to get to the nth node of the list.
*/


//Efficiency
/*
Two pointers approach
1.Take two dummy nodes, who’s next will be pointing to the head.

2.Take another node to store the head, initially,s a dummy node(start), and the next node will be pointing to the head. 
The reason why we are using this extra dummy node is that there is an edge case. 
If the node is equal to the length of the LinkedList, then this slow will point to slow’s next→ next. 
And we can say our dummy start node will be broken and will be connected to the slow next→ next.

3.Start traversing until the fast pointer reaches the nth node.

4.Now start traversing by one step both of the pointers until the fast pointers reach the end.    

5.When the traversal is done, just do the deleting part. Make slow pointers next to the next 
of the slow pointer to ignore/disconnect the given node.

6.Last, return to the next start.
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;

        for(int i=1; i<=n; i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
