//Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
/*
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
*/

/*
Approach:

- Start at the source(0,0) with an empty string and try every possible path i.e upwards(U), downwards(D), leftwards(L) and rightwards(R).
- As the answer should be in lexicographical order so it’s better to try the directions in lexicographical order i.e (D,L,R,U)
- Declare a 2D-array named visited because the question states that a single cell should be included only once in the path,
  so it’s important to keep track of the visited cells in a particular path.
- If a cell is in path, mark it in the visited array.
- Also keep a check of the “out of bound” conditions while going in a particular direction in the matrix. 
- Whenever you reach the destination(n,n) it’s very important to get back as shown in the recursion tree.
- While getting back, keep on unmarking the visited array for the respective direction.Also check whether there is a different
  path possible while getting back and if yes, then mark that cell in the visited array.

  TC: O(4^(m*n)), because on every cell we need to try 4 different directions.
  SC: O(m*n)
*/
class Solution{
    public:
    void helper(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string tmp, vector<vector<int>> &vis){
        if(i == n-1 && j == n-1){
            ans.push_back(tmp);
            return;
        }
        
        //Down
        if(i+1 < n && !vis[i+1][j] && m[i+1][j] == 1){
            vis[i][j] = 1;
            helper(i+1, j, m, n, ans, tmp + 'D', vis);
            vis[i][j] = 0;
        }
        
        //Left
        if(j-1 >= 0 && !vis[i][j-1] && m[i][j-1] == 1){
            vis[i][j] = 1;
            helper(i, j-1, m, n, ans, tmp + 'L', vis);
            vis[i][j] = 0;
        }
        
        //Right
        if(j+1 < n && !vis[i][j+1] && m[i][j+1] == 1){
            vis[i][j] = 1;
            helper(i, j+1, m, n, ans, tmp + 'R', vis);
            vis[i][j] = 0;
        }
        
        //Up
        if(i-1 >= 0 && !vis[i-1][j] && m[i-1][j] == 1){
            vis[i][j] = 1;
            helper(i-1, j, m, n, ans, tmp + 'U', vis);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        
        if(m[0][0] == 1){
            helper(0, 0, m, n, ans, "", vis);
        }
        return ans;
    }
};
