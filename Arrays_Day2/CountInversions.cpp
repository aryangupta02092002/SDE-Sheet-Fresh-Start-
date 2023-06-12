//Link: https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=0
/*
i. arr[i] > arr[j]
ii. i < j

Input Format: N = 5, array[] = {5,4,3,2,1}
Result: 10
*/

//Brute force
/*
Index i must be smaller than index j. So, we will fix i at one index at a time through a loop, 
and with another loop, we will check(the condition a[i] > a[j]) 
the elements from index i+1 to N-1  if they can form a pair with a[i].
TC: O(N^2);      SC: O(1)
*/
long long getInversions(long long *arr, int n){
    // Write your code here.
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}



//Optimized
/*
Using merge sort
n order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the merge().
While comparing a[left] and a[right] in the 3rd step of merge(), if a[left] > a[right], we will simply add this line:
cnt += mid-left+1 (mid+1 = size of the left half)
Now, we will return this cnt from merge() to mergeSort(). 
Inside mergeSort(), we will keep another counter variable that will store the final answer. 
With this cnt, we will add the answer returned from mergeSort() of the left half,
mergeSort() of the right half, and merge().
Finally, we will return this cnt, as our answer from mergeSort().

TC: O(NLogN);         SC: O(N)
*/
int merge(long long *arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    int cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(long long *arr, int low, int high) {
    int cnt = 0;
    if (low >= high) 
        return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, 0, n - 1);
}
