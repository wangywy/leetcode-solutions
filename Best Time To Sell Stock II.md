Best Time To Sell Stock II
=========
> Say you have an array for which the i<sup>th</sup> element is the price of a given stock on day i.

> Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).  

此题与[Best time To Sell Stock I](http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock)一样，要求计算交易所能获得的最大收益，不同之处在于可以进行任意多次交易。因为没有了交易次数的限制，可以查找序列中的连续上升子序列，在子序列开始处买入，在结束处卖出，最后将所有子序列收益相加便是可以获得的最大收益。  
代码如下：
```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len < 2) return 0;
        int i, buy = 0, profit = 0;
        for (i = 1; i < len; i++) {
            if (prices[i] < prices[i-1]) {
                profit += prices[i-1] - prices[buy];
                buy = i;
            }
        }
        profit += prices[len-1] - prices[buy];
        return profit;
    }
};
```