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
		//����βָ���ͷָ�� 
};

template<class T>
LinkQueue<T>::LinkQueue() {
	Node<T> *s;
	s = new Node<T>;
	//����һ��ͷ���
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
	T x;//������Ŷ�ͷԪ�ص�ֵ
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
	cout<<"�����е�Ԫ��Ϊ"<<x1<<" ";
	return 0;
}

