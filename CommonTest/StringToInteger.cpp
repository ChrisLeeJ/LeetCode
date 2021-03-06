#include <iostream>
#include <string>
using namespace std;

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

int main(){
	string str;
	cin >> str;
	Solution x;
	const char * strtemp = str.c_str();
	cout << atoi(strtemp) << endl;
	cout << x.myAtoi(str) << endl;
	system("pause");
	return 0;
}