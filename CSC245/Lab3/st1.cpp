#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

bool operator == (stack<string> &s1, stack<string> &s2);
bool operator < (stack<string> &s1, stack<string> &s2);

int main() {

	stack<string> s1, s2;
	s1.push("Hi there");
	s2.push("Hello");
	cout << s1 == s2 << endl;

}

bool operator == (stack<string> &s1, stack<string> &s2) {
	return s1 == s2;
}
bool operator < (stack<string> &s1, stack<string> &s2) { 
	return s1 < s2;
}
