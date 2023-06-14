//Link: https://leetcode.com/problems/unique-paths/
/*
Input Format: m = 2, n= 2
Output: 2

_s_ __
__  _e_
*/

//Brute force
/*
Using recursion, from index 0 of both row and column, andd traversing till get the last idex and then returning 1 
for whenever either of i and j reaches m and n.
TC: O(2^n), exponential, since helper in being called twice for each condition
SC: As we are using stack space for recursion so the space complexity will also be exponential.
*/
int helper(int i, int j, int m, int n){
    if(i == m-1 || j == n-1){
        return 1;
    }
    if(i>=m || j>=n){
        return 0;
    }
    else{
        return helper(i+1, j, m, n) + helper(i, j+1, m, n);
    }
}
int uniquePaths(int m, int n) {
	// Write your code here.
    return helper(0, 0, m, n);
}


//Better solution
/*
Using dp(memoization) in recursion to optimize the solution
*/
#include <bits/stdc++.h> 
int helper(int i, int j, int m, int n, vector<vector<int>> &dp){
    if(i == m-1 && j == n-1){
        return 1;
    }
    if(i>=m || j>=n){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    else{
        return dp[i][j] = helper(i+1, j, m, n, dp) + helper(i, j+1, m, n, dp);
    }
}
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    int ans = helper(0, 0, m, n, dp);
    
    if(m==1 && n==1){
        return ans;
    }
    return dp[0][0];
}



//Optimized
/*
Combinatorics
If we observe examples there is a similarity in paths from start to end. 
Each time we are taking an exactly m+n-2 number of steps to reach the end.
From start to reach the end we need a certain number of rightward directions and 
a certain number of downward directions. So we can figure out we need n-1 no. of rightward direction and
m-1 no. of downward direction to reach the endpoint.

Since we need an m+n-2 number of steps to reach the end among those steps if we 
choose n-1 rightward direction or m-1 downward direction and calculate the *combinations* 
( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.

Approach: The approach of this solution is very simple just use a for loop to calculate the m+n-2Cn-1  or m+n-2Cm-1 
TC: O(M-1) or O(N-1)
SC: O(1)
*/
int uniquePaths(int m, int n) {
	// Write your code here.
    int N = m+n-2;
    int r = m-1;
    double ans = 1;
    
    for(int i=1; i<=r; i++){
        ans = ans * (N-r+i) / i;
    }
    return (int)ans;
}
