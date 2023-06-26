//Link: https://leetcode.com/problems/3sum/
/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/

//Brute force
/*
3 nested for loops to find 3 elements having sum = 0
TC: O(N^3)
SC: O(3*K) -> K No. of triplets
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int sz = nums.size();

        for(int i=0; i<sz-2; i++){
            for(int j=i+1; j<sz-1; j++){
                for(int k=j+1; k<sz; k++){
                    tmp.clear();
                    if(nums[i] + nums[j] + nums[k] == 0){
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                    }
                    if(tmp.size() != 0){
                        ans.push_back(tmp);
                    }
                }
            }
            
        }
        return ans;
    }
};



//Optimized sol
/*
We could make use of the fact that we just need to return the triplets and thus could possibly sort the array. 
  This would help us use a modified two-pointer approach to this problem.

Eg) Input :  [-1,0,1,2,-1,-4]

After sorting, our array is : [-4,-1,-1,0,1,2]

Notice, that we are fixing the i pointer and then applying the traditional 2 pointer approach to check whether the 
sum of three numbers equals zero. If the sum is less than zero, it indicates our sum is probably too less 
and we need to increment our j pointer to get a larger sum. On the other hand, if our sum is more than zero, 
it indicates our sum is probably too large and we need to decrement the k pointer to reduce the sum and bring it closer to zero.

TC: O(N^2)
SC: O(3 * K) //k is no. of triplets
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int low = i+1, high = nums.size()-1, sum = 0-nums[i];

                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[low]);
                        tmp.push_back(nums[high]);

                        ans.push_back(tmp);

                        while(low < high && nums[low] == nums[low+1]){
                            low++;
                        }
                        while(low < high && nums[high] == nums[high-1]){
                            high--;
                        }
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};
