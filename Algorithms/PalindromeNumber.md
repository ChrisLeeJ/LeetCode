# [Palindrome Number](https://leetcode.com/problems/palindrome-number/#/description)

Determine whether an integer is a palindrome. Do this without extra space.

## 思路

判断 `x%10` 和 `x/10` 是否相等
不相等 则 判断 `x%10*10+x%100-x%10` 和 `x/100` 得到的数是否相等
...
用递归来实现

注意点：21120这样的案例如果直接进入递归会变成2112， 成为回文串，所以 `x%10==0` 的直接返回false即可

## code

```
class Solution {
public:
    bool isPalindrome(int x) {
        
        return ( x >= 0 && x <= 9 ) ? true : ( (x % 10 == 0 || x < 0) ? false : judgeBool(x, 0));
    }
    
    bool judgeBool(int x, int y){
        if (x / 10 == y * 10 + x % 10 || (x / 10 == y))
            return true;
        else if (x / 10 == 0)
            return false;
        else if (x  != y)
            return judgeBool(x / 10, y * 10 + x % 10);
    }
};
```