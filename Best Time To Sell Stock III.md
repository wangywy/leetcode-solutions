
Best Time To Sell Stock III
=========
> Say you have an array for which the i<sup>th</sup> element is the price of a given stock on day i.

> Design an algorithm to find the maximum profit. You may complete at most two transactions.

> **Note:**
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). 

Best Time To Sell Stock系列的第三题，比前面两题略难一些。题目规定最多只能进行两次交易（买进再卖出算一次交易），并且在手中持有股票时，不能再购买股票，必须先卖掉再买其它股票。因此，我们需要在[1,n]中找到一个i值，使得序列[1...i]的收益加上序列[i...n]的收益值最大。于是很自然地想到，令i=1, 2, 3, ...n，利用Best Time To Sell Stock I中的思路，分别求出i两边的子序列的收益，然后找到使得两边收益和最大的i值，复杂度为O(n<sup>2</sup>)。  
我们可以发现，在由前向后求[1...i]的收益过程中，需要用到[1...i-1]的收益值，因此可以把每一步求得的收益值保存下来，下一次计算时直接查表获得，不再需要重复计算。但是如果我们还是由前向后的求[i...n]的收益值，每次i增大时无法利用到前一次计算的结果。可以看到n的值是不变的，由此可以想到让i从n开始，从后向前的计算[i...n]的收益，这样每次计算[i-1...n]的收益时可以利用前一次求得的[i...n]的结果。需要注意的如果从后向前遍历，那么需要保存的是已经扫描过序列的最大元素值；从前向后遍历时需要记录已扫描序列的最小元素值。   
令lp[i]表示[1...i]序列的最大收益，rp[i]表示[i...n]序列的最大收益，令i从1到n遍历，找到lp[i] + rp[i]的最大值，便是所要求的最大收益。  
代码如下：
```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len < 1) return 0;
        int lp[len], rp[len];
        lp[0] = 0;
        int min = prices[0];
        for (int i = 1; i < len; i++) {
            if (prices[i] - min > lp[i-1]) {
                lp[i] = prices[i] - min;
            } else {
                lp[i] = lp[i-1];
            }
            if (prices[i] < min) min = prices[i];
        }
      
        rp[len-1] = 0;
        int max = prices[len-1];
        for (int i = len-2; i >= 0; i--) {
            if (max - prices[i] > rp[i+1]) {
                rp[i] = max - prices[i];
            } else {
                rp[i] = rp[i+1];
            }
                if (prices[i] > max) max = prices[i];
        }
    
        int profit = 0;
        for (int i = 0; i < len; i++) {
            profit = lp[i] + rp[i] > profit ? lp[i] + rp[i] : profit;
        }
        return profit;
    }
};
```