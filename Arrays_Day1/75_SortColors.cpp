/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

//Brute force: Any sorting algo
/*
Suppose merge sort, TC: O(N LogN); SC: O(N)
*/

//Better
/*
Taking 3 variables to store the count of number of 0,1,2, then will manually overwrite the array with the frequency of 0,1 and 2

cnt0=0, cnt1=0, cnt2=0
for(i=0 -> size){
  if(a[i] == 0) cnt0++
  else if(a[i] == 1) cnt1++;
  else if(a[i] == 2) cnt2++;
}
for(int i=0 -> cnt0){
  a[i] = 0;
}
for(int i=cnt0 -> cnt0 + cnt1){
  a[i] = 1;
}
for(int i=cnt0 + cnt1 -> size){
  a[i] = 2;
}
TC: O(N) + O(N) ~ O(2N);   SC: O(1)
*/

//Optimal Solution
/*
Dutch National Flag Algorithm
TC: O(N);    SC: O(1)
*/
void sortColors(vector<int> &nums){
  int low = 0, mid = 0, high = nums.size()-1;
  while(mid <= high){
    if(nums[mid] == 0){
      swap(nums[mid], nums[low]);
      mid++;
      low++;
    }
    else if(nums[mid] == 1){
      mid++;
    }
    else{
      swap(nums[mid], nums[high]);
      high--;
    }
  }
}
