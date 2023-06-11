/*
Input: matrix = [[1,2,3],
                 [4,5,6],
                 [7,8,9]]
Output: [[7,4,1],
         [8,5,2],
         [9,6,3]]
*/
//Brute force
/*
Take another dummy matrix, and take the first row and put it in the last column of the dummy mat, 
then second row in second last column and so on

TC: O(N*N);       SC: O(N*N)
*/
vector < vector < int >> rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          rotated[j][n - i - 1] = matrix[i][j];
      }
    }
    return rotated;
}

//Optimized solution
/*
Transpose the matrix and then reverse each row
TC: O(N*N) + O(N*N), first for transpose, other for reversing
SC: O(1)
*/

void rotateClockwise(int n, vector < vector < int >> & nums) {
    // Write your code here.
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(nums[i][j], nums[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        reverse(nums[i].begin(), nums[i].end());
    }
}
