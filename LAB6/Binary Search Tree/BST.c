#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	int* data;	
	

} Node;
typedef struct BST{
	struct Node* root;
	int size;


} BST;



/* Creates & initializes a node and then returns pointer to it*/
Node* createNode(Node* parent,int data){
	Node* ptr= malloc(sizeof(Node));
	int* n=malloc(sizeof(Node));
	*n=data;	
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->data=n;
	ptr->parent=parent;
	return ptr;
}


/*Creates & initializes a BST and returns the pointer to it*/
BST* createBST(){
	BST* ptr=malloc(sizeof(BST));
	ptr->root=NULL;
	ptr->size==0;
	return ptr;
}


//Inserts an item into the Binary Search Tree
void insert(BST* tptr,int item){
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

}

//Finds the max of two numbers
int max(int x,int y){
	
	return (x>y)?x:y;

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


// Finds height of the tree. Initially,ptr is root of the tree
int height(Node* ptr){

	if(ptr==NULL)
		return 0;	
	
	
	else{
		
		return 1 + max(height(ptr->left), height(ptr->right));

	}
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


// Finds minimum element of a tree
Node* findMin(Node* ptr){
	
	if(ptr->left==NULL)
		return ptr;
	else
		return findMin(ptr->left);
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

// deletes the given item from BST

void deleteItem(BST* bst,Node* ptr,int item){
	
	if(lookup(ptr,item)==1)
	{
		Node* ptr1= findItem(ptr,item);// ptr1 is the node at which item was found
		
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
			
			if(bst->root==ptr1) //if ptr is root of tree
				bst->root=successor;
			
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



}

void freeBST(Node* ptr){
    
    if(ptr==NULL)
        return;
    if(ptr->left==NULL& ptr->right==NULL){
        free(ptr->data);
        free(ptr);
        
    }
    else{
        freeBST(ptr->left);
        freeBST(ptr->right);
        free(ptr->data);
        free(ptr);
    }
    
    
    
    
}




int main(){

	BST* bst=createBST();
	Node* root;
	int input,n;
	scanf("%d",&input);
	
	while(1){
		root=bst->root;
		switch(input)
		{
			case 1:
				
				scanf("%d",&n);
				insert(bst,n);		
			
				break;
			
			case 2:
			
				scanf("%d",&n);
				deleteItem(bst,root,n);
				break;
			
			case 3:
				
				scanf("%d",&n);
				printf("%d ",lookup(root,n));
				break;
			
			case 4:
				printf("%d ",(height(root)-1));
				break;
			
			case 5:
				printSorted(root);
				break;
			
			case -1:
				exit(0);
		}	
		
		scanf("%d",&input);
		
		
		
	}
	freeBST(bst->root);
	free(bst);
	
	
	


}
