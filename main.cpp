#include <iostream>

using namespace std;

struct node{
char data;
node* left;
node* right;
};
node* newnode(char data)
{
    node* n=new(node);
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
node* insertnode(node* root,char data)
{
    if(root==NULL)
        root=newnode(data);
    else if(data<=root->data)
        root->left=insertnode(root->left,data);
    else
        root->right=insertnode(root->right,data);
    return root;

}

void preorder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
  node* root;
  root=NULL;
  int x=0;
  char y;
  while(x!=2)
  {
      cout<<"Enter 1 to insert a number to the tree.\nEnter 2 to exit :";
      cin>>x;
      switch(x)
      {
          case 1:cout<<"\n\nEnter the number :";
                 cin>>y;
                 cout<<endl<<endl;
                 root=insertnode(root,y);
                 break;
          case 2:break;
          default:cout<<"\n\n\tEnter a valid number!!!\n\n";
                  break;

      }
  }

  cout<<"\n\npreorder :";
  preorder(root);
  cout<<"\n\ninorder :";
  inorder(root);
  cout<<"\n\npostorder :";
  postorder(root);
}
