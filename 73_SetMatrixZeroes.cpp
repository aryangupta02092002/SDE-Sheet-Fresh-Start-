//Brute force - traverse all the index, mark it, and then make the entire row and col as 0. TC = O(N * M) + O(N + M) + O(N * M)- VERY HIGH
//Better sol - TC = O(2 * N * M); SC = O(N) + O(M)
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int row[n];
        int col[m];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] == 1 || col[j] == 1){
                    mat[i][j] = 0;
                }
            }
        }
    }
};

//Best sol -> TC = O(2 * N * M); SC = CONST
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
//         int row[n];      -> mat[..][0]
//         int col[m];      -> mat[0][..]
        int col = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;

                    if(j != 0){
                        mat[0][j] = 0;
                    }
                    else{
                        col = 0;
                    }
                }
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mat[i][j] != 0){
                    if(mat[0][j] == 0 || mat[i][0] == 0){
                        mat[i][j] = 0;
                    }
                }
            }
        }

        if(mat[0][0] == 0){
            for(int j=0; j<m; j++){
                mat[0][j] = 0;
            }
        }

        if(col == 0){
            for(int i=0; i<n; i++){
                mat[i][0] = 0;
            }
        }

    }
};
