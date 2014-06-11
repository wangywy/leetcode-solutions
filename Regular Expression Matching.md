#Regular Expression Matching
Implement regular expression matching with support for `'.'` and `'*'`.

> '.' Matches any single character.
'*' Matches zero or more of the preceding element.

> The matching should cover the entire input string (not partial).

> The function prototype should be:
> bool isMatch(const char *s, const char *p)

> Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a\*") → true
isMatch("aa", ".\*") → true
isMatch("ab", ".\*") → true
isMatch("aab", "c\*a\*b") → true

分析：解这道题需要利用递归的性质，若s的某个前缀匹配到p的某个前缀，那么就用s除去前缀后剩下的子串来匹配p剩下的正则式。题目要求是完全（entire）匹配，所以需要从s的开头字符开始匹配，当匹配到p表达式末尾时，若s串也在末尾，那么匹配成功，否则便是匹配失败。匹配过程中可能出现四种情况：

1. p串已经到达了末尾
2. s串以`"单字符*"`的形式开始，字符可以是正常字符也可以是dot。例如`.*`， `a*` 
3. s串以dot开始
4. s串以正常字符开始（除dot和*）

在实现时可以将3、4两种情况合并。

代码如下：
```
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Case 1: 必须同时到末尾才算匹配成功，因为题目要求是entire
        if (*p == '\0') {
            return *s == '\0';
        }
        // Case 2: 以*匹配开始，例如.*, a*(ab*不属于此case)
        if (strlen(p) >= 2 && p[1] == '*') {
            for (int i = 0; i < strlen(s) && (*p == '.' || *p == *(s+i)); i++) {
                // 考察*前面字符重复1...strlen(s)次时是否匹配
                if (isMatch(s+i+1, p+2)) {
                    return true;
                }
            }
            // *前面的字母重复0次。
            return isMatch(s, p+2);
        }
        // Case 3, 4: 以.或者正常字符开始，例如.a, abc
        return (*s != '\0') && (*p == '.' || *p == *s) && isMatch(s+1, p+1);
    }
};
```

