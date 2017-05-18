# [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/#/description)

Implement atoi to convert a string to an integer.

**Hint:** Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

**Notes:** It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

## 分析

*  符号后只能跟数字 跟其他符号 返回0
*  数字后跟其他符号立刻停止返回数字
*  考虑超过INT_MAX和INT_MIN的情况



## code

```
class Solution {
public:
    int myAtoi(string str) {
        bool isPositive = true;
		for (int i = 0; i < str.length(); ++i){
			if (str[i] != ' '){
				switch (str[i]){
				case '+':
					str = str.substr(i + 1, str.length() - i - 1);
					break;
				case '-':
					isPositive = false;
					str = str.substr(i + 1, str.length() - i - 1);
					break;
				default:
					str = str.substr(i, str.length() - i);
					break;
				}
				break;
			}
		}
		if (str[0] < '0' || str[0] > '9')
			return 0;
		int result = 0;
		for (int i = 0; i < str.length(); ++i){
			if (str[i] < '0' || str[i] > '9')
				break;
			if (result * 10 + str[i] - 48 < 0 || result * 10 / 10 != result){
				if (isPositive == true)
					return INT_MAX;
				else
					return INT_MIN;
			}
			result = result * 10 + str[i] - 48;
		}
		return isPositive == true ? result : -result;
    }
};
```

