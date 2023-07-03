//Link: https://leetcode.com/problems/permutations/
/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/


/*
BRUTE FORCE
Run a for loop starting from 0 to nums.size() – 1. Check if the frequency of i is unmarked, if it is unmarked then it means 
it has not been picked and then we pick. And make sure it is marked as picked.
Call the recursion with the parameters to pick the other elements when we come back from the recursion make sure you throw 
that element out. And unmark that element in the map.
TC: O(N! x N)
SC: O(N)
*/
class Solution {
public:
    void helper(vector<int> &tmp, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
        if(tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                tmp.push_back(nums[i]);
                freq[i] = 1;
                helper(tmp, nums, ans, freq);
                freq[i] = 0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++){
            freq[i] = 0;
        }
        helper(tmp, nums, ans, freq);
        return ans;
    }
};

/*
//OPTIMIZED SOL
We have given the nums array, so we will declare an ans vector of vector that will store all the permutations.
Call a recursive function that starts with zero, nums array, and ans vector.
Declare a map and initialize it to zero and call the recursive function

Base condition:
Whenever the index reaches the end take the nums array and put it in ans vector and return.

Recursion:
Go from index to n – 1 and swap once the swap has been done call recursion for the next state. After coming back from the 
recursion make sure you re-swap it because, for the next element, the swap will not take place.
TC: O(N! X N)
SC: O(1)
*/
class Solution {
public:
    void helper(int idx, vector<int> &nums, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            helper(idx+1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};
