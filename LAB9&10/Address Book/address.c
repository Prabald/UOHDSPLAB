#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct record{
	char rno[11];
	char email[256];
	char name[30];
	char phone[11];
}record;

/* This program takes command line arguments. So specify the name of .dat file which is to be used for storing student records */





//Initialize the file i.e.Renames the original file to temp.dat and then creates a new file with the name of original file. Then it copies the 
//records in it temp.dat whose roll no. is not marked as #DELETED
void initFile(char* file){

	rename(file,"temp.dat");
	FILE* fp= fopen(file,"a+");
	FILE* tmp=fopen("temp.dat","a+");
	record input;
	char delrno[11]="#DELETED";
	 while(fread(&input,sizeof(record),1,tmp)==1){
	
	 	if(strcmp(delrno,input.rno)!=0){
	 	
	 		fwrite(&input,sizeof(record),1,fp);
	 	}
		
	 }
	 fclose(fp);
	 fclose(tmp);
	 remove("temp.dat");
	



}
//displays the content of entire file
void displayContent(char* file){
	
	FILE* fp= fopen(file,"r+");	
	
	 record input;
	 printf("\n\n");
	 while(fread(&input,sizeof(record),1,fp)==1)
	 {
	 	printf("Name:%s Phone:%s rno:%s email:%s\n",input.name,input.phone,input.rno,input.email);
	 
	 
	 }
	 printf("\n\n");
	fclose(fp);
}

// Adds a record to the file
void addRecord(FILE* fp){

	record new;
	
	printf("Enter the roll number\n");
	scanf("%s",new.rno);
	
	printf("Enter the name\n");
	scanf("%s",new.name);
	
	printf("Enter the phone number\n");
	scanf("%s",new.phone);
	
	printf("Enter the email address\n");
	scanf("%s",new.email);
	
	fwrite(&new,sizeof(record),1,fp);

}
// Searches a record in file using student name
void search(char* file,char name[30]){
	
	FILE* fp= fopen(file,"r+");	
	record in;
	int flag=0;
	int reccount=1;
	while(fread(&in,sizeof(record),1,fp)==1){
		if(strcmp(name,in.name)==0){
			flag=1;
			printf("\n\n");
			printf("Successfully found the student record. It is record number %d\n", reccount);
			printf("Name: %s Roll No: %s Phoneno: %s Email: %s ",in.name,in.rno,in.phone,in.email);
			printf("\n\n");
			
		}
		reccount++;
	
	}
	
	if(flag==0){
		printf("\n\n");
		printf("No student with such name found\n");
		printf("\n\n");
	}
	fclose(fp);

}

//Deletes a record from the file by marking it as #DELETED. It'll be deleted by the initFile() function in next run of the program
void deleteRecord(char* file, char rno[11]){
	
	FILE* fp= fopen(file,"r+");	
	record in;
	int flag=0;
	while(fread(&in,sizeof(record),1,fp)==1){
		
		
		if(strcmp(rno,in.rno)==0){
		
			flag=1;
			
			
			fseek(fp,-(sizeof(record)),SEEK_CUR);// takes the filepointer to the beginning of record which we just read
			strcpy(in.rno,"#DELETED");
			fwrite(&in,sizeof(record),1,fp);
			printf("Deleted\n");
			
		
		}
	}
	if(flag==0)
			printf("No student with such roll no found\n");
		fclose(fp);

}

//Modifies the record with given roll number if found
void modifyRecord(char* file,char rno[11]){
	
	FILE* fp= fopen(file,"r+");	
	record in;
	int flag=0;
	while(fread(&in,sizeof(record),1,fp)==1){
		
		
		if(strcmp(rno,in.rno)==0){
		
			flag=1;
			record new;
			printf("Record found. Enter the details of new record\n");
			fseek(fp,-(sizeof(record)),SEEK_CUR);// takes the filepointer to the beginning of record which we just read
			printf("Enter the roll number\n");
			scanf("%s",new.rno);
			
			printf("Enter the name\n");
			scanf("%s",new.name);
			
			printf("Enter the phone number\n");
			scanf("%s",new.phone);
			
			printf("Enter the email address\n");
			scanf("%s",new.email);
			
			fwrite(&new,sizeof(record),1,fp);
			
		
		}
	
	}
	if(flag==0)
		printf("No student with such roll no found\n");
	fclose(fp);
}



int main(int argc,char** argv){
	
	if(argc!=2){
		printf("Invalid number of arguments");
		exit(1);
	}
	
	FILE* fp;
	initFile(argv[1]);// Removes the records which are to be deleted
	int choice=0;
	char tname[30],trno[11];
	while(1)
		{
			printf("Enter your choice from the following options\n 1. Add the details of a student\n");
			printf("2. Modify a student record\n3. Search for a student using name\n 4. Delete the details of a student\n5. Display database content\n-1.Exit\n");
			scanf("%d",&choice);
			
			switch(choice){
			
				case 1: // Add a record
					fp= fopen(argv[1],"a+");
					displayContent(argv[1]);
					addRecord(fp);
					fclose(fp);
					break;
				
				case 2: //Modify a record
					
					printf("Enter the roll number of student which you want to modify\n");
					scanf("%s",trno);
					modifyRecord(argv[1],trno);
					break;
					
				case 3: //Search for a record
					printf("Enter the name of student which you want to search for\n");
					scanf("%s",tname);
					search(argv[1],tname);
					break;
					
				case 4: // Delete a record
					printf("Enter the roll number of student which you want to delete\n");
					scanf("%s",trno);
					deleteRecord(argv[1],trno);
					break;
					
				case 5: //Display the contents of a record
						displayContent(argv[1]);
				 	break;
				 	
				case -1: // Exit case. It'll be handled later after the switch block
					break;
				default://Invalid Input
					printf("Invalid input! Enter a valid input\n");
					break;			
			}
		
			if(choice==-1) //If user chose to exit, it'll exit the looop
				break;
		
		}
	
}