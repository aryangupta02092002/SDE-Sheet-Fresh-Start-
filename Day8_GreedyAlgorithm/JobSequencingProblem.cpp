//Link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
/*
Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output: 2 60

Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .The 1st job is performed during the second unit of time as its deadline is 4.
Profit = 40 + 20 = 60
*/

/*
Basic Outline of the approach:-

Sort the jobs in descending order of profit. 
If the maximum deadline is x, make an array of size x .Each array index is set to -1 initially as no jobs have been performed yet.
For every job check if it can be performed on its last day.
If possible mark that index with the job id and add the profit to our answer. 
If not possible, loop through the previous indexes until an empty slot is found.

TC:  O(N log N) + O(N*M)
SC: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.
*/

bool static comparison(Job a, Job b){
        return (a.profit > b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comparison);
        int mx = 0;
        
        for(int i=0; i<n; i++){
            mx = max(mx, arr[i].dead);
        }
        
        vector<int> slot(mx+1, -1);
        
        int countJobs = 0, jobProfit = 0;
        
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>0; j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {countJobs, jobProfit};
    }
