#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		bool isPositive = false;
		int result = 0;
		if (str[0] == '+')
			str = str.substr(1, str.length() - 1);
		else if (str[0] == '-'){
			isPositive = false;
			str = str.substr(1, str.length() - 1);
		}
		for (int i = 0; i < str.length(); ++i){
			if (str[i] == ' ' || str[i] == '+')
				return 0;
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
	//cout << x.myAtoi(str) << endl;
	system("pause");
	return 0;
}