//Link: https://bit.ly/3I2iPvN
/*
Same as N meetings in one room
Input: Start[] = {1 6 2 4}
       Finish[] =   {2 7 5 8}
Output: 3
*/

/*
TC: O(N) + O(N*LogN) + O(N)
SC: O(N)
*/
#include "algorithm"
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();
    vector<pair<int, pair<int, int>>> v;
    for(int i=0; i<n; i++){
        v.push_back({finish[i], {start[i], i}});
    }

    sort(v.begin(), v.end());
    int count = 1, curr = v[0].first;

    for(int i=1; i<n; i++){
        if(curr <= v[i].second.first){
            curr = v[i].first;
            count++;
        }
    }
    return count;
}
