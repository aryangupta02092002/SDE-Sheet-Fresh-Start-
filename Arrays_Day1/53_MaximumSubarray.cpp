/*
[-2,1,-3,4,-1,2,1,-5,4]
-> 6  >>>>[4,-1,2,1] has the largest sum 6.
*/

//Brute force:
/*
Using 3 for loops to check the maximum sum by comparing sum continuously.
mx = INT_MIN;
for(i=0 -> n){
  for(j=0 -> n){
    sum = 0
    for(k=i -> j){
      sum += arr[i];
    }
    mx = max(sum, mx)
  }
}
TC: ~ O(N^3);  SC: const
*/

//Better Solution
/*
mx = INT_MIN;
for(i=0 -> n){
  sum = 0
  for(j=0 -> n){
    sum += arr[i]
    mx = max(sum, mx)
  }
}

TC: O(N^2);   SC: const
*/


//Optimal Solution
/*
Whenever the sum reaches negative, make it zero, so that n o unneccessary addition of elements will be done
Secondly, check the maximum between sum and max variable after addition

TC: O(N)
*/

int maxSubArray(vector<int>& nums) {
   int mx = INT_MIN;
   int sum = 0;
   for(int i=0; i<nums.size(); i++){
     sum += nums[i];
     mx = max(mx, sum);
     if(sum < 0){
       sum = 0;
     }
   }
   return mx;
}


//For printing the maximum subarray
int maxSubArray(vector<int>& nums) {
   int mx = INT_MIN;
   int start = 0, ansStart = -1, ansStart = -1;
   int sum = 0;
   for(int i=0; i<nums.size(); i++){
     if(sum == 0){
       start = i;
     }
     sum += nums[i];
     if(mx > sum){
       mx = sum;
       ansStart = start;
       ansEnd = i;
     }
     if(sum < 0){
       sum = 0;
     }
   }
   return mx;
}
