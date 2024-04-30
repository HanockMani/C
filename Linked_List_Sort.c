#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;
node *head=NULL;
void insert(int e){
    node *t=head;
    if(head==NULL){
        head=(node*)malloc(sizeof(node));
        head->data=e;
        head->next=NULL;
    }
    else{
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=(node*)malloc(sizeof(node));
        t->next->data=e;
        t->next->next=NULL;
    }
}

void sort_swap_values(){
    node *c, *n, *x=head;
    int temp;
    while(x!=NULL){
        c=head;
        while(c->next!=NULL){
            n=c->next;
			if(c->data > n->data){
                temp=c->data;
                c->data=n->data;
                n->data=temp;
            }
            c=c->next;
        }
        x=x->next;
    }
}

void sort_swap_adress(){
	node *p, *c, *n, *x;
    x=head;
    while(x!=NULL){
        c=head;
        while(c->next!=NULL){
        	n=c->next;
            if(c->data > n->data){
                if(c==head){
                	c->next=n->next;
                	n->next=c;
                	head=n;
				} 
				else{
					c->next=n->next;
                	n->next=c;
                	p->next=n;
				}
				p=n;
            }
            else{
            	p=c;
            	c=c->next;	
			}
        }
        x=x->next;
    }
}

void display(){
    node *t=head;
    if(head==NULL){
        printf("Empty Linked List!");
    }
    else{
        printf("\nLinked List Elements are: ");
        while(t!=NULL){
            printf("%d\t",t->data);
            t=t->next;
        }    
    }
}

int menu(){
    int ch;
    printf("\nMenu\n_______\n[1] Insert\n[2] Display\n[3] Sort(Values)\n[4] Sort(Adress)\n[5] Exit\nEnter your choice: ");
    scanf("%d",&ch);
    return ch;
}

int main(){
    int ch,e;
    for(ch=menu();ch!=5;ch=menu()){
        switch(ch){
            case 1: printf("\nEnter element to insert: ");
                    scanf("%d",&e);
                    insert(e);
                    break;
            case 2: display();
                    break;
            case 3: sort_swap_values();
                    break;
            case 4:	sort_swap_adress();
            		break;
            default:printf("Invalid Entry!");
                    break;
        }
    }
    return 0;
}
