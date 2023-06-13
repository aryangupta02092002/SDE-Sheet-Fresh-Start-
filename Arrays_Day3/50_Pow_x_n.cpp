//Link: https://leetcode.com/problems/powx-n/
/*
Input: x = 2.00000, n = 10
Output: 1024.00000
Explanation: You need to calculate 2.00000 raised to 10 which gives ans 1024.00000
*/
//Note: Check if n is negative, if it is negative divide 1 by the end

//Brute force
/*
Using simple for loop to find the power
TC: O(N)
SC: O(1)
*/
double myPow(double x, int n) {
      double ans = 1.0;
      int tmp = n;
      if(tmp < 0)     
          tmp = tmp * (-1); 
  
      for (int i = 0; i < tmp; i++) {
        ans = ans * x;
      }
      if(n < 0){
          return (double)(1.0)/(double)(ans);
      }
      return ans;
}

//Optimized
/*
Binary exponentiation
TC: O(Log N)
SC: O(1)
*/
double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } 
    else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) 
     ans = (double)(1.0) / (double)(ans);
  return ans;
}

