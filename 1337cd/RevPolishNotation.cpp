#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		int tokenNum = tokens.size();
		return eval(tokens);
		/*
		for (int i = 0; i < tokenNum; ++i) {
			cout << str2int(tokens[i]) << endl;
		}*/
	}

	int eval(vector<string> &tokens) {
		//Pop one from back
		string s = tokens[tokens.size()-1];
		tokens.pop_back();
		//
		if (s == "+") {
			int num2 = eval(tokens);
			int num1 = eval(tokens);
			return num1 + num2;
		} else if (s == "-") {
			int num2 = eval(tokens);
			int num1 = eval(tokens);
			return num1 - num2;
		} else if (s == "*") {
			int num2 = eval(tokens);
			int num1 = eval(tokens);
			return num1 * num2;
		} else if (s == "/") {
			int num2 = eval(tokens);
			int num1 = eval(tokens);
			return num1 / num2;
		} else {
			return atoi(s.c_str());
		}
	}

};



int main() {

	string input[] = {"4", "13", "5", "/", "+"};
	vector<string> inputVec(input, input+5);

	cout << "Result: " << (new Solution())->evalRPN(inputVec) << endl;

	return 0;
}
