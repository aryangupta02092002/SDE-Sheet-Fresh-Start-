//Link: https://bit.ly/3nquVHj
/*
Example 1:
Input: V = 70
Output: 2
Explaination: We need a 50 Rs note and a 20 Rs note.
*/

/*
TC: O(amount); all the denomination will be taken into consideration, so may be it counts 1 multiple time for worst case
SC: O(1)
*/
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;

    int count = 0;
    for(int i=n-1; i>=0; i--){
        while(coins[i] <= amount){
            amount -= coins[i];
            count++;
        }
    }
    return count;
}
