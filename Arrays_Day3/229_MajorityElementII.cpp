//Link: https://leetcode.com/problems/majority-element-ii/
/*
Input Format: N = 5, array[] = {1,2,2,3,2}
Result: 2
Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.
Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.
*/

//Brute Force
/*
Using 2 for loops
TC: O(N^2);        SC: O(1) Since the space used for storing ans is so small, that it can be considered as constant
*/
vector<int> majorityElement(vector<int> &arr) {
	// Write your code here.
  int n = arr.size();
  vector<int> ans;
	for(int i=0; i<n; i++){
		int count = 0;
		for(int j=0; j<n; j++){
			if(arr[i] == arr[j]){
				count++;
			}
		}
		if(count > n/3){
			ans.push_back(arr[i]);
		}
	}
	return ans;
}



//Better
/*
Using hashing
TC: O(N*LogN);       SC: O(N)
*/
vector<int> majorityElement(vector<int> &arr) {
	// Write your code here.
  int n = arr.size();
  vector<int> ans;
	map<int, int> m;

	for(int i=0; i<n; i++){
		m[arr[i]]++;
	}
	for(auto it=m.begin(); it!=m.end(); it++){
		if(it->second > n/3){
			ans.push_back(it->first);
		}
	}
	return ans;
}



//Optimized
/*
Using Moore's Voting Algorithm
If the array contains the majority of elements, their occurrence must be greater than the floor(N/3). 
Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. 
So when we traverse through the array we try to keep track of the counts of elements and the elements 
themselves for which we are tracking the counts. 
After traversing the whole array, we will check the elements stored in the variables. 
Then we need to check if the stored elements are the majority elements or not by manually checking their counts.
TC: O(N) + O(N);         SC: O(1)
*/
vector<int> majorityElement(vector<int> &arr)
{
    // Write your code here.
    int ele1 = -1, ele2 = -1;
    int count1 = 0, count2 = 0;
    for(int i=0; i<arr.size(); i++){
        if(ele1 == arr[i]){
            count1++;
        }
        else if(ele2 == arr[i]){
            count2++;
        }
        else if(count1 == 0){
            ele1 = arr[i];
            count1++;
        }
        else if(count2 == 0){
            ele2 = arr[i];
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for(int i=0; i<arr.size(); i++){
        if(ele1 == arr[i]){
            count1++;
        }
        else if(ele2 == arr[i]){
            count2++;
        }
    }

    vector<int> ans;
    if(count1 > arr.size()/3){
        ans.push_back(ele1);
    }
    if(count2 > arr.size()/3){
        ans.push_back(ele2);
    }
    return ans;

}
