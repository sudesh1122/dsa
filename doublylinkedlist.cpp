#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* prev, * next;
	Node(int val)
	{
		data = val;
		prev = next = nullptr;
	}
	Node()
	{
		prev = next = nullptr;
	}
};


class doublylinkedlist
{
	private:
		Node * head, * end;
	public:
		doublylinkedlist()
		{
			head = end = nullptr;
		}
		void appendNode(int val)
		{
			Node * temp = new Node(val);
			if(!end)
				head = end = temp;
			else
			{
				end -> next = temp;
				temp -> prev = end;
				end = temp;
				temp = nullptr;
				cout<<"node appended successfully \n";
			}

		}
		void display()
		{
			Node* temp = head;
			if(!temp)
				cout<<"List is empty, nothing to show\n";
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
		}

		void prependNode(int val)
		{	
			Node * temp = new Node(val);
			if(!head)
				head= end = temp;
			else
			{
				head->prev = temp;
				temp->next = head;
				head = temp;
				temp = nullptr;
				cout<<"node prepended successfully \n";
			}
		}
		void deleteNode(int val)
		{
			Node* temp= head;
			while(temp)
			{
				if(temp->data==val)
				{
					break;
				}
				else
					temp = temp->next;
			}
			if(!temp)
				cout<<"Element not found\n";
			else if(temp == head && head == end)
			{
				head = end = nullptr;
				delete temp;
				cout<<"deleted last Element.Now list is empty\n";
			}
			else if(temp == head)
			{
				head = head->next;
				head->prev = nullptr;
				delete temp;
				cout<<"Item deleted from the start of the list\n";
			}
			else if(temp == end)
			{
				end = end->prev;
				end->next = nullptr;
				delete temp;
				cout<<"item deleted from the end of the list\n";
			}
			else
			{
				temp->prev ->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				cout<<"item deleted successfully!\n";
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