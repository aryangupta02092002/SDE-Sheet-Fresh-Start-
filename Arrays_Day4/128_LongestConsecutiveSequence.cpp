//Link: https://leetcode.com/problems/longest-consecutive-sequence/
/*
Input: [100, 200, 1, 3, 2, 4]
Output: 4
Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.
*/

//Brute force
/*
Simply sort the array and find the longest consecutive sequence
TC:O(N * log(N))
SC: O(1)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());

        int ans = 1, curr = 1, prev = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == prev+1){
                curr++;
            }
            else if(nums[i] != prev){
                curr = 1;
            }
            prev = nums[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};


//Optimal sol
/*
Using set data structure
Push all elements in set, and then run a loop and check for any number present which creates a sequence
TC: O(N)
SC: O(N)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        s.insert(nums.begin(), nums.end());

        int ans = 0;

        for(int num : nums){
            if(!s.count(num-1)){
                int curr = num;
                int tmp = 1;

                while(s.count(curr+1)){
                    curr += 1;
                    tmp += 1;
                }

                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
