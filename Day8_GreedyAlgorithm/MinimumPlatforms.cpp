//Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
/*
Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
*/

//Brute force
/*
Using two nested for loops
Intuition: Take each interval of arrival and departure one by one and count the number of overlapping time intervals. 
This can easily be done using nested for-loops. Maintain the maximum value of the count during the process and 
return the maximum value at the end.
TC: O(N^2)
SC: O(1)
*/


//Efficient
/*
Using sorting
Intuition: At first we need to sort both arrays. When the events will be sorted, it will be easy to track the count of 
trains that have arrived but not departed yet. The total platforms needed at one time can be found by taking
the difference between arrivals and departures at that time and the maximum value of all times will be the final answer.

Approach:  At first we need to sort both arrays. When the events will be sorted, it will be easy to track the 
count of trains that have arrived but not departed yet. The total platforms needed at one time can be 
found by taking the difference of arrivals and departures at that time and the maximum value of all times 
will be the final answer. If(arr[i]<=dep[j]) means if arrival time is less than or equal to the departure 
time then- we need one more platform. So increment count as well as increment i. 
If(arr[i]>dep[j]) means the arrival time is more than the departure time then- we have one extra platform which we can reduce. 
So decrement count but increment j. Update the ans with max(ans, count) after each iteration of the while loop.
TC: O(N*LogN)
SC: O(1)
*/
int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int ans = 1;
    	int count = 1;
    	int i=1, j=0;
    	
    	while(i<n && j<n){
    	    if(arr[i] <= dep[j]){
    	        count++;
    	        i++;
    	    }
    	    else{
    	        count--;
    	        j++;
    	    }
    	    ans = max(ans, count);
    	}
    	return ans;
    }
