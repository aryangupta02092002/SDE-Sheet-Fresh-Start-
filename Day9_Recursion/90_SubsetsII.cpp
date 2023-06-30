//Link: https://leetcode.com/problems/subsets-ii/description/
/*
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/


//Brute force
/*
At every index, we make a decision whether to pick or not pick the element at that index. This will help us 
in generating all possible combinations but does not take care of the duplicates. Hence we will use a 
set to store all the combinations that will discard the duplicates.
TC: O( 2^n *(k log (x) )). 2^n for generating every subset and k* log( x)  to insert every combination of 
average length k in a set of size x. After this, we have to convert the set of combinations back into a list
of list /vector of vectors which takes more time.
SC: O(2^n * k) 
*/
class Solution {
public:
    void helper(vector<int> &nums, int idx, vector<int> &tmp, set<vector<int>> &st){
        if(idx == nums.size()){
            sort(tmp.begin(), tmp.end());
            st.insert(tmp);
            return;
        }
        tmp.push_back(nums[idx]);
        helper(nums, idx+1, tmp, st);
        tmp.pop_back();
        helper(nums, idx+1, tmp, st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        set<vector<int>> st;
        helper(nums, 0, tmp, st);
        for(auto it = st.begin(); it != st.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};


/*
Sort the input array.Make a recursive function that takes the input array,the current subset,the current index and 
a list of list/ vector of vectors to contain the answer.
Try to make a subset of size n during the nth recursion call and consider elements from every index while generating the
combinations. Only pick up elements that are appearing for the first time during a recursion call to avoid duplicates.
Once an element is picked up, move to the next index.The recursion will terminate when the end of array 
is reached.While returning backtrack by removing the last element that was inserted.
TC: O(2^n)
SC: O(2^n * K)
*/
class Solution {
public:
    void helper(int idx, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &ans){
        ans.push_back(tmp);
        for(int i=idx; i<nums.size(); i++){
            if(i != idx && nums[i] == nums[i-1]){
                continue;
            }
            tmp.push_back(nums[i]);
            helper(i+1, nums, tmp, ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        helper(0, nums, tmp, ans);
        return ans;
    }
};
