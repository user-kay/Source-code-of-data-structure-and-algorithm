#include<iostream>
#include<stdio.h>
using namespace std;

const int QueueSize = 100;
//出队移动 front
//入队移动 rear
 
template<class T>
class CirQueue {
	public:
		CirQueue(); //构造函数
		~CirQueue(); //析构函数
		void Enqueue(T x); //入队操作
		T Dequeue(); //将队头出队
		T GetHead(); //得到队头的元素
		int IsEmpty(); //判断队列是否为空
	private:
		T data[QueueSize];
		int front, rear;//队头指针和队尾指针 
};

template<class T>
CirQueue<T>::~CirQueue() {
	
}

//一般同时指向队列的最高位
template<class T>
CirQueue<T>::CirQueue() {
	front = rear = QueueSize - 1;
}

template<class T>
void CirQueue<T>::Enqueue(T x) {
	if( (rear + 1) % QueueSize == front ) {
		throw"上溢"; 
	}
	//注意是循环链表所以要求余
	rear = (rear + 1) % QueueSize;
	data[rear] = x; 
} 



template<class T>
T CirQueue<T>::Dequeue() {
	if(rear == front) {
		throw "下溢";
	}
	T x ;
	front = (front + 1) % QueueSize;
	x = data[front];
	return x; 
}

template<class T>
T CirQueue<T>::GetHead() {
	if(rear == front) {
		throw"下溢"; 
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
	cout<<"对5,8进行插入操作"<<endl;
	Q.Enqueue(5);
	Q.Enqueue(8);
	x = Q.Dequeue();
	cout<<"输出队头的元素"<<endl;
	cout<<x<<" ";
	
	return 0;
} 


 
