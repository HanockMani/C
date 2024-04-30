#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct node{
	char name[20];
	struct node *next;
};
typedef struct node node;
node *head;

void insert(char name[]){
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		strcpy(head->name,name);
		head->next=NULL;
	}
	else{
		node *t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		strcpy(t->next->name,name);
		t->next->next=NULL;
	}
}

void delete_spec(char name[]){
	if(head==NULL)
		printf("\nEmpty List");
	else if(strcmp(head->name,name)==0 && head->next==NULL){
		head=NULL;
		printf("\nName Deleted!");
	}
	else if(strcmp(head->name,name)==0){
		head=head->next;
		printf("\nName Deleted!");
	}
	else{
		node *t=head;
		while(t->next!=NULL){
			if(strcmp(t->next->name,name)==0){
				t->next=t->next->next;
				printf("\nName Deleted!");
				break;
			}
			t=t->next;
			if(t->next==NULL)
				printf("\nName not found");
		}
	}
}

void reverse(){
	node *p, *c, *n;
	c=head;
	while(c!=NULL){
		if(c==head){
			c=c->next;
			p=head;
		}
		else{
			n=c->next;
			c->next=p;
			p=c;
			c=n;
		}
	}
	head->next=NULL;
	head=p;
	printf("\nReversed the list!");
}

void sort(){
	node *t, *t1;
	char temp[20];
	int count=0, count1=0;
	t1=head;
	while(t1->next!=NULL){
		t=head;
		while(t->next!=NULL){
			if(strcmp(t->name,t->next->name) > 0){
				strcpy(temp,t->name);
				strcpy(t->name,t->next->name);
				strcpy(t->next->name,temp);
			}
			t=t->next;
		}
		t1=t1->next;
	}
	printf("\nSorted the list!");
}

void count(){
	node *t=head;
	int count=0;
	while(t!=NULL){
		count++;
		t=t->next;
	}
	printf("\nNumber of names in list: %d",count);
}

void display(){
	node *t=head;
	if(head==NULL)
		printf("\nEmpty List");
	else{
		while(t!=NULL){
			printf("%s\t",t->name);
			t=t->next;
		}
	}		
}

int menu(){
	int ch;
	printf("\n\nMenu\n_______\n[1] INSERT\n[2] DELETE\n[3] REVERSE\n[4] SORT\n[5] COUNT\n[6] DISPLAY\n[7] EXIT\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int ch;
	char name[20];
	for(ch=menu();ch!=7;ch=menu()){
		switch(ch){
			case 1: printf("\nEnter name to insert: ");
					scanf("%s",&name);
					insert(name);
					break;
			case 2: printf("\nEnter name to delete: ");
					scanf("%s",&name);
					delete_spec(name);
					break;
			case 3:	reverse();
					break;
			case 4: sort();
					break;
			case 5:	count();
					break;
			case 6: display();
					break;
			default:printf("Invalid Entry!");
				break;
		}
	}
	return 0;
}
