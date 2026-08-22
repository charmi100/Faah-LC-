/*
Problem: Best Time to Buy and Sell Stock

My Approach:
- Try all pairs (buy, sell) → O(n^2).
- Then optimize by tracking minimum price.

Optimized Idea:
- Keep track of minimum price so far.
- At each step calculate profit.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int profit = 0;

        for(int price : prices) {
            minPrice = min(minPrice, price);
            profit = max(profit, price - minPrice);
        }

        return profit;
    }
};