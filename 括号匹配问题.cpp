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
		if(str[i] == '(' || str[i] == '��') {
			s[++top] = str[i];
		}
		else if(str[i] == ')' || str[i] == '��') {
			if(top > -1) {
				top--;
			}
			else {
				return -1;
				//˵�������Ŷ��� 
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
	cout<<"������һ���������ʽ";
	cin>>str;
	Matcher M(str);
	int k = M.Match();
	if(k == 0) {
		cout<<"��ȷƥ��"<<endl;
	} 
	else if(k == 1) {
		cout<<"�����Ŷ���"<<endl;
	}
	else {
		cout<<"�����Ŷ���"<<endl;
	}
	return 0;
}
