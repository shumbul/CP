#include <iostream>
using namespace std;
#include <queue>
// A tree node
struct node
{
    char data;
    node *left;
    node *right;
 node *right_neighbor;
 node(char data)
   {
       this -> data = data;
       left = NULL;
       right = NULL;
       right_neighbor = NULL;
   }
};
// Function to print the right_neighbor of the nodes
void PreOrderTraversal(node *node)
{
    if(node == NULL){
      return;
 }
 else{
   if(node -> right_neighbor != NULL){
     cout << node -> data << "-> " << node -> right_neighbor -> data << endl;
   }
   else{
     cout << node -> data << "-> NULL" << endl;
   }
   PreOrderTraversal(node -> left);
   PreOrderTraversal(node -> right);
 }
}

struct node* insertnode(struct node* root, char data){
	int y;
	if(root!=NULL)
  node *root = new node('a');
  else{
  	cout<<"Left(1) or right(2) of "<<root->data<<" ?"<<endl;
  	cin>>y;
  	if(y==1)
  	root=insertnode(root -> left,data);
  	else
 	root=insertnode(root -> right,data);
   }
   return root;
}

int main() {
  // The tree
  char c,y;
  node * root=NULL;
  while(1){
  cout<<"Insert nodes "<<endl;
  cin>>c;
  root=insertnode(root,c);
  
  cout<<"Want to add more nodes? Press 1";
  cin>>y;
  if(y!=1)
  break;
}
  queue <node*> Q;
  // Enqueue the root node
  Q.push(root);
  // Enqueue NULL to serve a partition between levels
  Q.push(NULL);
  while (!Q.empty()){
    // Dequeue the element from the front of the queue
    node *node = Q.front();
    Q.pop();
    if(node == NULL){
      // This shows that a level has finished, so enqueue
      // NULL to denote that.
      if(!Q.empty()){
      Q.push(NULL);
      }
    }
    else{
      // Peek at the element at the front of the queue and
      // set the right pointer to the adjacent element in the queue
      node -> right_neighbor = Q.front();
      // Enqueue its left and right children if they exist
      if(node -> left != NULL){
        Q.push(node -> left);
      }
      if(node -> right != NULL){
        Q.push(node -> right);
      }
    }
  }
  PreOrderTraversal(root);
  return 0;
}
