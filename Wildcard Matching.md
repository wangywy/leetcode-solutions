# Wildcard Matching
Implement regular expression matching with support for `'?'` and `'*'`.

> '?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

> The matching should cover the entire input string (not partial).

> The function prototype should be:
bool isMatch(const char *s, const char *p)

> Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

分析：这道题按照[Regular Expression Matching](https://oj.leetcode.com/problems/regular-expression-matching/)的思路来解决，递归实现的代码如下：
```
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        if (*p == '*') {
            for (int i = 0; i < strlen(s); i++) {
                if (isMatch(s+i+1, p+1)) {
                    return true;
                }
            }
            return isMatch(s, p+1);
        }
        return *s != '\0' && (*p == '?' || *p == *s) && isMatch(s+1, p+1);
    }
};
```
但是上面这种实现，当p串中含有大量`'*'`时，会进行大量的递归调用，提交时会TLE。不难看出，递归方法的时间复杂度高达O(n! \* m!)，所以必须想办法降低复杂度。
造成复杂度非常高的原因便是符号`'*'`，由于该符号可以匹配任意长度的序列，所以在遇到该符号时我们不得不将所有可能长度的序列都匹配一遍。尤其是当存在连续`*`时，会进行很多重复的匹配。解决这个问题的办法是将连续的`'*'`当作一个单独的`'*'`，这样可以大大减少需要匹配的次数。
具体做法是，当p中遇到`'*'`时，记录下此时s串正在匹配的位置，然后找到p串中下一个不为`'*'`的位置（即跳过连续的\*），记录下此位置并从该位置起与s串向后进行匹配，如果在这过程中遇到不匹配的情况，就将p指针移动到刚才记录下的那个位置，而s指针移动到之前记录的那个位置的后一个位置（相当于\*匹配的序列长度加1，初始长度为0），s和p再重新开始匹配。
代码如下：
```
class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    const char *str, *ptr;
    bool stared = false;
    for (str = s, ptr = p; *str != '\0';) {
      switch (*ptr) {
        case '?': {
          str++;ptr++;
          break;
        }
        case '*': {
          stared = true;
          // 记录遇到*时的位置
          s = str; p = ptr;
          while (*p == '*') p++;
          if (!p) return true;
          ptr = p;  // 移动到连续*之后的第一个非*字符
          // str指针并未变化，相当于*匹配的序列长度为0
          break;
        }
        default: {
          if (*str != *ptr) {
            if (!stared) return false;
            str = ++s; // *匹配的序列长度加1
            ptr = p;  // 跳到*之后第一个字符开始重新匹配
          } else {
            str++;ptr++;
          }
        }
      }
    }
    while (*ptr == '*') ptr++;
    return *ptr == '\0';
  }
};
```

