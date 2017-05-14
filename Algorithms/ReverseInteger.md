# [Reverse Integer](https://leetcode.com/problems/reverse-integer/#/description)

Reverse digits of an integer.

**Example:**

```
Example1: x = 123, return 321
Example2: x = -123, return -321
```

## code

````
class Solution {
public:
    int reverse(int x) {
        bool isPositive = false;
		int result = 0;
		x < 0 ? x = -x : isPositive = true;
		while (x != 0){
			if (result == result * 10 / 10)
				result = result * 10 + x % 10;
			else
				return 0;
			x /= 10;
		}
		return isPositive == true ? result : -result;
    }
};
````

## note

- 有符号整形的最大值是2的32次-1，当翻转整数超过该值时返回0
- 乘除法可以判断是否超过INT_MAX
- 不能用大小判断，因为在计算中（没有进行赋值）超过INT_MAX也会改变值，和临时分配的空间来保存整形值有关，而临时分配的空间取决于其中取值范围最大的变量