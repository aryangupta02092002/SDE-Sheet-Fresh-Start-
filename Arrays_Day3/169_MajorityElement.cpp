//Link: https://leetcode.com/problems/majority-element/
/*
Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}
Result: 2
Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.
*/

//Brute Force
/*
Two nested for loops, count whenever two elements are same.
TC: O(N^2);     SC: O(1)
*/
int majorityElement(vector<int>& nums) {
	// Write your code here.
  int n = nums.size();
	for(int i=0; i<n; i++){
		int count = 0;
		for(int j=0; j<n; j++){
			if(arr[i] == arr[j]){
				count++;
			}
		}
		if(count > n/2){
			return arr[i];
		}
	}
	return -1;
}



//Better solution
/*
Using hashmap
TC: O(N*LogN) + O(N);         SC: O(N)
*/
int majorityElement(vector<int>& nums) {
	// Write your code here.
  int n = nums.size();
	map<int, int> m;

	for(int i=0; i<n; i++){
		m[arr[i]]++;
	}
	for(auto it=m.begin(); it!=m.end(); it++){
		if(it->second > n/2){
			return it->first;
		}
	}
	return -1;
}



//Optimized
/*
Using Moore's Algorithm
So when we traverse through the array we try to keep track of the count of elements 
and the element itself for which we are tracking the count. 
After traversing the whole array, we will check the element stored in the variable. 
If the question states that the array must contain a majority element, 
the stored element will be that one but if the question does not state so, 
then we need to check if the stored element is the majority element or not. 
If not, then the array does not contain any majority element.

TC: O(N) + O(N);    SC: O(1)
*/
int majorityElement(vector<int>& nums) {
	// Write your code here.
  int n = nums.size();
	int count = 0, element;
	for(int i=0; i<n; i++){
		if(count == 0){
			count = 1;
			element = arr[i];
		}
		else if(element == arr[i]){
			count++;
		}
		else{
			count--;
		}
	}
	count = 0;
	for(int i=0; i<n; i++){
		if(element == arr[i]){
			count++;
		}
	}
	if(count > n/2){
		return element;
	}
	return -1;
}
