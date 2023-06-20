//Link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
/*
Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:
2
Here, both lists intersecting nodes start from node 2.
*/


//Brute force
/*
Using two while loop, and compare the nodes
TC: O(N*M)
SC: O(1)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB != NULL){
            ListNode *tmp = headA;
            while(tmp != NULL){
                if(tmp == headB){
                    return headB;
                }
                tmp = tmp->next;
            }
            headB = headB->next;
        }
        return NULL;
    }
};


//Better Solution
/*
Hashing
Using set data structure
Store the nodes in the set, and then run another loop for other list and check for the presence of the node
TC: O(N+M)
SC: O(N)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;
        while(headA != NULL){
            st.insert(headA);
            headA = headA->next;
        }

        while(headB != NULL){
            if(st.find(headB) != st.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};


//Optimized Solution
/*
Take two dummy nodes for each list. Point each to the head of the lists.
Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.
TC: O(2 * MAX(M , N))
SC: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp1 = headA, *tmp2 = headB;
        while(tmp1 != tmp2){
            tmp1 = tmp1 == NULL ? headB : tmp1->next;
            tmp2 = tmp2 == NULL ? headA : tmp2->next;
        }
        return tmp1;
    }
};
