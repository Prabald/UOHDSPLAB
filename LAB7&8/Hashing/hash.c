#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
//generates the hash 
 int getHash(char* email){
	int len= strlen(email);
	 int hash=1;
	for(int i=0;i<len;i++)
	{
		hash= hash + i*email[i];
	}
	return hash%100;
}

//debugging function to view the contents of hashtable
void printHT(char hashtable[100][256]){
	
	for(int i=0;i<100;i++){
		if(hashtable[i]==NULL)
			continue;
		printf("%s\n",hashtable[i]);
	}

}


//returns -1 if table is full
int linearProbe(char hashtable[100][256],int i,char email[256]){
	
	int ctr=1;
	char* defval=" ";
	while(ctr<=100){
		i=(i+1)%100;
		if(strcmp(hashtable[i],defval)==0)// slot is empty
		{
			strcpy(hashtable[i],email);
			printf("Inserted via probing %s i: %d\n",email,i);
			return 0;
		}
		else if(strcmp(hashtable[i],email)==0){
			//This means that the string read is a duplicate
			return 0;
		}
		
		ctr++;
	
	
	}

	return -1; //No empty slots left
 
}
//Initializes all slots inside hash table
void initHT(char hashtable[100][256]){
	for(int i=0;i<100;i++){
		
		strcpy(hashtable[i]," ");
	}

}

//populates data in hash table
void populateHashtable(char hashtable[100][256],FILE* fd){
	initHT(hashtable);
	int hash;
	char* defval=" ";
	while(feof(fd)==0){
		char email[256];
		fscanf(fd,"%s",email);
		fscanf(fd,"\n");
		
		hash= getHash(email);
		
		if(strcmp(hashtable[hash],defval)==0)
		{
			printf("Inserted %s Hash: %d\n",email,hash);//printf("Slot empty: In table: %s In input:%s hash:%d\n",hashtable[hash],email,hash);
			strcpy(hashtable[hash],email);
			
		}
		else if(strcmp(hashtable[hash],email)!=0)
			{
				
				linearProbe(hashtable,hash,email);
				
			}		

	}

}

//Write to the output file
void writeOutput(char hashtable[100][256],FILE* fout){
	char* defval=" ";
	for(int i=0;i<100;i++){
		if(strcmp(hashtable[i],defval)==0)
			continue;
		fprintf(fout,"%s\n",hashtable[i]);
	
	}


}

/*Input file is the first command line argument and output file is the secon one*/

int main(int argc,char** argv){
	char hashtable[100][256];
	//int hash;
	
	FILE* fin =fopen(argv[1],"r");
	FILE* fout=fopen(argv[2],"w+");
	if(fin==NULL ||fout==NULL){
		printf("File not read");
		exit(0);
	}
	populateHashtable(hashtable,fin);// read the data from input file and add it to hashtable
	writeOutput(hashtable,fout);// write the date from hashtable to output file
	
	fclose(fin);
	fclose(fout);


}