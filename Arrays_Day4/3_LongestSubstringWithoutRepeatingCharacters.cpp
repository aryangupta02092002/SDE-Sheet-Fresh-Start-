//Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/


//Brute force
/*
TC: O(N^2)
SC: O(N)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.size()==0)
            return 0;
        int maxans = INT_MIN;
        for (int i = 0; i < str.length(); i++) 
        {
            unordered_set < int > set;
            for (int j = i; j < str.length(); j++){
                if (set.find(str[j]) != set.end()){
                    maxans = max(maxans, j - i);
                    break;
                }
                set.insert(str[j]);
            }
        }
        return maxans;
    }
};


//Optimized
/*
TC: O(N)
SC: O(256)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1;
        vector<int> dict(256, -1);
        int ans = 0;

        for(int i=0; i<s.size(); i++){
            if(dict[s[i]] > start){
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            ans = max(ans, i-start);
        }
        return ans;
    }
};
