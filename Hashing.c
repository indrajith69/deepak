#include <stdio.h>
#include<stdlib.h>

int size = 0;

int hashcode(int key) {
	return (key % size);
}

struct node {
   int data;
   struct node *next;
};

struct hashtable {
    struct node *key;
};

struct hashtable *htable;


void insert(int key){
    int index = hashcode(key);
    if (htable[index].key==NULL) {
        struct node *link = (struct node*) malloc(sizeof(struct node));

        link->data = key;
        link->next = NULL;

        htable[index].key=link;
        printf("if condition is working");
    }
    else{
        struct node *ptr = (struct node*) malloc(sizeof(struct node));
        struct node *link = (struct node*) malloc(sizeof(struct node));

        link->data = key;
        link->next = NULL;

        ptr = htable[index].key;

        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = link;
    }
};

void display(){
    int i;
    for (i = 0; i < size; i++) {
        struct node *ptr =htable[i].key;
        while(ptr != NULL) {
            printf("(%d) ",ptr->data);
            ptr = ptr->next;
        }
    }
}



void main() {
    int i,x;

	printf("enter the no of elements to store in the hash table: ");
    scanf("%d", &size);

    htable = (struct hashtable*) malloc(size * sizeof(struct hashtable));

    for (i = 0; i < size; i++) {
        printf("enter key: ");
        scanf("%d",&x);
        insert(x);
    }
    display();
}
