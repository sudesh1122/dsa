#include <iostream>
using namespace std;

class Node{
public:
	int key;
	int data;
	Node* next;
	Node(){
		key= 0;
		data=0;
		next=NULL;
	}
	Node(int k,int d)
	{
		key = k;
		data =d;
	}
};

class Stack{
public:
	Node* head;
	Stack(){
		head=NULL;
	}
	Stack(Node * n)
	{
		head=n;
	}
	Node* nodeExists(int k){
			Node* ptr= head;
			Node* temp=NULL;
			while(ptr!=NULL)
			{
				if(ptr->key==k)
				{
					temp=ptr;
				}
				ptr=ptr->next;
			}
			return temp;
	}
	void pushNode(Node* n)
	{
		if(nodeExists(n->key)!=NULL)
		{
			cout<<"Node already exists with key "<<n->key<<endl;
		}
		else
		{
			n->next=head;
			head=n;
			cout<<"Node pushed successfully "<<endl;
		}
	}
	void popNode()
	{	
		if(head==NULL)
		{
			cout<<"Stack is under flow";

		}
		else
		{
			Node* temp = head;
			head = head->next;
			temp->next =NULL;
			free(temp);
			cout<<"Node poped successfully "<<endl;
		}


	}
	/*void printTopNode()
	{	
		Node* temp =head;
		if(temp==NULL)
		{
			cout<<"Stack is empty"<<endl;
		}
		else
		{	
		cout<<"("<<temp->key<","<<temp->data <<")" <<endl;
	}
	}*/
	void display()
	{
		if(head==NULL)
		{
			cout<<"stack is empty "<<endl;

		}
		else
		{	 
			Node* temp = head;
			while(temp!=NULL)
			{
				cout<<"("<<temp->key<<","<<temp->data<<")"<<";";
				temp= temp->next;

			}
		}
	}
	void updateByKey(int k,int d)
	{
		if(nodeExists(k)==NULL)
		{
			cout<<"No node exists with key "<<k<<endl;
		}
		else
		{
			Node* temp = nodeExists(k);
			temp->data = d;
			cout<<"node updated successfully"<<endl;
		}

	}
	Node* headNode()
	{
		return head;
	}
};

int main()
{
	Stack s;
	int option,key1,k1,data1;

	do{
		cout<<"choose proper option for your operation \n1. push Node\n2. pop node\n3. print top node \n4. Display all nodes\n5. Update a node n key\n\nEnter 0 to exit ";
		cin>>option;
		Node* n = new Node;
		switch(option)
		{
			case 0: break;
			case 1: 
					cout<<"enter the key of new node"<<endl;
					cin>>k1;
					cout<<"enter the data for new node\n";
					cin>>data1;
					n->key =k1;
					n->data =data1;
					s.pushNode(n);
					break;
			case 2:	
					s.popNode();
					break;
			case 3:
					n = s.headNode();
					cout<<"("<<n->key<<","<<n->data<<")"<<endl;
					break;	
			case 4:
					s.display();
					break;
			case 5:	cout<<"enter the key of the node which you want to update \n";
					cin>>k1;
					cout<<"enter the new value of the data of the node\n";
					cin>>data1;
					s.updateByKey(k1,data1);
					break;
			default:
					cout<<"please choode proper option"<<endl;				
		}
	}while(option!=0);
	return 0;
}




