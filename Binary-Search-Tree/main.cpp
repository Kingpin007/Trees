#include <iostream>
#include <queue>

using namespace std;

struct Node
{
  int data;
  Node *left,*right;
};

Node* insert(Node*,int);
Node* createNewNode(int);
int findMin(Node*);
int findMax(Node*);
int findHeight(Node*);
void levelOrder(Node*);
void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);
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
  cout<<"Minimum is: "<<findMin(root)<<"\nMaximum is: "<<findMax(root);
  cout<<"\nLevelOrder output: ";
  levelOrder(root);
  cout<<endl;
  cout<<"\nPreOder output: ";
  preOrder(root);
  cout<<endl;
  cout<<"\nInOrder output: ";
  inOrder(root);
  cout<<endl;
  cout<<"\nPostOrder output: ";
  postOrder(root);
  cout<<endl;
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

int findMin(Node *root)
{
  if(root == NULL)
  {
    cout<<"Error, the tree is empty!\n";
    return -1;
  }
  else if(root->left==NULL)
    return root->data;
  return findMin(root->left);
}

int findMax(Node *root)
{
  if(root == NULL)
  {
    cout<<"Error, the tree is empty!\n";
    return -1;
  }
  else if(root->right==NULL)
    return root->data;
  return findMax(root->right);
}

int findHeight(Node *root)
{
  if(root == NULL)
    return -1;
  int l=findHeight(root->left);
  int r=findHeight(root->right);
  return ((l>r?l:r)+1);
}

void levelOrder(Node *root)
{
  if(root == NULL)
    return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty())
  {
    Node *current = q.front();
    cout<<current->data<<"->";
    if(current->left!=NULL)
      q.push(current->left);
    if(current->right!=NULL)
      q.push(current->right);
    q.pop();
  }
}

void preOrder(Node *root)
{
  if(root == NULL)
    return;
  cout<<root->data<<"->";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node *root)
{
  if(root == NULL)
    return;
  inOrder(root->left);
  cout<<root->data<<"->";
  inOrder(root->right);
}

void postOrder(Node *root)
{
  if(root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<"->";
}
