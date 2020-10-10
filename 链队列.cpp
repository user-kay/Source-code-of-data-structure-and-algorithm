#include<iostream>
#include<stdio.h>
using namespace std;

template<class T> 
struct Node{
	T data;
	Node *next;
}; 

template<class T>
class LinkQueue {
	public:
		LinkQueue();
		~LinkQueue();
		void EnQueue(T x); 
		T GetHead();
		T DeQueue();
	private:
		Node<T> *rear, *front;
		//定义尾指针和头指针 
};

template<class T>
LinkQueue<T>::LinkQueue() {
	Node<T> *s;
	s = new Node<T>;
	//定义一个头结点
	rear = front = s;
	s->next = NULL; 
}

template<class T>
LinkQueue<T>::~LinkQueue() {
	Node<T> *p = front;
	while(front != NULL) {
		front = front->next;
		delete p;
	}
}

template<class T>
void LinkQueue<T>::EnQueue(T x) {
	Node<T> *s;
	s = new Node<T>;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

template<class T>
T LinkQueue<T>::DeQueue() {
	T x;//用来存放队头元素的值
	Node<T> *p = front->next;
	x = p->data;
	front->next = p->next;
	delete p; 
	return x;
}

template<class T>
T LinkQueue<T>::GetHead() {
	T x;
	Node<T> *p = front->next;
	x = p->data;
	return x;
}

int main() {
	int x1, x2;
	LinkQueue<int> L;
	L.EnQueue(10);
	x1 = L.DeQueue();
	cout<<"队列中的元素为"<<x1<<" ";
	return 0;
}

