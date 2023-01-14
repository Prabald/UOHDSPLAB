#include<stdio.h>
#include<stdlib.h>
/*
So, we've to make a structure that maintains disjoint sets and use that to find MST in a graph. So, first we need a graph structure containing all the vertices and edges. 
An edge structure to store the edge endpoints and weight.
*/

typedef struct edge{
	int source;//source end point
	int end;// other endpoint
	int weight;//weight of edge
} Edge;



typedef struct Graph{
	int* V;// Number of Vertices
	int* E;// Number of Edges
	struct edge* edges;// Array of edges

} Graph;


typedef struct subset {
    int rep;//representative of the subset
    int rank;//rank of the subset
}subset;


Graph* initGraph(int v,int e){
	
	Graph* graph = malloc(sizeof(Graph));
	graph->edges=malloc(sizeof(Edge)*(e+1));
	graph->V= malloc(sizeof(int));
	graph->E=malloc(sizeof(int));
	*(graph->V)=v;
	*(graph->E)=e;
	return graph;
}
// Initializes the subsets array
void initSubsets(subset* subsets,int v,int e){

	for (int i=0;i<v;i++) {
        subsets[i].rep = i;
        subsets[i].rank = 0;
    }
}
void getEdges(Graph* graph,FILE* fp){
	
	int s,e,w;
	int i=1;
	Edge* edges= graph->edges;
	while(feof(fp)!=1)	
	{
		//getting source node of edge
		fscanf(fp,"%d",&s);
		edges[i].source=s;
		//getting end node of edge
		fscanf(fp,"%d",&e);
		edges[i].end=e;
		//getting weight of the edge
		fscanf(fp,"%d",&w);
		edges[i].weight=w;
		i++;
		printf("Source:%d End: %d Weight:%d\n",s,e,w);
	}

}


//returns the set representative of s
int find(subset* sub, int s)
{
   //
    if (sub[s].rep != s)//If the set representative of s is not s itself
        sub[s].rep = find(sub, sub[s].rep);// recursively find the set representative
    return sub[s].rep; //return the set representative
}


//unions a and b using rank
void findUnion(subset subsets[], int a, int b)
{
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[a].rank >subsets[b].rank)
        subsets[b].rep = a;
        
    else if (subsets[a].rank > subsets[b].rank)
        subsets[a].rep = b;
    // If ranks are same, then make one as root and
    // increment its rank by one
    else {
        subsets[b].rep = a;
        subsets[a].rank++;
    }
}



void sortEdges(Graph* graph){

  Edge* edges=graph->edges;
  Edge temp;
  
  //sorts the edges using bubble sort
  for (int i = 1; i <=*(graph->E); i++)
    for (int j = 1; j <=*(graph->E)-i; j++)
      if (edges[j].weight > edges[j+1].weight) {
        temp = edges[j];
        edges[j] = edges[j+1];
        edges[j+1]=temp;
      }





}
//Prints the content of graph
void printGraph(Graph* graph){
	Edge* edges= graph->edges;
	for(int i=1;i<=*graph->E;i++){
		printf("Weight: %d\t %d -> %d \n",edges[i].weight,edges[i].source,edges[i].end);
	
	}

}


void printMST(Edge edgelist[],int count,int weight){
	printf("Edges of the MST {");
	for(int i=0;i<count;i++){
		if(i!=count)
			printf("(%d,%d),",edgelist[i].source,edgelist[i].end);
		else
			printf("(%d,%d)",edgelist[i].source,edgelist[i].end);

	}
	printf("}, Total Weight: %d",weight);

}



//finds the MST using Kruskal's algo and prints it
void findMST(Graph* graph)
{
	
	int V=*graph->V;
    // Allocate memory for creating V sets
    subset* subsets = (subset*)malloc((V+1)* sizeof(subset));
    //initSubsets(subsets,*graph->E,*graph->E);
    int count=0, weight=0;
    Edge edgelist[*(graph->E)];
    Edge* edges=graph->edges;
     for (int v = 0; v <=V; ++v) {
        subsets[v].rep = v;
        subsets[v].rank = 0;
    }
    
    // Iterate through all edges of graph, find sets of both
    // vertices of every edge, if sets are same, then there
    // is cycle in graph.
    for (int i = 0; i < *(graph->E);i++) {
        //finds the set representative for source node
        int s = find(subsets, graph->edges[i].source);
        //finds the set representative for end node
        int e= find(subsets, graph->edges[i].end);
	
//The following condition is true when the set representatives of a and b are same i.e. both belong to the same set
        if (s != e)// If both ends of an edge don't belong to the same set then it means that there is no cycle and the edge can be added to MST
         {
         		edgelist[count].source=edges[i].source;
         		edgelist[count].end=edges[i].end;
         		edgelist[count].weight=edges[i].weight;
         		count++;
         		weight+=edges[i].weight;
         		printf("Added %d->%d to mst. Weight:%d\n",edges[i].source,edges[i].end,weight);
         		
         		
         
         }
        //If there's no cycle being created on adding both ends of this edge, then we can add them to same set
        findUnion(subsets, s, e);
    }
    printf("\n\n\n");
    printMST(edgelist,count,weight);
   
}

void freeGraph(Graph* graph){

	free(graph->edges);
	free(graph);


}


int main(int argc,char** argv){

	if(argc<2){
		printf("Invalid command line arguments");
		exit(0);
	}
	
	FILE* fp=fopen(argv[1],"r");
	int v,e;
	fscanf(fp,"%d",&v);
	
	fscanf(fp,"%d",&e);
	printf("Vertices:%d Edges:%d\n",v,e);
	
	Graph* graph=initGraph(v,e);
	getEdges(graph,fp);// reads the data of graph from file
	printGraph(graph);// printing the data read from file
	printf("\n\n\n");
	printf("Sorting edges for applying Kruskal's algorithm\n");
	sortEdges(graph);// sorting the edgelist
	printf("\n\n\n");
	printf("After sorting\n");
	printGraph(graph);// printing the sorted edges
		printf("\n\n\n");
	findMST(graph);//finds the MST using Kruskal's algorithm
	freeGraph(graph);


	fclose(fp);
}