#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	int* data;	
	int height;	

} Node;
typedef struct List{
	Node* root;
	int size;

} List;

//Finds the max of two numbers
int max(int x,int y){
	
	return (x>y)?x:y;

}
int height(Node* ptr){

	if(ptr==NULL)
		return 0;	
	
	
	else{
		
		return 1 + max(height(ptr->left), height(ptr->right));

	}
}

List* createList(){
	List* ptr= malloc(sizeof(List));
	ptr->root=NULL;
	ptr->size=0;
	return ptr;
}

//returns the pointer to node
Node* createNode(Node* parent,int item){

	Node* ptr= malloc(sizeof(Node));
	int* data=malloc(sizeof(int));
	*data=item;
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->parent=parent;
	return ptr;

}



// calculates the balance factor of the tree with ptr as its root
int calcBF(struct Node *ptr)
{
    if (ptr== NULL)
        return 0;
    return height(ptr->left) - height(ptr->right);
}

/* After right rotation, 
* left child of the root becomes root
* right child of the root's left child becomes it's left child(i.e. new root)
* former root becomes the right child of its left child(i.e. new root)
* former root's right child remains the same but the right child of it's earlier left child is now its left child' '*/
Node* rotateRight(Node* ptr){ //ptr= initial root node


	Node* ptrleft=ptr->left; //left child of given root node
	Node* rightchild=ptrleft->right;// right child of the left child of given root node
	
	ptrleft->right=ptr;// the given root node is now the right child of its former left child
	ptrleft->parent=ptr->parent;
	ptr->parent=ptrleft;

	ptr->left=rightchild;// the left child of 	
	
	//recomputing the heights of ptr and rightchild
	ptr->height=height(ptr);
	rightchild->height=height(rightchild);
	return ptrleft; // ptrleft is now the new root

}


// Finds minimum element of a tree
Node* findMin(Node* ptr){
	
	if(ptr->left==NULL)
		return ptr;
	else
		return findMin(ptr->left);
} 

Node* rotateLeft(Node* ptr){

	Node* ptrright=ptr->right;// right child of root
	Node* leftchild= ptrright->left;// left child of root's right child
	
	ptrright->left=ptr;// root is now left child of it's  right child 	
	ptrright->parent=ptr->parent;
	ptr->parent=ptrright;
	ptr->right=leftchild;// the leftchild of root's right child is now root's right child
	if(leftchild!=NULL)
	    leftchild->parent=ptr;
	
	ptr->height=height(ptr);
	ptrright->height=height(ptrright);
	ptr->parent=ptrright;
	return ptrright;// right child of the root is new root
	
}

//returns root of the tree after balancing it
Node* balanceTree(Node* ptr,int data){

	int balance= calcBF(ptr);
		
		if (balance < -1 && data > *(ptr->right->data))// Right Right condition: Rotate left
       		 return rotateLeft(ptr);// return the root of node after left rotation
		
		
		if (balance > 1 && data < *(ptr->left->data))// Left Left condition: Rotate right
       	 	return rotateRight(ptr);//return the root of right after right rotation
		
		
		if (balance < -1 && data < *(ptr->right->data)) //Right Left condition
		{
		    ptr->right = rotateRight(ptr->right);
		    return rotateLeft(ptr);
		}
		
		if (balance > 1 && data > *(ptr->left->data))//Left Right condition
		{
		    ptr->left =  rotateLeft(ptr->left);
		    return rotateRight(ptr);
		}
		return ptr;


}
void insert(List* tptr,int item){
	Node* ptr=tptr->root;

	if(tptr->root == NULL) //The tree is currently empty
	{	
		
		ptr=createNode(NULL,item);
		tptr->root=ptr;
		(tptr->size)++;	
		
	}
	else
	{
		
		while(1){
			if(item < *(ptr->data))
			{
				if(ptr->left==NULL) //Reached the leaf node
				{
					Node* child= createNode(ptr,item);
					ptr->left=child;
					(tptr->size)++;	
					break;
				}
				else		
				{
					ptr=ptr->left;	
				}		
						
			}
			else
			{
				if(ptr->right==NULL)//Reached the leaf node
				{
					Node* child= createNode(ptr,item);
					ptr->right=child;
					(tptr->size)++;	
					break;
				}
				else		
				{
					ptr=ptr->right;	
				}			
			}
		}
	}
	ptr=tptr->root;
	ptr->height=height(ptr);
		
	Node* root= balanceTree(ptr,item);// returns the root of tree after balancing it
	tptr->root=root;
}


