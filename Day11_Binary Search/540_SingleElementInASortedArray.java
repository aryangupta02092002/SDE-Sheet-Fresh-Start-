//Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

//Hashing
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> u;
        int sz = nums.size();
        for(int i=0; i<sz; i++){
            u[nums[i]]++;
        }
        int ans;
        for(auto i=u.begin(); i!=u.end(); i++){
            if(i->second == 1){
                ans = i->first;
            }
        }
        return ans;
    }
};

//Binary Search
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int low = 0, high = nums.length-2;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == nums[mid^1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return nums[low];
    }
}
