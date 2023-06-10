/*
TC: O(N);  SC: O(1)
*/
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mn = prices[0];
    int mxProfit = 0;
    int sz = prices.size();

    for(int i=1; i<sz; i++){
        int cost = prices[i] - mn;
        mxProfit = max(mxProfit, cost);
        mn = min(mn, prices[i]);
    }
    return mxProfit;
}