//Checks whether the item is present in tree or not.Initially,ptr is root of the tree
int lookup(Node* ptr,int item){
	
	if(ptr==NULL)
		{
			return 0;
		}
	if(*(ptr->data) ==item)
		return 1;
	else
	{
		if(item>*(ptr->data))
			return lookup(ptr->right,item);
		else
			return lookup(ptr->left,item);
	
	}

}

//returns the node on which the item is present
Node* findItem(Node* ptr,int item){
	
	if(*(ptr->data) ==item)
		return ptr;
	else
	{
		if(item>*(ptr->data))
			return findItem(ptr->right,item);
		else
			return findItem(ptr->left,item);
	
	}


}


//balances the tree for deletion
Node* balanceDel(Node* root){
	
	root->height=1+ max(height(root->left),height(root->right));
 	int balance = calcBF(root);
 	
	// Left Left Case
    if (balance > 1 && calcBF(root->left) >= 0)
        return rotateRight(root);
 
    // Left Right Case
    if (balance > 1 && calcBF(root->left) < 0)
    {
        root->left =  rotateLeft(root->left);
        return rotateRight(root);
    }
 
    // Right Right Case
    if (balance < -1 && calcBF(root->right) <= 0)
        return rotateLeft(root);
 
    // Right Left Case
    if (balance < -1 && calcBF(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
	return root;

}
// deletes the given item from BST

void deleteItem(List* list,Node* ptr,int item){
	
	if(lookup(ptr,item)==1)
	{
		Node* ptr1= findItem(ptr,item);// ptr1 is the node at which item was found
		int x=*(ptr1->data);
		//If ptr1 turns out to be a leaf node
		if(ptr1->left ==NULL && ptr1->right==NULL)
			{
				if(*(ptr1->parent->data) >item)
					ptr1->parent->left= NULL;			
				else
					ptr1->parent->right=NULL;
			
			}
			
		//If ptr1 has only one child
		
		else if(ptr1->left==NULL || ptr1->right==NULL)
		{
			if(ptr1->left==NULL)
			{
				Node* temp=ptr1->right;
				ptr1->data=temp->data;
				ptr1->right=temp->right;
				ptr1->left=temp->left;
				free(temp);
				
			}
		
			else
			{
				Node* temp= ptr1->left;
				ptr1->data=temp->data;
				ptr1->right=temp->right;
				ptr1->left=temp->left;
				free(temp);
					
			}
			
		
		}
		
		
		//If ptr1 has two children 
		
		else{
		
			Node* successor= findMin(ptr1->right); //finds the inorder successor of ptr1 (i.e. min element of the right subtree)
			
			//the inorder successor is its own child
			if(ptr1->left==successor||ptr1->right==successor){
			
				successor->parent=ptr1->parent;
				successor->left=ptr1->left;
				successor->right=ptr1->right->right;
				
			}
			else{
				//Removing the link between inorder successor node and its parent
				
				successor->parent->left=successor->right;
				successor->parent=NULL;
				
				//Making successor the parent of children of ptr1
				
				successor->left=ptr1->left;
				successor->right=ptr1->right;
				ptr1->right->parent=successor;
				ptr1->left->parent=successor;
			}
			
			if(list->root==ptr1) //if ptr is root of tree
				list->root=successor;
			
			else{
				
				//Making successor children of ptr1's parent
				if(*(ptr1->parent->data)> item)
					ptr1->parent->left = successor;
				else
					ptr1->parent->right = successor;
			
			}
			free(ptr1);
		}
	
 	
	}
	
	// Now, balancing the tree
	
	Node* root= list->root;
	Node* newroot=balanceDel(root);
	list->root=newroot;

}


void printSorted(Node* ptr){
	
	if(ptr==NULL)
		return;	
	else if(ptr->left==NULL && ptr->right==NULL){
		
		printf("%d ",*(ptr->data));
	}
	else {
		printSorted(ptr->left);
		printf("%d ",*(ptr->data));
		printSorted(ptr->right);
	
	}	
}



int main(){

	List* mylist=createList();
	int input,n;
	Node* root;
	while(1){
		scanf("%d",&input);
		switch(input){
			case 1:
				scanf("%d",&n);
				insert(mylist,n);
				break;
			case 2:
				scanf("%d",&n);
				root=mylist->root;
				deleteItem(mylist,root,n);
				break;
			case 3:
				scanf("%d",&n);
				root=mylist->root;
				printf("%d ",lookup(root,n));
				break;	
			case 4:
				root=mylist->root;
				printf("%d ",height(root));
				break;	
			case 5:
				root=mylist->root;
				printSorted(root);
				break;	
		
			case -1:
				exit(0);
		}
	
	
	
	
	}	
	 	return 0;
}