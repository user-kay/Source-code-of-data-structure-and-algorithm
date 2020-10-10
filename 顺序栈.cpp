#include<iostream>
#include<stdio.h>
using namespace std;

const int StackSize = 10;

template<class T>
class SeqStack {
	public:
		SeqStack();
		void Push(T x);//��ջ����
		T Pop(); //��ջ����
		T GetTop(); //ȡջ��Ԫ��
		int Empty();//�ж��Ƿ�Ϊ��
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
	    SeqStack<int> S;      //����ģ�����ʵ��
	if (S.Empty()==1)
		cout<<"ջΪ��"<<endl;
	else
        cout<<"ջ�ǿ�"<<endl;
    cout<<"��15��10ִ����ջ����"<<endl;
	S.Push(15);
	S.Push(10);   
	cout<<"ջ��Ԫ��Ϊ:"<<endl;   //ȡջ��Ԫ��
	cout<<S.GetTop( )<<endl;  
	cout<<"ִ��һ�γ�ջ����"<<endl;
	S.Pop( );          //ִ�г�ջ����
    cout<<"ջ��Ԫ��Ϊ:"<<endl;
    cout<<S.GetTop( )<<endl;
	return 0;
} 
