String to Integer
===
> Implement `atoi` to convert a string to an integer

要实现C语言库函数`int atoi(const char* str)`，需要考虑的输入情况有：
+ str是空指针或者长度为0， 直接返回0
+ 字符串开始时有一连串的空格
+ 空格之后第一个非空格字符可能是正负号“+”、“-”，如果是其他字母直接返回0
+ 之后是一段连续的数字，末尾可能会带有字母，忽略掉这些字母
+ 转化后的值可能大于INT\_MAX或者小于INT\_MIN，这种情况下直接返回INT\_MAX或INT\_MIN

代码如下：
```
class Solution {
public:
    int atoi(const char *str) {
        int len;
        if (str == NULL || (len = strlen(str)) == 0) return 0;

        int i = 0, j = 0;
        if (len == 0) return 0;
        int sign = 1;
  
        // 处理开始处空格
        while (str[i] != '\0' && str[i] == ' ') i++;
        if (str[i] == '\0') return 0;
  
        // 处理正负号
        if (str[i] != '\0' && !isdigit(str[i])) {
            if (str[i] == '+') {
                sign = 1;
            } else if (str[i] == '-') {
              sign = -1;
            } else {
              return 0;
            }
            i++;
        }
 
        int res = 0;
        // 处理中间数字  
        while (str[i] != '\0' && isdigit(str[i])) {
            if (INT_MAX / 10 >= res) {
                res *= 10;
            } else {
              return sign == 1 ? INT_MAX : INT_MIN;
            }
    
            int digit = str[i] - '0';
            if (INT_MAX - digit >= res) {
                res += digit;
            } else {
              return sign == 1 ? INT_MAX : INT_MIN;
            }
            i++;
        }
        return res * sign;
    }
};
```