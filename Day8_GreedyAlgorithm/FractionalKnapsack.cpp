//Link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
/*
Example
Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.
Output: 240.00

Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. 
Total value = 100 + 60 + 80 = 240.00
*/

/*
The greedy method to maximize our answer will be to pick up the items with higher values. Since it is possible 
to break the items as well we should focus on picking up items having higher value /weight first. To achieve this, 
items should be sorted in decreasing order with respect to their value /weight. Once the items are sorted we can 
iterate. Pick up items with weight lesser than or equal to the current capacity of the knapsack. In the end,
if the weight of an item becomes more than what we can carry, break the item into smaller units. Calculate its
value according to our current capacity and add this new value to our answer.
Let’s understand with an example:-

N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.
The value/weight of item 1 is (100/20) = 5,for item 2 is (60/10) = 6 and for item 3 is (120/30) = 4.

Sorting them in decreasing order of value/weight we have 
60, 100, 120
10, 20, 30

Initially capacity of bag(W)  = 50, value = 0
Item 1 has a weight of 10, we can pick it up. 
Current weight = 50 – 10 = 40 ,Current value = 60.00
Item 2  has a weight of 20 , we can pick it up. 
Current weight = 40 – 20 = 20 ,Current value = 60.00 + 100.00 = 160.00
Item 3 has a weight of 30 , but current knapsack capacity is 20.Only a fraction of it is chosen.
Current weight = 20 – 20 = 0 ,Final value = 160.00 + (120/30 )*20 = 240.00

TC: O(n log n + n)
SC: O(1)
*/

bool static comparison(Item a, Item b){
        double s = (double)a.value / (double)a.weight;
        double t = (double)b.value / (double)b.weight;
        return s > t;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, comparison);
        int currWei = 0;
        double finalVal = 0.0;
        
        for(int i=0; i<n; i++){
            if(currWei + arr[i].weight <= W){
                currWei += arr[i].weight;
                finalVal += arr[i].value;
            }
            else{
                int rem = W - currWei;
                finalVal += (arr[i].value / (double)arr[i].weight) * (double)rem;
                break;
            }
        }
        return finalVal;
    }
