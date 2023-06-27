//Link: https://leetcode.com/problems/max-consecutive-ones/description/
/*
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

/*
If  the value at the current index is equal to 1 we increase the value of count by one. After updating  the count 
variable if it becomes more than the max_count  update the max_count.
If the value at the current index is equal to zero we make the variable count as 0 since there are no more consecutive ones.
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, mx = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }
            else{
                count = 0;
            }
            mx = max(mx, count);
        }
        return mx;
    }
};
