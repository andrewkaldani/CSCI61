#include <iostream>
#include <stack>
#include<algorithm>
#include <string>
#include<vector>
#include<queue>
#include <cstdlib>

using namespace std;
struct Node{
  int data;
  Node *left, *right;
};
Node* newNode(int data){
    Node* node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}
Node* insert(Node* root, int data){
  if(root==nullptr){
    return newNode(data);
  }
  if(data < root->data)
  {
    root->left=insert(root->left, data);
  }
  else{
    root->right = insert(root->right, data);
  }
  return root;
}
void printInOrder(Node *root){
  	if (root == nullptr)
  		return;

  	queue<Node*> a;
  	a.push(root);

  	while (!a.empty())
  	{
  		int count = a.size();
  		while (count--)
  		{
  			Node* temp = a.front();
  			a.pop();
  			cout << temp->data << ' ';
  			if (temp->left){
  				a.push(temp->left);}
  			if (temp->right){
  				a.push(temp->right);}
  		}

  		cout << endl;
  	}
  }

Node* construct(queue<int> &data)
{
	queue<Node*> a;
	Node* root = newNode(data.front());
	data.pop();
	a.push(root);

	while (!data.empty())
	{
    		Node* parent = a.front();
		a.pop();
		parent->left = newNode(data.front());
		data.pop();
		a.push(parent->left);
		if (!data.empty())
		{
			parent->right = newNode(data.front());
			data.pop();
			a.push(parent->right);

		}
	}
	return root;
}
void inorder(Node *root, queue<int> &data){
  if(root == NULL ){
    return;
  }
  inorder(root->left,data);
  data.push(root->data);
  inorder(root->right,data);
}
void preorder(Node *root, queue<int> &data){
  if(root == NULL ){return;}
  root->data = data.front();
  data.pop();
  preorder(root->left,data);
  preorder(root->right,data);
}
void convertToHeap(Node* &root){
  queue<int>data;
  inorder(root,data);
  root = construct(data);
}
int main()
{
	Node* root = nullptr;
	vector<int> data = { 2, 3, 11, 5, 7, 6 , 10 , 9 , 8 ,4 };
	for (int data: data)
		root = insert(root, data);

	convertToHeap(root);
	printInOrder(root);

	return 0;
}
