//Link: https://leetcode.com/problems/reverse-pairs/description/
/*
Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
*/

//Brute Force
/*
Simple, just two nested for loops, as we know i < j, so we will fix i at one index and j from i+1, 
and then we will compare the elements and count which satisfies the conditions
TC: O(N^2)
SC: O(1)
*/
#include <bits/stdc++.h> 
int helper(vector<int> &arr, int n){
	int count = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i] > 2*arr[j]){
				count++;
			}
		}
	}
	return count;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	return helper(arr, n);
}


//Optimized
/*
Merge sort
Why the same logic of count inversion will not work?
The merge function works by comparing two elements from two halves i.e. arr[left] and arr[right]. 
Now, the condition in the question was arr[i] > arr[j]. That is why we merged the logic. 
While comparing the elements, we counted the number of pairs.

But in this case, the condition is arr[i] > 2*arr[j]. And, we cannot change the condition of 
comparing the elements in the merge() function. If we change the condition, 
the merge() function will fail to merge the elements. So, we need to check this condition and count the number of pairs separately.

In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the mergeSort().
We will add the numbers returned by the previous mergeSort() calls.
Before the merge step, we will count the number of pairs using a function, named countPairs().
We need to remember that the left half starts from low and ends at mid, and the right half starts from mid+1 and ends at high.
The steps of the countPairs() function will be as follows:

We will declare a variable, cnt, initialized with 0.
We will run a loop from low to mid, to select an element at a time from the left half.
Inside that loop, we will use another loop to check how many elements from the right half can make a pair.
Lastly, we will add the total number of elements i.e. (right-(mid+1)) (where right = current index), to the cnt and return it.

TC: O(2N*logN);    SC: O(N)
*/
#include <bits/stdc++.h> 
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;  
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);  
    return cnt;
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	return mergeSort(arr, 0, n - 1);
}
