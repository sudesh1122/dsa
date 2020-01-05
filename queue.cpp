#include <iostream>
using namespace std;

class Node{
public:
	int val;
	Node* next;
	Node(){
		val=0;
		next =NULL;
	}
	Node(int v)
	{
		val = v;
	}
};

class Queue
{
public:
	Node* front;
	Node* rear;
	Queue()
	{
		front = NULL;
		rear=NULL;
	}
	Queue(Node* n)
	{
		front = n;
	}
	void Insert(int v)
	{
		if(rear==NULL)
		{	
			rear = new Node();
			rear->val=v;
			rear->next=NULL;
			front = rear;
		}
		else
		{
			Node*  temp = new Node();
			temp->val=v;
			temp->next=NULL;
			rear->next=temp;
			rear = temp;
		}
		cout<<"Node inserted successfully"<<endl;
	}
	

	void pop()
	{
		if(front==NULL)
		{
			cout<<"Underflow";
		}
		else
		{
			Node* temp = front;
			if(temp->next==NULL)
			{
				cout<<"Element popped from queue is "<<temp->val<<endl;
				free(front);
				front= NULL;
				rear = NULL;
			}
			else
			{
				temp = temp->next;
				cout<<"Element popped from queue is "<<front->val<<endl;
				free(front);
				front = temp;
			}
		}
	}
	void display()
	{
		if(front==NULL)
		{
			cout<<"queue is empty, nothing to display\n";
		}
		else
		{
			Node* temp = front;
			cout<<"Elements are : ";
			while(temp!=NULL)
			{
				cout<<temp->val<<" ";
				temp=temp->next;
			}
			
		}
	}

};
int main()
{
	Queue q;
	int option,v1;
	do{
		cout<<"\n\nChoose proper option->\n1.Insert a neew element to the queue\n2. Pop element from queue\n3.Print all elements of the queue\n\nEnter 0 to exit\n";
		cin>>option;
		Node* n =  new Node;
		switch(option)
		{
			case 0: break;
			case 1: cout<<"enter the value you wanna insert\n";
					cin>>v1;
					q.Insert(v1);
					break;
			case 2: q.pop();
					break;
			case 3: q.display();
					break;
			default: cout<<"please choose proper option\n";
		}

	}while(option!=0);
	return 0;
}



