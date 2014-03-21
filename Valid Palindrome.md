Valid Palindrome
===========
---

> Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

> For example,

> `A man, a plan, a canal: Panama"` is a palindrome.  
`"race a car"` is not a palindrome.

> **Note:**  
> Have you consider that the string might be empty? This is a good question to ask during an interview.

> For the purpose of this problem, we define empty string as valid palindrome.

此题较为简单，解题思路是从字符串开始和结尾处分别设置两个指针，一个向后遍历，一个向前遍历，当着两个指针指向的字符都是有效字符（即字母和数字）时，比较量指针所指字母是否相同；如果其中任何一个指针不是有效字符，就要相应的向前或向后移动，直到有效为止。

代码如下：

```cpp
class Solution {
public:
    bool isValid(char& c) {
        if ('A' <= c && c <='Z') {
            c += ('a' - 'A');
            return true;
        } else if ('a' <= c && c <= 'z') {
            return true;
        } else if ('0' <= c && c <= '9') {
            return true;
        } else {
            return false;
        }
    }

     bool isPalindrome(string s) {
        int len = s.size();
        if (len == 0) return true;
        int l = 0, h = len - 1;
        while (l < h) {
            if (!isValid(s[l])) {
                l++;
            } else if (!isValid(s[h])) {
                h--;
            } else if (s[l++] != s[h--]) {
                return false;
            }
        }
        return true;
    }
};
```