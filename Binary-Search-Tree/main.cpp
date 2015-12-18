#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *left,*right;
};

Node* insert(Node*,int);
Node* createNewNode(int);
bool search(Node*,int);

int main()
{
  Node *root = NULL;
  root = insert(root,15); root = insert(root,10); root = insert(root,20);
  root = insert(root,17); root = insert(root,25); root = insert(root,5);
  root = insert(root,12);
  cout<<"Enter a number to be searched for: ";
  int n;
  cin>>n;
  if(search(root,n) == true)
    cout<<"Found!\n";
  else
    cout<<"Not Found!\n";
  return 0;
}

Node* createNewNode(int x)
{
  Node* newNode = new Node();
  newNode->data = x;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insert(Node* root, int x)
{
  if(root == NULL)
    root = createNewNode(x);
  else if(root->data >= x)
    root->left = insert(root->left,x);
  else
    root->right = insert(root->right,x);
  return root;
}

bool search(Node* root, int x)
{
  if(root==NULL)
    return false;
  else if(root->data > x)
    search(root->left,x);
  else if(root->data < x)
    search(root->right,x);
  else
    return true;
}
