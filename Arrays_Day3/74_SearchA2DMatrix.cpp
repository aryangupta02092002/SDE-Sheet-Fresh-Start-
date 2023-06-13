//Link: https://leetcode.com/problems/search-a-2d-matrix/

/*
Input: matrix = 
[[1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]], 

target = 3

Output: true
*/

//Brute force
/*
Traverse each element in the matrix and find whether the given target exists or not
TC: O(M*N);     SC: O(1)
*/

//Efficient
/*
Consider the matrix as 1D array, i.e., all the rows made together with index from 0 to (row*col)-1
Now apply binary search, using [mid/col][mid%col]
TC: O(log(m*n))
SC: O(1)
*/
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int row = mat.size(), col = mat[0].size();
    int low = 0, high = (row * col)-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(mat[mid/col][mid%col] == target){
            return true;
        }
        if(mat[mid/col][mid%col] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return false;
}
