
Best time To Sell Stock I
=========
> Say you have an array for which the i<sup>th</sup> element is the price of a given stock on day i.

> If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

题目要求计算出只进行一次交易所能获得的最大收益，也就是要找出股票价格序列中的一对值，使得两者的差值最大，并且较小值必须出现在较大值之前。  
用p[n]表示prices[1...n]中的最大差值，即题目中所说的最大收益，如何求解p[n]?  
假设我们已经求得了p[n-1]的值，并且prices[1...n-1]中的最小值为min_price。如果p[n]与min_price的差值大于prices[1...n-1]中求得的最大差值，即p[n-1]，那么prices[1...n]中的最大差值便是prices[n] - min_price；否则，加入prices[n]后并没有使得序列的中差值增大，那么p[n] = p[n-1]。  
由上述分析不难看出，这是一道典型的动态规划题。利用一个长度为n数组profit保存prices[1...n]的最大差值，其中p[i]表示prices[1...i]的最大差值。同时使用一个长度为n的数组min保存prices[1...n]的最小值，min[i]表示prices[1...i]中的最小值，从前向后扫描一遍prices[1...n]，最后得到的p[n]便是所要求得的最大收益值，时间复杂度为O(n)，空间复杂度O(2n)。  
代码如下：

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len  < 2) return 0;
        
        int profit[len];
        int min[len];
        profit[0] = 0;
        min[0]  = prices[0];
        
        for (int i = 1; i < len; i++) {
            if (prices[i] - min[i-1] > profit[i-1]) {
                profit[i]  = prices[i] - min[i-1];
            } else {
                profit[i] = profit[i-1];
            }
            if (prices[i] < min[i-1]) {
                min[i] = prices[i];
            } else {
                min[i] = min[i-1];
            }
            
        }
        return profit[len-1];
    }
};
```
事实上，从上面的代码中可以看出，我们在求profit[i]时只用到了profit[i-1]和min[i-1]，在求min[i]时只用到了min[i-1]，也就是求新问题时只用到了上一步的结果，再往前的结果没有用到，所以不需要使用数组将所有min值和profit值都保存下来，只要保存上一次计算的值即可，改进后的代码如下：  
```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len  < 2) return 0;
        
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            if (prices[i] - min_price > max_profit) {
                max_profit  = prices[i] - min_price;
            }
        }
        return max_profit;
    }
};
```


