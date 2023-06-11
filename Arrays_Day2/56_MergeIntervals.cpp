//Brute Force
/*
We are just grouping close intervals by sorting the given array. After that, 
we merge an interval with the other by checking if one can be a part of the other interval.
For this checking, we are first selecting a particular interval using a loop and 
then we are comparing the rest of the intervals using another loop.
TC: O(N*logN) + O(2*N)
SC: O(N*logN)

sort(arr.begin(), arr.end());
for (let i = 0; i < n; i++) { // select an interval:
    int start = arr[i][0];
    int end = arr[i][1];

    //Skip all the merged intervals:
    if (ans.size() && end <= ans[ans.size() - 1][1]) {
      continue;
    }

    //check the rest of the intervals:
    for (int j = i + 1; j < n; j++) {
      if (arr[j][0] <= end) {
        end = max(end, arr[j][1]);
      } else {
        break;
      }
    }
    ans.push_back({start, end});
  }
  return ans;
*/

//Optimized Solution
/*
We kept on merging simultaneously as we were traversing through the array and when 
the element was non-overlapping we simply inserted the element in our answer list.

TC: O(N*logN) + O(N)
SC: O(N)
*/
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0];
    int end = intervals[0][1];
    vector<vector<int>> ans;

    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0] <= end){
            end = max(end, intervals[i][1]);
        }
        else{
            ans.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    ans.push_back({start, end});
    return ans;
}
