#include <iostream>
using namespace std;

class Node{
public:
	int key;
	int data;
	Node* next;
	Node(){

		key =0;
		data=0;
		next=NULL;
	}
	Node(int k,int d)
	{
		key = k;
		data= d;

	}

};
class SinglyLinkedList{
public:
	Node* head;

	SinglyLinkedList()
	{
		head=NULL;
	}
	SinglyLinkedList(Node *n)
	{
		head=n;
	}
	//1. check if node exists using key value
	Node* nodeExists(int k)
	{
		 Node* temp = NULL;
		 Node* ptr= head;
		 while(ptr!=NULL)
		 {
		 	if(ptr->key==k)
		 	{
		 		temp=ptr;
		 	}
		 	ptr= ptr->next;

		 }
		 return temp;
	}
	//2. Append a node to the list
	void appendNode(Node *n)
	{
		if(nodeExists(n->key)!=NULL)
		{
			cout<<" Node already exists with key value: "<<n->key <<"  Append another with different key value"<<endl;
		}
		else{
			if(head==NULL)
			{
				head=n;
				cout<<"Node appended"<<endl;
			}
			else
			{

				Node* ptr= head;
				while(ptr->next!=NULL)
				{
					ptr = ptr->next;

				}
				ptr->next =n;
				cout<<"Node appended"<<endl;
			}

			}		
		
	}
	//3. prepend Node - Attach a node at the start
	void prependNode(Node * n)
	{
		if(nodeExists(n->key)!=NULL)
		{
			cout<<" Node already exists with key value: "<<n->key <<"Append another with different key value"<<endl;
		}
		else
		{
			n->next=head;
			head= n;
			cout<<"node prepended";
		}
	}
	//4. Insert a node after a particular node in the list
	void insertNodeAfter(int k,Node* n)
	{
		Node* ptr = nodeExists(k);
		if(ptr==NULL)
		{
			cout<<"No node exists with key value: "<<k<<endl;
		}
		else
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<" Node already exists with key value: "<<n->key <<"Append another with different key value"<<endl;
			}
			else
			{
				n->next=ptr->next;
				ptr->next=n;
				cout<<"Node inserted after node with key: "<<k<<endl;
			}
		}
	}
	//5. delete node by unique key
	void deleteNodeByKey(int k)
	{
		if(head==NULL)
		{
			cout<<"SinglyLinkedList is already empty. Can't delete anything"<<endl;
		}
		else
		{	if(head->key==k){
			head= head->next;
			cout<<"Node unlinked with key's value: "<<k<<endl;
			}
			else {
				Node* temp=NULL;
				Node* prevptr = head;
				Node* currentptr = head->next;
				while(currentptr!=NULL)
				{
					if(currentptr->key==k)
					{
						temp = currentptr;
						currentptr = NULL;
					}
					else
					{
						prevptr= prevptr->next;
						currentptr= currentptr->next;
					}	
				}
				if(temp!=NULL)
				{
					prevptr->next=temp->next;
					cout<<"Node unlinked with  key's value: "<<k<<endl;
				}
				else
				{
					cout<<"Node doesn't exist with key value "<<k<<endl;
				}
			}


		}


	}
	//6. Update node
	void updateNodeByKey(int k,int d)
	{
		Node* ptr = nodeExists(k);
		if(ptr!=NULL)
		{
			ptr->data=d;
			cout<<"Node data updated successfully"<<endl;

		}
		else
		{
			cout<<"Node does not exist."<<endl;
		}	
	}
	//7. printing
	void printlist()
	{
		if(head==NULL)
		{
			cout<<"No node in singly linked list"<<endl;
		}
		else
		{
			cout<<"Signly linked list items : ";
			Node* temp = head;
			while(temp!=NULL)
			{
				cout<<"("<<temp->key<<","<<temp->data<<") --> ";
				temp=temp->next;
			}
		}	
	}



};


int main()
{
	SinglyLinkedList s;
	int option, k1, data1,key1;
	do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;
    Node* n1 = new Node;
    cin>>option;
    switch(option)
    {
    	case 0 : 
    			break;
    	case 1:
    			cout<<"enter the value of key : "<<endl;
    			cin>>key1;
    			cout<<"enter the value of data: ";
    			cin>>data1;
    			n1->key = key1;
    			n1->data=data1;
    			s.appendNode(n1);
    			break;
    	case 2:
    			
    			cout<<"enter the value of key : "<<endl;
    			cin>>key1;
    			cout<<"enter the value of data: ";
    			cin>>data1;
    			n1->key = key1;
    			n1->data=data1;
    			s.prependNode(n1);
    			break;
    	case 3:
    			cout<<"enter the key value after which you wanna insert new node: "<<endl;
    			cin>>k1;
    			cout<<"enter the key for new node "<<endl;
    			cin>>key1;
    			cout<<"enter the data value for new node:"<<endl;
    			cin>>data1;
    			n1->key = key1;
    			n1->data=data1;
    			s.insertNodeAfter(k1,n1);
    			break;
    	case 4:
    			cout<<"enter the key for the node you wanna delete :"<<endl;
    			cin>>k1;
    			s.deleteNodeByKey(k1);
    			break;
    	case 5: 
    			cout<<"enter the key : "<<endl;
    			cin>>key1;
    			cout<<"enter the value of new data:"<<endl;
    			cin>>data1;
    			s.updateNodeByKey(key1,data1);
    			break;
    	case 6:
    			s.printlist();
    			break;
    	case 7: 
    			system("CLS");
    			break;
    	default:
    			cout<<"please enter proper option "<<endl;		
    											
    }
}while(option!=0);
 



	return 0;
}