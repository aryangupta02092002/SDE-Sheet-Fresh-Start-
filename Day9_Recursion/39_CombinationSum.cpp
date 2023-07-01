//Link: https://leetcode.com/problems/combination-sum/description/
/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

/*
Whenever the problem is related to picking up elements from an array to form a combination, start thinking about
the “pick and non-pick” approach.
Initially, the index will be 0, target as given and the data structure(vector or list) will be empty

Now there are 2 options viz to pick or not pick the current index element.

If you pick the element, again come back at the same index as multiple occurrences of the same element is possible so 
the target reduces to target – arr[index] (where target -arr[index]>=0)and also insert the current element into the data structure.

If you decide not to pick the current element, move on to the next index and the target value stays as it is. 
Also, the current element is not inserted into the data structure.

While backtracking makes sure to pop the last element as shown in the recursion tree below.

Keep on repeating this process while index < size of the array for a particular recursion call.

You can also stop the recursion when the target value is 0, but here a generalized version without adding too many conditions is considered.

Using this approach, we can get all the combinations.
If index== size of array and  target == 0 include the combination in our answer
TC: O(2^t * k) where t is the target, k is the average length

Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: 
pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. 
(to put length k data structure into another data structure)
Why not (2^n) but (2^t) (where n is the size of an array)?

Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

SC: O(k*x), k is the average length and x is the no. of combinations
*/

class Solution {
public:
    void helper(int idx, int tar, vector<int> &cand, vector<vector<int>> &ans, vector<int> &tmp){
        if(idx == cand.size()){
            if(tar == 0){
                ans.push_back(tmp);
            }
            return;
        }
        if(cand[idx] <= tar){
            tmp.push_back(cand[idx]);
            helper(idx, tar - cand[idx], cand, ans, tmp);
            tmp.pop_back();
        }
        helper(idx+1, tar, cand, ans, tmp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(0, target, candidates, ans, tmp);
        return ans;
    }
};
