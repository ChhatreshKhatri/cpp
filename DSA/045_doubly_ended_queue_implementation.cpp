#include <bits/stdc++.h>
using namespace std;
// all operation in O(1) tc
// sc O(n) arr size
class Deque2
{
	int *arr;
	int front;
	int rear;
	int size;

public:
	// Initialize your data structure.
	Deque2(int n)
	{
		size = n;
		arr = new int[n];
		front = -1;
		rear = -1;
	}

	// Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
	bool pushFront(int x)
	{
		// full
		if (isFull())
		{
			//(front==0&&rear==-1)||(rear==(front-1)%(size-1)) isFull
			return false;
		}
		// first element
		else if (isEmpty())
		{
			front = rear = 0;
		}
		// cyclic
		else if (front == 0 && rear != size - 1)
		{
			// rear!=size-1 so that stack is not full
			front = size - 1;
		}
		else
		{
			front--;
		}
		arr[front] = x;
		return true;
	}

	// Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
	bool pushRear(int x)
	{
		// full
		if (isFull())
		{
			//(front==0&&rear==-1)||(rear==(front-1)%(size-1)) isFull
			return false;
		}
		// cyclic
		else if (isEmpty())
		{
			// front==-1 isEmpty
			front = rear = 0;
		}
		// front is in mid or something and rear at end
		else if (rear == size - 1 && front != 0)
		{
			rear = 0;
		}
		else
		{
			rear++;
		}
		arr[rear] = x;
		return true;
	}

	// Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
	int popFront()
	{
		// to check queue is empty
		if (isEmpty())
		{
			// front==-1
			return -1;
		}
		int ans = arr[front]; // store kara liya return ke liye
		arr[front] = -1;	  // element ko hata diya/pop kr diya
		// if single element is present update front and rear
		if (front == rear)
		{
			front = rear = -1;
		}
		// cyclic
		else if (front == size - 1)
		{
			front = 0;
		}
		else
		{
			front++;
		}
		return ans;
	}

	// Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
	int popRear()
	{
		// check empty
		if (isEmpty())
		{
			return -1;
		}
		int ans = arr[rear]; // store kara liya return ke liye
		arr[rear] = -1;
		// single element is present
		if (front == rear)
		{
			front = rear = -1;
		}
		// cyclic
		else if (rear == 0)
		{
			rear = size - 1;
		}
		else
		{
			rear--;
		}
		return ans;
	}

	// Returns the first element of the deque. If the deque is empty, it returns -1.
	int getFront()
	{
		if (isEmpty())
		{
			return -1;
		}

		return arr[front];
	}

	// Returns the last element of the deque. If the deque is empty, it returns -1.
	int getRear()
	{
		if (isEmpty())
		{
			return -1;
		}

		return arr[rear];
	}

	// Returns true if the deque is empty. Otherwise returns false.
	bool isEmpty()
	{
		if (front == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Returns true if the deque is full. Otherwise returns false.
	bool isFull()
	{
		if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
		{
			//(rear==(front-1)&(size-1))rear front ke ek piche
			// front should not be 0 as it will become front(0)-1=-1 will return -ve
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main()
{
	Deque2 d(10);//10 size
	d.pushFront(10);
	d.pushFront(9);
	d.pushFront(8);
	d.pushRear(11);
	d.pushRear(12);
	int ab=d.getFront();
	int cd=d.getRear();
	cout<<ab<<endl;
	cout<<cd<<endl;

	return 0;
}