//Problem link: https://bit.ly/3Gs6wZu
/*
Input Format:  array[] = {3,1,2,5,3}
Result: {3,4}
*/

//Brute Force
/*
TC: O(N^2);     SC: O(1)
*/
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int repeating = -1, missing = -1;

    //Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        //Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}


//Better Solution 1
/*
Sorting the array, then finding the repeating number first and then the missing using count variable to count the 
occurences
TC: O(NLogN) + O(N) + O(N);    SC: const
*/
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int *ans = new int[2];
    sort(arr.begin(), arr.end());
    int count = 1;
    int rep = -1;
    for(int i=0; i<n-1; i++){
        if(arr[i] == arr[i+1]){
            rep = arr[i];
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i] == count){
            count++;
        }
    }
    
    return {count, rep};
}

//Better Solution 2
/*
Using hash to store values
TC: O(2N);    SC: O(N)
*/
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int hash[n + 1] = {0}; // hash array

    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) 
            repeating = i;
        else if (hash[i] == 0) 
            missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {missing, repeating};
}


//Optimised
/*
Using maths or basically arithmetic expressions
TC: O(N);     SC: O(1)
*/
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    long long sum = (n * (n+1))/2;
    long long sum2 = (n * (n+1) * (2*n+1))/6;

    long long s = 0, s2 = 0;
    for(int i=0; i<n; i++){
        s += arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = s - sum;
    long long val2 = s2 - sum2;

    val2 = val2/val1;

    long long x = (val1 + val2)/2;
    long long y = x - val1;
    
    return {(int)y, (int)x};
}
