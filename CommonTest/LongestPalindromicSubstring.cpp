#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string L_Palindrome = "";
        for(int center = 0; center < s.length(); ++center) {
            int min_point = center, max_point = center;
            while (s[min_point--] == s[max_point++]);
            L_Palindrome = (L_Palindrome.length() < (max_point - min_point - 3)) ? s.substr( min_point + 2, max_point - min_point - 3 ) : L_Palindrome;

            min_point = center;
            max_point = center + 1;
            while (s[min_point--] == s[max_point++]) ;
            L_Palindrome = (L_Palindrome.length() < (max_point - min_point - 2)) ? s.substr( min_point + 1, max_point - min_point - 2 ) : L_Palindrome;
        }
        return L_Palindrome;
    }
};

int main(){
    string str = "";
    cin >> str;
    Solution s;
    cout << s.longestPalindrome(str) << endl;
    return 0;
}
