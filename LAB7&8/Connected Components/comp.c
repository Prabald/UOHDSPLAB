#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int endnode; // stores the other end of the node
    struct Node* next;// stores the end of 
}Node;


typedef struct AdjList{
    
    struct Node* head;
    int visited;//visited=1 , not visited=0
    
    
    
} AList;

void initList(AList** list,int size);
AList** createList(int size);
Node* createNode(int end);
void append(AList* list, Node* new );
void populateList(FILE* fd,AList** list,int size);
void printList(AList** list, int size);
void DFS(AList** list,int i);
int countComponents(AList** list,int size);
void freeList(AList** list,int size);

//initializes the each adjlist array's visited to 0
void initList(AList** list,int size){
	for(int i=1; i<=size;i++){
		list[i]->head=NULL;
		list[i]->visited=0;
	}


}



// Creates the adjacency list dynamically
AList** createList(int size){
	AList** new= malloc(sizeof(AList*)*(size+1));
	for(int i=0;i<=size;i++)
	{
		new[i]=malloc(sizeof(AList));
	
	}
	initList(new,size);
	return new;

}

// creates a new node and returns a pointer to it
Node* createNode(int end){
	
	Node* new=malloc(sizeof(Node));
	new->endnode=end;
	new->next=NULL;
	return new;
}


// Appends the given node to given list
void append(AList* list, Node* new ){

	Node* ptr=list->head;
	
	if(ptr==NULL){ //the vertex isn't connected to any other vertex yet i.e. list is null
		list->head=new;
	}
	else{
		
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			
		}
		ptr->next=new;
	
	
	}


}

// Populates the adjacency list by taking input from file
void populateList(FILE* fd,AList** list,int size){

	int v1,v2;
	while(feof(fd)==0){
        
        fscanf(fd,"%d",&v1);
        fscanf(fd,"%d",&v2);
      //  printf("%d %d \n",v1,v2);
        if(v1>size || v2>size)
        	{
        		printf("Invalid vertex");
        		return;
        	}
        Node* v1node=createNode(v2);
        Node* v2node=createNode(v1);
        append(list[v1],v1node);
		append(list[v2],v2node);     
    }

}


// This function prints the contents of list. Created for debugging purposes
void printList(AList** list, int size){

	for(int i=1;i<=size;i++){
	
		
		Node* ptr=list[i]->head;
		printf("Vertex %d Visited:%d Edges:",i, list[i]->visited);
		while(ptr!=NULL){
			printf(" %d %d ",i,ptr->endnode);
			ptr=ptr->next;
		
		}
		printf("\n");
	
	}




}

// It runs DFS recursively on the given graph, marking the nodes as visited on encountering them

void DFS(AList** list,int i){
	
	if(list[i]->visited==1) // If the node has already been visited then there's no point exploring its edges
		return;
	list[i]->visited=1; 
	
	Node* ptr=list[i]->head;//ptr will be used to explore all the neighbors of node i
	while(ptr!=NULL){
			int end=ptr->endnode; // vertex which is on the other end of edge from node i (i.e. Edge: i --> end)
			DFS(list,end); //
			ptr=ptr->next;
		}
}

//returns the number of components in the given graph 
int countComponents(AList** list,int size){
	int count=0;
	for(int i=1;i<=size;i++){	
		if(list[i]->visited==1)// If the node is already visited then its already in some component
			continue;
		count++;// If the node is not visited then it means that its part of a separate component
		DFS(list,i);// Run DFS on present node, marking every node on the way as visited. 
		
		/*After this,in the next iteration of this loop if some node is still unvisited, then 
		  it means that the node belongs to a separate component*/
	}
	return count;//count: number of components
}

// free the memory allocated for entire list
void freeList(AList** list,int size){

	free(list[0]);
	for(int i=1;i<=size;i++){
		Node* ptr=list[i]->head;
		while(ptr!=NULL){
			Node* temp= ptr;
			ptr=ptr->next;
			free(temp);
		}
		free(list[i]);
	}

	free(list);
}






int main(int argc,char** argv){
    
    FILE* fd=fopen(argv[1],"r");
    if(fd==NULL){
        printf("File not opened");
        exit(1);
    }
    int n,e;
    
    /*Read the number of vertices and edges*/
    fscanf(fd,"%d",&n); //n: number of vertices
   	fscanf(fd,"%d",&e); //e: number of edges
   	
   	/*Create the adjacency list and read data from file to populate the list*/
    AList** list= createList(n);
    populateList(fd,list,n);
    
    /*Count the number of components in respective graph*/
    printf("%d",countComponents(list,n));
    
	freeList(list,n);// free the list
    fclose(fd);
    
}