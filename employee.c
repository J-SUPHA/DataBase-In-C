#include "employee.h"
EMPLOYEE* list_of_employees=NULL;

void printEmployee(EMPLOYEE e){ //done
	printf("Name: %s ",e.name);
	printf(", ID: %d\n",e.id);//printing the name
	PAYMENT *M = (PAYMENT*)malloc(sizeof(PAYMENT));
	M = e.payments;
	if (M==NULL){
		printf("No Payments\n");
		printf("===============================================\n");
		return;
	}
	printf("-------------------------------------------\n");
	printf("DATE");
	printf("\t\t\tAMOUNT\n");
	printf("---------");
	printf("\t\t---------\n");
	while(M!=NULL){
		printf("%s",M->date);
		printf("\t\t%f\n",M->amount);
		M=M->next;//moving pointer
		} 
	printf("===============================================\n");

}

void addEmployee(int e_id, char* e_name){//done add to beginning as case implies
	EMPLOYEE * Y = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));
	Y->name = e_name;
	Y->id = e_id;
	Y->next = list_of_employees;
	list_of_employees = Y;
	
}

void printEmployees(){ //not even close
    EMPLOYEE * M =(EMPLOYEE*) malloc(sizeof(EMPLOYEE)); 
    M = list_of_employees;
	if (M==NULL){
		printf("This list is empty");
		return;
		}
    while(M!=NULL){
		printEmployee(*M);
		M=M->next;

	} 
}

int addPayment(int e_id, char* p_date, float p_amount){
	EMPLOYEE * Y = (EMPLOYEE *) malloc(sizeof(EMPLOYEE));
	Y = list_of_employees;//creating the employee traverser 
	PAYMENT * R = (PAYMENT *) malloc(sizeof(PAYMENT)); //creating the payment traverser
	R->date = p_date; //allocating the data
	R->amount = p_amount;
	while (e_id!=Y->id && Y!=NULL){//searching for the the corresponding employee
	Y=Y->next; 
	}
	if (Y==NULL){
			return 0;//case when employee not found  
		}else{
			R->next=Y->payments;//inserting lastest payment at the front of the payment linkedlist
			Y->payments = R; //employee will reference the latest payment
			return 1;
		}
}

int deleteEmployee(int e_id, char* e_name){
	EMPLOYEE *Prev = NULL;
	EMPLOYEE *Post = list_of_employees;
	PAYMENT *pidder = (PAYMENT*) malloc(sizeof(PAYMENT));//two pointers used to free payments space
	PAYMENT *ridder = (PAYMENT*) malloc(sizeof(PAYMENT));
	if (Post!=NULL && Post->name==e_name && Post->id==e_id){
		ridder=Post->payments;
		while (ridder!=NULL){
			pidder = ridder;
			ridder = ridder ->next;
			free(pidder);
		}
		Post->payments=NULL; //making payments null so they don't pop up again
		list_of_employees = Post->next;
		free(Post);
		return 1;
	}
	while(Post->id != e_id && Post!=NULL){
		Prev = Post;
		Post = Post->next;
		}
	if (Post==NULL){ return 0;}//case that the employee to delete is not found
	ridder=Post->payments;
		while (ridder!=NULL){
			pidder = ridder;
			ridder = ridder ->next;
			free(pidder);
		}
	Post ->payments=NULL;
	Prev->next = Post->next;
	free(Post);
	return 1;
}