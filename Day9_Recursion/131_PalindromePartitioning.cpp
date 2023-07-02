//Link: https://leetcode.com/problems/palindrome-partitioning/description/
/*
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/
/*
STEP 1: We consider substrings starting from the 0th index.[0,0] is a palindrome, so partition right after the 0th index.
[0,1] is another palindrome, make a partition after 1st index. Beyond this point, other substrings starting from index 0 
are “aab”  and “aabb”. These are not palindromes, hence no more. partitions are possible. 
The strings remaining on the right side of the partition are used as input to make recursive calls.

STEP 2: Consider the recursive call on the left(refer to image)  where “abb” is the input.[1,1] is a palindrome,
make a partition after it.[1,2] and [1,3] are not palindromes.

STEP 3: Here “bb” is the input.[2,2] as well as [2,3]  are palindromes. Make one partition after the 2nd index and 
one after the 3rd index The entire string is exhausted after the 3rd index, so the right recursion ends here. 
Palindromes generated from the right recursion are inserted in our answer.

Our answer at this point :[ [“a”,” a”,” bb”] ]

The left recursion will continue with  “b” as its input.[3,3] is a palindrome so one last partition for the left recursion 
is made after the 3rd index. Insert the palindromes.
ans = [  [“a”,”a”,”bb”], [ “a”,”a”,”b”,”b”] ] 

STEP 4: After the list of palindromic substrings are returned from the left recursive call, continue the same process for 
the call on the right that was left to recur. The right recursion is having “bb” as input, something we have already 
encountered in step 3. Hence we will repeat the same task which was done in step 3 onwards.

Final answer : [  [“a”,”a”,”bb”], [ “a”,”a”,”b”,”b”] ,[“aa”,”b”,”b”], [“aa”,”bb”] ]

TC: O( (2^n) *k*(n/2) )
Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. 
O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

SC: O(k * x)
*/
class Solution {
public:
    bool isPalin(int i, int j, string s){
        while(i <= j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    void helper(int idx, string s, vector<vector<string>> &ans, vector<string> &tmp){
        if(idx == s.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            if(isPalin(idx, i, s)){
                tmp.push_back(s.substr(idx, i-idx+1));
                helper(i+1, s, ans, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        helper(0, s, ans, tmp);
        return ans;
    }
};
