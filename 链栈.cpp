#include<iostream>
#include<stdio.h>
using namespace std;

template<class T>
class LinkStack {
	public:
		LinkStack();//构造函数
		~LinkStack();//析构函数
		void Push(T x);//入栈操作
		T Pop();
		T getTop();
		int Empty();
	private:
		Node<T> *top; 
};

template<class T>
LinkStack<T>::LinkStack() {
	top = NULL;
}

template<class T>
LinkStack<T>::~LinkStack() {
	Node<T> *p ;
	p = new Node<T>;
	while(top != NULL){
		p = top;
		top = top->next;
		delete p; 
	} 
}

template<class T>
void LinkStack<T>::Push(T x) {
	Node<T> *p = new Node<T>;
	p->data = x;
	p->next = top;
	top = p;
}

template<class T>
T LinkStack<T>::Pop() {
	Node<T> *p = top;
	T x = p->data;
	top = top->next;
	delete p;
	return x;
}



int main() {
	
}
