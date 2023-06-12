/*
Input: nums = [1,3,4,2,2]
Output: 2
*/

//Brute Force
/*
Sort the given array and then check for duplicate numbers.
TC: O(Nlogn + N)
SC: O(1)
*/
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(arr[i] == arr[i+1]){
            return arr[i];
        }
    }
}


//Better
/*
Using hashing or frequency array
TC: O(N);    SC: O(N)
*/
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    int freq[n+1] = {0};
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
        if(freq[arr[i]] > 1){
            return arr[i];
        }
    }
}


//Optimized
/*
Using fast and slow pointer same as Linkedlist to find the duplicate when fast == slow
TC: O(N)
SC: O(1)
*/
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    int slow = arr[0];
    int fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);
    
    fast = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
