//Link: https://leetcode.com/problems/palindrome-linked-list/
/*
Input: head = [1,2,2,1]
Output: true
*/

//Brute force
/*
Use extra space to store the linked list, reverse and check whether it's palindrome or not
TC: O(N)
SC: O(N)
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        for(int i=0; i<arr.size()/2; i++){
            if(arr[i] != arr[arr.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};


//Optimized Sol
/*
Following are the steps to this approach:-

Find the middle element of the linked list. 
Reverse a linked list from the next element of the middle element.
Iterate through the new list until the middle element reaches the end of the list.
Use a dummy node to check if the same element exists in the linked list from the middle element.
*/
class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode *dummy = NULL;
        while(head != NULL){
            ListNode *tmp = head->next;
            head->next = dummy;
            dummy = head;
            head = tmp;
        }
        return dummy;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return false;
        }

        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;
        fast = head;

        while(slow != NULL){
            if(fast->val != slow->val){
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};
