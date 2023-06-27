//Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
/*
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

//Brute force
/*
Hashing
Using set data structure to store all the elements and then return the repeating one
TC: O(n*log(n))+O(n)
SC: O(n)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int sz = s.size();
        int j = 0;

        for(int x : s){
            nums[j++] = x;
        }
        return j;
    }
};


//Optimized sol
/*
Two Pointers
Take a variable i as 0;
Use a for loop by using a variable ‘j’ from 1 to length of the array.
If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
After completion of the loop return i+1, i.e size of the array of unique elements.
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j=1; j<nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
