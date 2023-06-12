/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/
//Brute force
/*
Consider 2 pointers both at the starting of two arrays, now compare each elements at particular index
and put the min into new array
TC:  O(M+N) + O(M+N)
SC: O(M+N)
*/

void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
	// Write your code here.
	long long arr3[m+n];
	int l = 0, r = 0, k = 0;

	while(l < m && r < n){
		if(arr1[l] <= arr2[r]){
			arr3[k++] = arr1[l++];
		}
		else{
			arr3[k++] = arr2[r++];
		}
	}

	while(l < m){
		arr3[k++] = arr1[l++];
	}
	while(r < n){
		arr3[k++] = arr2[r++];
	}
	for(int i=0; i<n+m; i++){
    nums1[i] = nums3[i];
  }
}



//Optimized
/*
Using no extra space
Put the pointers at the end of the arrays, and then compare for each elements at the pointers
and sort the array
TC: O(N+M)
SC: O(1)
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	// Write your code here.
    int i = m-1, j = n-1, k = m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i] < nums2[j]){
            nums1[k--] = nums2[j--];
        }
        else{
            nums1[k--] = nums1[i--];
        }
    }
    while(j >= 0){
        nums1[k--] = nums2[j--];
    }
	
}
