//Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1
/*
Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
*/

/*
*/

void helper(int idx, vector<int> &arr, int n, vector<int> &ans, int sum){
        if(idx == n){
            ans.push_back(sum);
            return;
        }
        sum += arr[idx];
        helper(idx+1, arr, n, ans, sum);
        sum -= arr[idx];
        helper(idx+1, arr, n, ans, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        helper(0, arr, N, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
