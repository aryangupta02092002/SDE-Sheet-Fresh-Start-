//Link: https://leetcode.com/problems/two-sum/
/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

//Brute force
/*
Using nested for loops, where we will initialize i at a particular index and j will proceed from i+1
TC: O(N^2)
SC: O(1)
*/
vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}

//Optimized
/*
Using hashmap, to check and find the desired output
TC: O(N*LogN), as map used which takes LogN complexity, whereas if unordered_map would have been used then the TC would be O(N^2)
as unordered_map takes O(N) to find an element
SC: O(N)
*/
vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(target - nums[i]) != m.end()) {
            return {m[target - nums[i], i};
        }
        m[nums[i]] = i;
    }
    return { -1, -1};
}
                      

//More Optimized
/*
Two pointers approach
TC: O(N) + O(N*logN)
SC: O(1)
*/
string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
