//Link: https://bit.ly/3rj7Ib1
/*
Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. 
If the ‘nth root is not an integer, return -1.
Example 1:
Input Format: N = 3, M = 27
Result: 3
Explanation: The cube root of 27 is equal to 3.

Example 2:
Input Format: N = 4, M = 69
Result: -1
Explanation: The 4th root of 69 does not exist. So, the answer is -1.
*/

//Brute force (Linear Search)
/*
Algorithm:
- We will first run a loop(say i) from 1 to m.
- Inside the loop we will check the following:
- If func(x, n) == m: This means x is the number we are looking for. So, we will return x from this step.
- If func(x, n) > m: This means we have got a bigger number than our answer and until now we have not found any number 
  that can be our answer. In this case, our answer does not exist and we will break out from this step and return -1.

TC: O(M)
SC: O(1)
*/
long long helper(int b, int exp){
  long long ans = 1;
  long long base = b;
  while(exp > 0){
    if(exp % 2){
      exp--;
      ans = ans * base;
    }
    else{
      exp /= 2;
      base = base * base;
    }
  }
  return ans;
}
int NthRoot(int n, int m) {
  // Write your code here.
  for(int i=1; i<=m; i++){
    long long val = helper(i, n);
    if(val == m * 1ll){
      return i;
    }
    else if(val > m * 1ll){
      break;
    }
  }
  return -1;
}


//Optimized Sol (Binary Search)
/*
Algorithm:

- Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 1 and the high will point to m.
- Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
      mid = (low+high) // 2 ( ‘//’ refers to integer division)
- Eliminate the halves accordingly: 
    - If func(n, m, mid) == 1: On satisfying this condition, we can conclude that the number ‘mid’ is our answer. 
      So, we will return to ‘mid’.
    - If func(n, m, mid) == 0: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer.
      So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
    - If func(n, m, mid) == 2: the value mid is larger than the number we want. This means the numbers greater than ‘mid’ will not
      be our answers and the right half of ‘mid’ consists of such numbers. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
- Finally,  if we are outside the loop, this means no answer exists. So, we will return -1.
The steps from 2-3 will be inside a loop and the loop will continue until low crosses high.

TC: O(LogN)
SC: O(1)
*/
int helper(int mid, int n, int m){
  long long ans = 1;
  for(int i=1; i<=n; i++){
    ans = ans * mid;
    if(ans > m){
      return 2;
    }
  }
  if(ans == m){
    return 1;
  }
  return 0;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1, high = m;
  while(low <= high){
    int mid = low + (high-low)/2;
    int midN = helper(mid, n, m);

    if(midN == 1){
      return mid;
    }
    else if(midN == 0){
      low = mid+1;
    }
    else{
      high = mid-1;
    }
  }
  return -1;
}
