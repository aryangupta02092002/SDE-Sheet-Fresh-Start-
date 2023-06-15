//Link: https://leetcode.com/problems/4sum/
/*
arr[a] + arr[b] + arr[c] + arr[d] == target

Input Format: arr[] = [1,0,-1,0,-2,2], target = 0
Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Explanation: We have to find unique quadruplets from the array such that the sum of those elements 
is equal to the target sum given that is 0. The result obtained is such that the sum of the quadruplets yields 0.
*/

//Brute force
/*
Using nested for loops(4) 
TC: O(N^4)
SC: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.
*/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size();
        set<vector<int>> s;

        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                for(int k=j+1; k<sz; k++){
                    for(int l=k+1; l<sz; l++){
                        long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                        
                        if(sum == target){
                            vector<int> tmp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(tmp.begin(), tmp.end());
                            s.insert(tmp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};

//Better sol
/*
3 nested for loops and a set data structure
TC: O(N3*log(M)), where N = size of the array, M = no. of elements in the set.
SC: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size();
        set<vector<int>> s;

        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                set<long long> hash;
                for(int k=j+1; k<sz; k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    int forth = target - sum;

                    if(hash.find(forth) != hash.end()){
                        vector<int> tmp = {nums[i], nums[j], nums[k], forth};
                        sort(tmp.begin(), tmp.end());
                        s.insert(tmp);
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};


//Optimized Solution
/*
Now we will check the sum i.e. nums[i]+nums[j]+nums[k]+nums[l].
If the sum is greater, then we need lesser elements and so we will decrease the value of l.
If the sum is lesser than the target, we need a bigger value and so we will increase the value of k. 
If the sum is equal to the target, we will simply insert the quad i.e. nums[i], nums[j], nums[k], and nums[l] 
into our answer and move the pointers k and l skipping the duplicate elements
(i.e. by checking the adjacent elements while moving the pointers).
Finally, we will have a list of unique quadruplets.

TC: O(N3), where N = size of the array.
SC: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<sz; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1; j<sz; j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }

                //2 pointers
                int k = j+1;
                int l = sz-1;

                while(k < l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> tmp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(tmp);
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }
                        while(k < l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
