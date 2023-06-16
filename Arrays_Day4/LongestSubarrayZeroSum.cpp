//Link: https://bit.ly/31UHoeM

/*
Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result: 5
Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!
*/

//Brute force:
/*
So our initial approach could be to consider all possible subarrays of the given array and 
check for the subarrays that sum to zero. Among these valid subarrays (a sum equal to zero)
we’ll return the length of the largest subarray by maintaining a variable, say max. 
TC: O(N^2)
SC: O(1)
*/
int LongestSubsetWithZeroSum(vector < int > arr) {
  int mx = 0;
  for(int i=0; i<arr.size(); i++){
    int sum = 0;
    for(int j=i; j<arr.size(); j++){
      sum += arr[j];
      if(sum == 0){
        mx = max(mx, j-i+1);
      }
    }
  }
  return mx;
}



//Optimized sol
/*
1. Initially sum = 0, max = 0
2. HashMap<Integer, Integer> h = [ ];
3.  => i=0 -> sum=1, sum!=0 so check in the hashmap if we’ve seen a subarray with this sum before,
in our case hashmap does not contain sum (1), so we add (sum, i) to the hashmap.
TC: O(N)
SC: O(N)
*/
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  unordered_map<int, int> u;
  int mx = 0, sum = 0;
  
  for(int i=0; i<arr.size(); i++){
    sum += arr[i];
    if(sum == 0){
      mx = i+1;
    }
    else{
      if(u.find(sum) != u.end()){
        mx = max(mx, i - u[sum]);
      }
      else{
        u[sum] = i;
      }
    }
  }
  return mx;

}
