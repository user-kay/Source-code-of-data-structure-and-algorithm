#include<bits/stdc++.h>
using namespace std;

class Matcher {
	public:
		Matcher(string str1);
		~Matcher();
		int Match();
	private:
		string str;
}; 

Matcher::Matcher(string str1) {
	str = str1;
}

Matcher::~Matcher() {
	
}

int Matcher::Match() {
	int top = -1;
	char s[30];
	for(int i = 0 ; str[i] != '\0' ; i++) {
		if(str[i] == '(' || str[i] == '（') {
			s[++top] = str[i];
		}
		else if(str[i] == ')' || str[i] == '）') {
			if(top > -1) {
				top--;
			}
			else {
				return -1;
				//说明右括号多了 
			}
		}
		 
	}
	if(top == -1) {
		return 0;
	} 
	else {
		return 1;
	}
}

int main() {
	string str;
	cout<<"请输入一个算术表达式";
	cin>>str;
	Matcher M(str);
	int k = M.Match();
	if(k == 0) {
		cout<<"正确匹配"<<endl;
	} 
	else if(k == 1) {
		cout<<"左括号多了"<<endl;
	}
	else {
		cout<<"右括号多了"<<endl;
	}
	return 0;
}
