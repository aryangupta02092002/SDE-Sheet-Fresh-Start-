//Link: https://www.codingninjas.com/codestudio/problems/median-of-a-row-wise-sorted-matrix_1115473?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
/*
Example 1:
Input: 
r = 3 , c = 3
1 4 9 
2 5 6
3 8 7
Output: Median = 5
Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9
So, median = 5
*/


//Brute force (Linear force)
/*
The approach is very simple, just fill all elements in a linear array sort the array using the sort function, and then find the 
middle value (Median). 
TC: O(row*col log(row*col)) for sorting the array where r*c denotes the number of elements in the linear array.
SC: O(row*col)  for storing elements in the linear array
*/
int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    int median[m*n];
    int idx = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            median[idx] = matrix[i][j];
            idx++;
        }
    }
    int sz = sizeof(median) / sizeof(median[0]);
    sort(median, median+sz);
    return median[(m*n)/2];
}


//Optimized Sol (Binary search)
/*
Step 1: Find the minimum and maximum element in the given array. By just traversing the first column, we find the minimum element and by just traversing the last column, we find the maximum element.

Step 2: Now find the middle element of the array one by one and check in the matrix how many elements are present in the matrix.

Three cases can occur:-

- If count ==  (r*c+1)/2 , so it may be the answer still we mark max as mid since we are not referring indices,
  we are referring the elements and 5 elements can be smaller than 6 also and 7 also , so to confirm we mark max as mid.
- If count<(r*c+1)/2 , we mark  min as mid+1 since curr element or elements before it cannot be the answer.
- If count>(r*c+1)/2 , we mark max as mid , since elements after this can only be the  answer now.

TC: O(row*log col) since the upper bound function takes log c time.
SC: O(1)
*/
![Screenshot](https://lh6.googleusercontent.com/4TXWnuiVcUQEaQUiomnn_gwquL9qfAT4O38Qls6Sdz_ZNnnxt5txhGiiJLsYAL5OR9zAvchqsVwQmkGlLfro3CVDqieinu3VgyFba1tbmzxt9cFUpeky5ufzZ-clfJmGlbkRGkic?raw=true)
![Screenshot](https://lh5.googleusercontent.com/3Aozu7SCX0Tq2Jf0W8TEGeeQSSX6KeRzGK2AblElAuhYPELxbZmtRQ0EK3H3hIVH_XfXR1Fd4EekyiitASB1g1D5qucGDdaWBDJW2BTmAELKBMqbwtW4i9zCszBynrKE7kpldAtk?raw=true)
int countSmallerThanMid(vector<int> &row, int mid){
    int low = 0, high = row.size()-1;
    while(low <= high){
        int m = low + (high - low)/2;
        if(row[m] <= mid){
            low = m+1;
        }
        else{
            high = m-1;
        }
    }
    return low;
}
int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    int low = 1, high = 1e9;
    while(low <= high){
        int mid = low + (high-low)/2;
        int count = 0;

        for(int i=0; i<m; i++){
            count += countSmallerThanMid(matrix[i], mid);
        }
        if(count <= (m * n)/2){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
