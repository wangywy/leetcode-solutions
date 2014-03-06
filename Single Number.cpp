class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n == 0) return -1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= A[i];
        }
        return res;
    }
};

/*
本题用利用了异或位运算的性质
异或运算可以看成是

*/