#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		else{
			vector<vector<char>> StringCollections;
			vector<char> strings;
			for (int i = 0; i < numRows; ++i)
				StringCollections.push_back(strings);
			for (int i = 0; i < s.length(); ++i){
				int temp = i % (2 * numRows - 2);
				temp < numRows ? StringCollections.at(temp).push_back(s[i]) : StringCollections.at(2 * numRows - 2 - temp).push_back(s[i]);
			}
			string str = "";
			for (vector<vector<char>>::iterator iter1 = StringCollections.begin(); iter1 != StringCollections.end(); ++iter1)
				for (vector<char>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2)
					str += *iter2;
			return str;
		}
    }
};

int main(){
    string str = "";
    int num = 0;
    cin >> str >> num;
    Solution s;
    cout << s.convert(str, num) << endl;
	system("pause");
    return 0;
}
