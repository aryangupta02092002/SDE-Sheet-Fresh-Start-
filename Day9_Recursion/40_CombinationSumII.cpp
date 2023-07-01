//Link: https://leetcode.com/problems/combination-sum-ii/
/*
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/

/*
Before starting the recursive call make sure to sort the elements because the ans should contain the combinations in 
sorted order and should not be repeated.

Initially, We start with the index 0, At index 0 we have n – 1 way to pick the first element of our subsequence.

Check if the current index value can be added to our ds. If yes add it to the ds and move the index by 1. 
While moving the index skip the consecutive repeated elements because they will form duplicate sequences.

Reduce the target by arr[i],call the recursive call for f(idx + 1,target – 1,ds,ans) after the call make sure to pop
the element from the ds.(By seeing the example recursive You will understand).

If(arr[i] > target) then terminate the recursive call because there is no use to check as the array is sorted in 
the next recursive call the index will be moving by 1 all the elements to its right will be in increasing order.

Base Condition:
Whenever the target value is zero add the ds to the ans return.
TC: O(2^n*k)
SC: O(k*x)
*/

class Solution {
public:
    void helper(int idx, int tar, vector<int> &cand, vector<vector<int>> &ans, vector<int> &tmp){
        if(tar == 0){
            ans.push_back(tmp);
            return;
        }

        for(int i=idx; i<cand.size(); i++){
            if(i > idx && cand[i] == cand[i-1]){
                continue;
            }
            tmp.push_back(cand[i]);
            helper(i+1, tar - cand[i], cand, ans, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(0, target, candidates, ans, tmp);
        return ans;
    }
};
