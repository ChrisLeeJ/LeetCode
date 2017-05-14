#include <iostream>
#include <math.h>
using namespace std;
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
int main(){
	int a = 0;
	cin >> a;
	Solution x;
	cout << x.reverse(a) << endl;
	system("pause");
	return 0;
}