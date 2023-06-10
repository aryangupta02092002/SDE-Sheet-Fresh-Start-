//Type 1 : When row and col given, have to find element at that particular index. TC = O(R)
//Brute force : using the combination formula completely
//Mathematically analizing combination formula and shortening it for optimized solution
int nCr(int n, int r){     //r=5, c=3   -> ans = 6     ncr(r-1, c-1)
    long long ans = 1;
    for(int i=0; i<r; i++){
        ans = ans * (n-i);
        ans = ans/(i+1);
    }
    return ans;
}


//Type 2 : Print nth row of the Pascal triangle
//n=5 -> 1 4 6 4 1
//Brute force could be using the above combination based formula to find element at each place, 
//and thus calling the function again and again.  TC: O(N*R)

//Better sol: rather calling nCr function, create a loop in the main function, 
//doing the same task and also printing before the loop ends
//TC = O(N)
//Link: https://leetcode.com/problems/pascals-triangle-ii/description/
vector<int> getRow(int n){
    vector<int> ans;
    long long val = 1;
    ans.push_back(val);
    
    for(int i=1; i<n; i++){
        val = val * (n-i);
        val = val/i;
        ans.push_back(val);
    }
    return ans;
}


//Type 3 : Given total number of rows n, print the entire triangle
//Brute force = Can use the first way, but not efficient as it will take TC = O(N * N * R), 
//as using the type 1 funtion for the same ~ O(N^3)

//Efficient: Using type 2 format to print the triangle. TC = O(N^2)
  vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> rowAns;
        rowAns.push_back(1);

        for(int col=1; col<row; col++){
            ans = ans * (row-col);
            ans = ans/col;
            rowAns.push_back(ans);
        }
        return rowAns;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
