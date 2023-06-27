//Link: https://leetcode.com/problems/trapping-rain-water/
/*
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
*/

//Brute force
/*
For each index, we have to find the amount of water that can be stored and we have to sum it up.
If we observe carefully the amount the water stored at a particular index is the minimum of maximum
elevation to the left and right of the index minus the elevation at that index.
TC: O(N*N)
SC: O(1)
TLE
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int trapped = 0;

        for(int i=0; i<sz; i++){
            int j = i;
            int leftMax = 0, rightMax = 0;

            while(j >= 0){
                leftMax = max(leftMax, height[j]);
                j--;
            }
            j = i;
            while(j < sz){
                rightMax = max(rightMax, height[j]);
                j++;
            }
            trapped += min(leftMax, rightMax) - height[i];
        }
        return trapped;
    }
};


//Better sol
/*
Intuition: We are taking O(N) for computing leftMax and rightMax at each index. The complexity can be 
boiled down to O(1) if we precompute the leftMax and rightMax at each index.

Approach: Take 2 array prefix and suffix array and precompute the leftMax and rightMax for each index beforehand. 
Then use the formula min(prefix[I], suffix[i])-arr[i] to compute water trapped at each index.
TC: O(3 * N)
SC: O(N) + O(N)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int pref[sz], suff[sz];
        pref[0] = height[0];

        for(int i=1; i<sz; i++){
            pref[i] = max(pref[i-1], height[i]);
        }

        suff[sz-1] = height[sz-1];
        for(int i=sz-2; i>=0; i--){
            suff[i] = max(suff[i+1], height[i]);
        }

        int trapped = 0;
        for(int i=0; i<sz; i++){
            trapped += min(pref[i], suff[i]) - height[i];
        }
        return trapped;
    }
};


//Optimized Sol
/*
2 POINTERS
Take 2 pointers l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively. 
Take two variables leftMax and rightMax and initialize them to 0. If height[l] is less than or equal to height[r]
then if leftMax is less than height[l] update leftMax to height[l] else add leftMax-height[l] to your final answer 
and move the l pointer to the right i.e l++. If height[r] is less than height[l], then now we are dealing with the right block.
If height[r] is greater than rightMax, then update rightMax to height[r] else add rightMax-height[r] to the final answer. 
Now move r to the left. Repeat these steps till l and r crosses each other.

TC: O(N)
SC: O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int left = 0, right = sz-1;
        int ans = 0;
        int maxLeft = 0, maxRight = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= maxLeft){
                    maxLeft = height[left];
                }
                else{
                    ans += maxLeft - height[left];
                }
                left++;
            }
            else{
                if(height[right] >= maxRight){
                    maxRight = height[right];
                }
                else{
                    ans += maxRight - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
