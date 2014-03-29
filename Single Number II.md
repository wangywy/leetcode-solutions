另外，本题还有一种更为通用的解法，那就是将数组先按照非递减序排序，然后比较相邻两个元素是否相同，找到不相同的那个数便是所要的结果。代码如下：
  
	class Solution {
	public:
	    int singleNumber(int A[], int n) {	        
	        sort(A, A+n);
	        int i, j = 1;
	        for (i = 0; i < n - 1; i++) {
	            if (A[i] == A[i+1]) {
	                j++;
	            } else {
	                if (j < 2) return A[i];
	                j = 1;
	            }
	        }
	        return A[n-1];
	    }
	};

如果题目不是出现两次，而是出现n次，只有一个数出现了x次，