//Link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
/*
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
*/

//Optimized
/*
The process to flatten the given linked list is as follows:-

We will recurse until the head pointer moves null. The main motive is to merge each list from the last.
Merge each list chosen using the merge algorithm. The steps are
Create a dummy node. Point two pointers, i.e, temp and res on dummy node. ans is to keep track of dummy node
and temp pointer is to move ahead as we build the flattened list.
We iterate through the two chosen. Move head from any of the chosen lists ahead whose current pointed node is smaller. 
Return the new flattened list found.
TC: O(N)
SC: O(1)
*/

Node *mergeTwoLists(Node *a, Node *b){
    Node *tmp = new Node(0);
    Node *ans = tmp;
    
    while(a != NULL && b != NULL){
        if(a->data < b->data){
            tmp->bottom = a;
            tmp = tmp->bottom;
            a = a->bottom;
        }
        else{
            tmp->bottom = b;
            tmp = tmp->bottom;
            b = b->bottom;
        }
    }
    
    if(a){
        tmp->bottom = a;
    }
    else{
        tmp->bottom = b;
    }
    
    return ans->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
    if(root == NULL || root->next == NULL){
        return root;
    }
    
    root->next = flatten(root->next);
    
    root = mergeTwoLists(root, root->next);
    
    return root;
}
