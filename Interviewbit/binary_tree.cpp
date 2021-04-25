//Binary Tree Implementation
#include<stdio.h>
#include<stdlib.h>

struct node
{ 
int data;
struct node* left;
struct node* right;
}* root=NULL;
int flag=0;            //used in deletion

struct node* insertion(struct node* root,int data)
{
  if(root==NULL)
   {
    root=(struct node*)malloc(sizeof(struct node));
     root->data=data;
     root->left=root->right=NULL;
   }
   else
    {
      int d;
      printf("Insert L(0) or R(1) of %d ?\n",root->data);
      scanf("%d",&d);
      if(d==0)
      root->left=insertion(root->left,data);
      else if(d==1)
      root->right=insertion(root->right,data);
      else 
      printf("Element could not be inserted, Please select either 0 or 1\n");
    }
    return root;
}
 
struct node* deletion(struct node*root, int data)
 { 
    if(root->data==data)
    {
        root=NULL;
        flag=1;
    }
    else                 //SEARCHING LEFT AND RIGHT CHILD
    {
      if(root->left&&flag!=1)
     {printf("Moving left of %d\n",root->data);
    root->left=deletion(root->left,data);
    }
      if(root->right&&flag!=1)
      {printf("Moving right of %d\n",root->data);
      root->right=deletion(root->right,data);
      }
    }
    return root;
 }
//TRAVERSALS
void inorder(struct node* root)
{
    
    if(root==NULL)
    return;
    else
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{

 if(root==NULL)
  return;
  else
  {
      printf("%d\t",root->data);
      preorder(root->left);
      preorder(root->right);
  }
}
void postorder(struct node* root)
{

if(root==NULL)
 return;
 else
 {
     postorder(root->left);
     postorder(root->right);
     printf("%d\t",root->data);
 }
}

int main()
 {
  int d,data;
  while(1)
 {
    printf("\nEnter your choice:\n1.insertion \n2.deletion \n3.traverse\n4.exit\n");
    scanf("%d",&d);
    switch(d)
    {
        case 1:
               printf("Enter data to be inserted\n");
               scanf("%d",&data);
               root=insertion(root,data);
               break;
        case 2:
               if (root==NULL)
               {
               printf("Tree is empty\n");
               }
               else
               {
               printf ("Enter data to be deleted\n");
               scanf("%d",&data);
               root=deletion(root,data);
               if (flag==0)
               printf("The element you wanted to delete is not present, Please Try Again\n");
               }
               flag=0;
               break;
        case 3:
                printf("INOREDER:\n");
                 inorder(root);
                printf("\nPREOREDER:\n");
                 preorder(root);
                printf("\nPOSTOREDER:\n");
                 postorder(root);
                break;
        case 4: 
                exit(0);
                break;
        default:printf("wrong input");
    }
    }
 }
