# Longest Palindromic Substring

Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

**Example:**

```
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
```

**Example:**

```
Input: "cbbd"

Output: "bb"
```

**code**

````
class Solution {
public:
    string longestPalindrome(string s) {
        string L_Palindrome = "";
        for(int center = 0; center < s.length(); ++center) {
            int min_point = center, max_point = center;
            while (s[--min_point] == s[++max_point])
                if (min_point < 0 || max_point >= s.length())
                    break;
            L_Palindrome = (L_Palindrome.length() < (max_point - min_point - 1)) ? s.substr( min_point + 1, max_point - min_point - 1 ) : L_Palindrome;

            min_point = center;
            max_point = center + 1;
            if (s[min_point] == s[max_point])
                while (s[--min_point] == s[++max_point])
                    if (min_point < 0 || max_point >= s.length())
                        break;
            L_Palindrome = (L_Palindrome.length() < (max_point - min_point - 1)) ? s.substr( min_point + 1, max_point - min_point - 1 ) : L_Palindrome;
        }
        return L_Palindrome;
    }
};
````

