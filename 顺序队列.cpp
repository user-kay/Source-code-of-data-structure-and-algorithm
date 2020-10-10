#include<iostream>
#include<stdio.h>
using namespace std;

const int QueueSize = 100;
//�����ƶ� front
//����ƶ� rear
 
template<class T>
class CirQueue {
	public:
		CirQueue(); //���캯��
		~CirQueue(); //��������
		void Enqueue(T x); //��Ӳ���
		T Dequeue(); //����ͷ����
		T GetHead(); //�õ���ͷ��Ԫ��
		int IsEmpty(); //�ж϶����Ƿ�Ϊ��
	private:
		T data[QueueSize];
		int front, rear;//��ͷָ��Ͷ�βָ�� 
};

template<class T>
CirQueue<T>::~CirQueue() {
	
}

//һ��ͬʱָ����е����λ
template<class T>
CirQueue<T>::CirQueue() {
	front = rear = QueueSize - 1;
}

template<class T>
void CirQueue<T>::Enqueue(T x) {
	if( (rear + 1) % QueueSize == front ) {
		throw"����"; 
	}
	//ע����ѭ����������Ҫ����
	rear = (rear + 1) % QueueSize;
	data[rear] = x; 
} 



template<class T>
T CirQueue<T>::Dequeue() {
	if(rear == front) {
		throw "����";
	}
	T x ;
	front = (front + 1) % QueueSize;
	x = data[front];
	return x; 
}

template<class T>
T CirQueue<T>::GetHead() {
	if(rear == front) {
		throw"����"; 
	}
	T x = data[front];
	return x;
}

template<class T>
int CirQueue<T>::IsEmpty() {
	if(front == rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int x;
	CirQueue<int> Q;
	cout<<"��5,8���в������"<<endl;
	Q.Enqueue(5);
	Q.Enqueue(8);
	x = Q.Dequeue();
	cout<<"�����ͷ��Ԫ��"<<endl;
	cout<<x<<" ";
	
	return 0;
} 


 
