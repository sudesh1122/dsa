#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* prev;
	Node* next;
	Node(int val)
	{
		data = val;
		prev = next = NULL;
	}
	Node()
	{
		
		prev = next = NULL;
	}
};
class doublylinkedlist
{
public:
	Node* head;
	Node* end;
	doublylinkedlist()
	{
		head = end = NULL;
	}
	void appendNode(int val)
	{
		Node * temp = new Node;
		temp->data = val;
		temp->next = NULL;
		if(end==NULL)
		{
			temp->prev =NULL;
			head= end = temp;
		}
		else
		{
			end->next = temp;
			temp->prev = end;
			end = temp;
			cout<<"node appended successfully \n";
		}

	}
	void display()
	{
		Node* temp = head;
		if(temp==NULL)
		{
			cout<<"List is empty, nothing to show\n";
		}
		else
		{	
			cout<<"Elements of the list are : ";
			while(temp->next!=NULL)
			{
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<temp->data<<"\n";
		}	
		delete temp;

	}

	void prependNode(int val)
	{	
		Node * temp = new Node;
		temp->data = val;
		temp->prev = NULL;
		if(head==NULL)
		{
			temp->next =NULL;
			head= end = temp;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
			cout<<"node prepended successfully \n";
		}
	}
	void deleteNode(int val)
	{
		if(head->data==val)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			cout<<"Node found at the start!!\ndeleted successfully\n";
		}
		/*else if(end->data==val)
		{
			Node* temp = end;
			end = end->prev;
			delete temp;
			cout<<"Node found at the end!!\ndeleted successfully\n";

		}*/ //we are not applying this condition as we want to use first come first delete approach.
		else
		{
			Node* temp = NULL;
			Node* prevNode = head;
			Node* currentNode = head->next;
			
			while(currentNode->next!=NULL)
			{
				if(currentNode->data==val)
				{
					temp = currentNode;
					
					break;
				}
				else
				{
					prevNode = prevNode->next;
					currentNode= currentNode->next;
					
				}
			}
			
			if(temp==NULL)
			{
				if(end->data = val)
				{
					Node* temp = end;
					end = end->prev;
					delete temp;
					cout<<"Node found at the end of the list\nNode deleted successfully!\n";
				}
				else
				{
					cout<<"There is no node exists with value "<<val<<endl;
				}
			}	
			else
			{	
				Node* nextNode  = currentNode->next;
					
				prevNode->next = temp->next;
				nextNode->prev = temp->prev;
				delete currentNode;
				delete temp;
					
				cout<<"Node with given value delete successfully!\n";
				
			}
		}

	}
};
int main()
{	
	doublylinkedlist s;
	int option, data1;
	do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
   // cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNode()" << endl;
   // cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;
    Node* n1 = new Node;
    cin>>option;
    switch(option)
    {
    	case 0 : 
    			break;
    	case 1:
    			//cout<<"enter the value of key : "<<endl;
    			//cin>>key1;
    			cout<<"enter the value of data: ";
    			cin>>data1;
    			//n1->key = key1;
    			//n1->data=data1;
    			s.appendNode(data1);
    			break;
    	case 2:
    			
    			//cout<<"enter the value of key : "<<endl;
    			//cin>>key1;
    			cout<<"enter the value of data: ";
    			cin>>data1;
    			//n1->key = key1;
    			//n1->data=data1;
    			s.prependNode(data1);
    			break;
    	/*case 3:
    			cout<<"enter the key value after which you wanna insert new node: "<<endl;
    			cin>>k1;
    			cout<<"enter the key for new node "<<endl;
    			cin>>key1;
    			cout<<"enter the data value for new node:"<<endl;
    			cin>>data1;
    			n1->key = key1;
    			n1->data=data1;
    			s.insertNodeAfter(k1,n1);
    			break;*/
    	case 4:
    			cout<<"enter the data of the node you wanna delete :"<<endl;
    			cin>>data1;
    			s.deleteNode(data1);
    			break;
    	/*case 5: 
    			cout<<"enter the key : "<<endl;
    			cin>>key1;
    			cout<<"enter the value of new data:"<<endl;
    			cin>>data1;
    			s.updateNodeByKey(key1,data1);
    			break;*/
    	case 6:
    			s.display();
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