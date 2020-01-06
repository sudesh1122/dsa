#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* l;
	Node* r;
};

//Function too create a new node in heap 

Node* GetNewNode(int val)
{
	Node* newNode = new Node();
	newNode->data = val;
	newNode->l = newNode->r = NULL;
	return newNode;
}
// Function to insert data in BST, returns address of root node 
Node* Insert(Node* root,int val)
{
	if(root==NULL)
	{
		root=GetNewNode(val);
		return root;
	}
	else if( val<=root->data)
	{
		root->l = Insert(root->l,val);
	}
	else
	{
		root->r = Insert(root->r,val);
	}
	return root;
}
bool Search(Node* root, int data)
{
	if(root==NULL) return false;
	else if(root->data == data) return true;
	else if(data<=root->data) return Search(root->l,data);
	else return Search(root->r,data);
}



Node* FindMin(Node* n)
{
	Node * temp = n;
	while(temp->l!=NULL)
	{
		temp = temp->l;
	}
	return temp;

}



Node* Delete(Node* root, int data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(data < root->data) root->l = Delete(root->l,data);
	else if(data > root->data) root->r = Delete(root->r,data);
	else // when the node found
	{	
		//case 1 when node to be deleted has no child
		if(root->l ==NULL && root->r==NULL)
		{
			delete root;
			root = NULL;
			
		}
		//case 2. when node to be deleted has 1 chid 
		else if(root->l == NULL)
		{
			Node* temp = root;
			root = root->r;
			delete temp;
			
		}
		else if(root->r == NULL)
		{
			Node* temp = root;
			root = root->l;
			delete temp;
			
		}
		//case3. when node to be deleted has 2 children
		else
		{
			Node* temp = FindMin(root->r); //or FindMax(root->l);
			root->data = temp->data;
			root->r = Delete(root->r,temp->data);
		} 
	}
	return root;	

}

int main()
{
	Node* root = NULL;
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

	int num;
	cout<<"Enter the number you want to Search- \n";
	cin>>num;
	if(Search(root,num)) cout<<"FOUND!!!\n";
	else cout<<"Not FOUND!!\n";
	root = Delete(root,10);
	
	cout<<"Enter the number you want to Search- \n";
	cin>>num;
	if(Search(root,num)) cout<<"FOUND!!!\n";
	else cout<<"Not FOUND!!\n";

}
