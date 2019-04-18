#include <iostream>

using namespace std;

struct node{
int data;
node* left;
node* right;
};
node* newnode(int data)
{
    node* n=new(node);
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
node* insertnode(node* root,int data)
{
    if(root==NULL)
        root=newnode(data);
    else if(data<=root->data)
        root->left=insertnode(root->left,data);
    else
        root->right=insertnode(root->right,data);
    return root;

}

int findmax(node* root)
{
    if(root->right==NULL)
        return root->data;
    return findmax(root->right);
}

int findmin(node* root)
{
    if(root->left==NULL)
        return root->data;
    return findmin(root->left);
}

bool searchnode(node* root,int w)
{
    if(root==NULL)
        return false;
    else if(root->data==w)
        return true;
    else if(w<root->data)
        return searchnode(root->left,w);
    else
        return searchnode(root->right,w);
}

node* deletenode(node* root, int data)
{
    if(root==NULL)
        cout<<"\n\nNO such node\n\n";
   else if(data<root->data)
   root->left=deletenode(root->left,data);

 else if(data>root->data)
   root->right=deletenode(root->right,data);
 else if(root->data==data)
 {
     if(root->left==NULL && root->right==NULL)
     {
         delete root;
         root=NULL;
     }
 }

 return root;

}
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int Findheight(node* root){
 if(root==NULL)
    return -1;
 return max(Findheight(root->left),Findheight(root->right))+1;
}
int main()
{
  node* root;
  root=NULL;
  int x=0;
  int y;
  cout<<"Enter 1 to insert a number to the tree.\nEnter 2 to exit";
  while(x!=2)
  {
      cin>>x;
      switch(x)
      {
          case 1:cout<<"\n\nEnter the number :";
                 cin>>y;
                 root=insertnode(root,y);
                 break;
          case 2:break;
          default:cout<<"\n\n\tEnter a valid number!!!\n\n";
                  break;

      }
  }
  int z;
  cout<<"\n\n\nEnter number to be search :";
  cin>>z;

  if(searchnode(root,z)==true)
    cout<<"\n\nFOUND\n\n";
  else
    cout<<"\n\nNOT FOUND\n\n";

   cout<<"\n\nMax number is :"<<findmax(root);
   cout<<"\n\nMin number is :"<<findmin(root);

   cout<<"\n\nHeight of the tree is :"<<Findheight(root);
}
