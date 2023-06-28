//Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
/*
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/

/*
Using extra space or array
TC: O(N) + O(N*LogN) + O(N)
SC: O(N)
*/
int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, pair<int, int>>> v;
        for(int i=0; i<n; i++){
            v.push_back({end[i], {start[i], i}});
        }
        
        sort(v.begin(), v.end());
        int count = 1;
        int curr = v[0].first;
        
        for(int i=1; i<n; i++){
            if(curr < v[i].second.first){
                curr = v[i].first;
                count++;
            }
        }
        return count;
    }

//Using priority queue
/*
TC: O(N) + O(N*LogN) + O(N)
SC: O(N)
*/
int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<n; i++){
            pq.push({end[i], start[i]});
        }
        
        int count = 1;
        int curr = pq.top().first;
        pq.pop();
        while(!pq.empty()){
            auto tmp = pq.top();
            pq.pop();
            
            int e = tmp.first;
            int s = tmp.second;
            
            if(s > curr){
                count++;
                curr = e;
            }
        }
        return count;
    }
