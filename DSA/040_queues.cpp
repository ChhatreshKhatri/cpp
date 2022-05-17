#include<bits/stdc++.h>
using namespace std;
//queue follows fifo order
//queue can be implemented through array and linked list
//implementing using array
class Queue2 {
	int *arr;
	int qfront;
	int rear;
	int qsize;
public:
    Queue2() {
        // Implement the Constructor
		qsize=100001;
		arr=new int[qsize];
		qfront=0;
		rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
		if(qfront==rear)
			return true;
		else 
			return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
		if(rear==qsize)cout<<"queue is full"<<endl;
		else{
			arr[rear]=data;
			rear++;
		}
    }

    int dequeue() {
        // Implement the dequeue() function
		if(qfront==rear)
			return -1;
		else{
			int ans=arr[qfront];
			arr[qfront]=-1;
			qfront++;
			if(qfront==rear){
				qfront=0;rear=0;
			}
			return ans;
		}
    }

    int front() {
        // Implement the front() function
		if(qfront==rear)
			return -1;
		else
			return arr[qfront];
    }

    int size(){
        return rear-qfront;
    }

    void print(){
        for(int i=qfront;i<rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
};
int main()
{
    //create a queue
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"size of queue "<<q.size()<<endl;
    cout<<q.front()<<" is popped "<<endl;
    q.pop();
    cout<<"size of queue "<<q.size()<<endl;
    if(q.empty())cout<<"queue is empty"<<endl;else cout<<"queue is not empty"<<endl;
    cout<<"front is "<<q.front()<<endl;

    Queue2 q2;
    //tc-O(1)
    q2.enqueue(5);
    q2.enqueue(50);
    q2.enqueue(500);
    q2.enqueue(5000);
    q2.print();
    cout<<"queue2 size "<<q2.size()<<endl;
    cout<<"element dequeued "<<q2.dequeue()<<endl;
    cout<<"front element-> "<<q2.front()<<endl;
    q2.print();
    

return 0;
}