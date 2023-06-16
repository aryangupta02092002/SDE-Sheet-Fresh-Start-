//Link: https://bit.ly/3fp24yN
/*
Example 1:
Input Format: A = [4, 2, 2, 6, 4] , k = 6
Result: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
*/

//Brute force
/*
We will check the XOR of every possible subarray and count how many of them are equal to k. 
To get every possible subarray sum, we will be using three nested loops. 
TC: O(N^3)
SC: O(1)
*/
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    int count = 0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int xorr = 0;
            for(int k=i; k<=j; k++){
                xorr = xorr ^ arr[k];
            }
            if(xorr == x){
                count++;
            }
        }
    }
    return count;
}


//Better sol
/*
TC: O(N^2)
SC: O(1)
*/
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {
            xorr = xorr ^ arr[j];

            if (xorr == x) 
                count++;
        }
    }
    return count;
}


//Optimal Sol
/*
Using Hashing
TC: O(N*LogN)
SC: O(N)
*/
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    int count = 0;

    int xorr = 0;
    map<int, int> m; 
    m[xorr]++;

    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
        int tmp = xorr ^ x;

        count += m[tmp];
        m[xorr]++;
    }
    return count;
}
