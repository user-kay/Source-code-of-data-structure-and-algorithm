#include<iostream>
#include<stdio.h>
using namespace std;

const int StackSize = 10;

template<class T>
class SeqStack {
	public:
		SeqStack();
		void Push(T x);//入栈操作
		T Pop(); //出栈操作
		T GetTop(); //取栈顶元素
		int Empty();//判断是否为空
	private:
		T data[StackSize];
		int top; 
}; 

template<class T>
SeqStack<T>::SeqStack() {
	top = -1;
}

template<class T>
void SeqStack<T>::Push(T x) {
	data[++top] = x;
}

template<class T>
T SeqStack<T>::Pop() {
	T x = data[top--];
	return x;
}

template<class T>
T SeqStack<T>::GetTop() {
	T x = data[top];
	return x;
}

template<class T>
int SeqStack<T>::Empty() {
	if(top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	    SeqStack<int> S;      //创建模板类的实例
	if (S.Empty()==1)
		cout<<"栈为空"<<endl;
	else
        cout<<"栈非空"<<endl;
    cout<<"对15和10执行入栈操作"<<endl;
	S.Push(15);
	S.Push(10);   
	cout<<"栈顶元素为:"<<endl;   //取栈顶元素
	cout<<S.GetTop( )<<endl;  
	cout<<"执行一次出栈操作"<<endl;
	S.Pop( );          //执行出栈操作
    cout<<"栈顶元素为:"<<endl;
    cout<<S.GetTop( )<<endl;
	return 0;
} 
