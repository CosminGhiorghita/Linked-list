#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
}node;

void addFirst(node **head, int num )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->value=num;
    if ((*head)== NULL)
    {
    (*head)=temp;
    (*head)->next=NULL;
    }
    else
    {
    temp->next=(*head);
    (*head)=temp;
    }
}

void addNodeBottom(node **head, int val){

    //create new node
    node *newNode = (node*)malloc(sizeof(node));

    if(newNode == NULL){
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(-1);
    }

    newNode->value = val;
    newNode->next = NULL;  
	
	  //check for first insertion
	if ((*head)==NULL){
		*head = newNode;
		//printf("added at beginning\n");
		return;
	}
	
    else
    { 
        node *current = *head;
  		while (current->next != NULL) {
    		current = current->next;
  		}
  		current->next = newNode;
  		//printf("added later\n");
        }
}

/* Function to reverse the linked list */
void reverse(node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void add1(node **head)
{
	if((*head)==NULL)
		return;
	
	node *aux = *head;
	while(aux->next != NULL)
		aux = aux->next;
		
	if (aux->value != 9) // daca ultima cifra e diferita de 9
		aux->value = aux->value + 1;
	else {
		reverse(head);
		
		if ((*head)->next == NULL){ // daca lista contine doar 9
			(*head)->value = 0;
			node *new = malloc(sizeof(node));
			new->value = 1;
			new->next = NULL;
			(*head)->next = new;
		} else {
			aux = *head;
			aux->value = aux->value + 1;
			while(aux->next != NULL){
				if(aux->value == 10){
					aux->value = 0;
					aux->next->value += 1;
				}
				aux = aux->next;
			}
			
			if(aux->value == 10){ //daca si prima 'cifra' este 10 atunci trebuie sa adaugam un nou nod . caz 999 + 1 = 1000
				aux->value = 0;
				node *new = malloc(sizeof(node));
				new->value = 1;
				new->next = NULL;
				aux->next = new;
			}
		}
		reverse(head);	
	}
}

void show(node *head)
{
	node *aux = head;
	while(aux!= NULL){
		printf("%d ", aux->value);
		aux = aux->next;
	}
	printf("\n");
}


int main()
{	
	long int numar;
	printf("Introduceti un numar cu cel mult 9 cifre: "); scanf("%ld", &numar);
	
	node *head = NULL;
	
	int c;
	LOOP: while(numar){
			c = numar % 10;
			addFirst(&head, c);
			numar = numar / 10;
		}
		
	if(head != NULL){
		printf("Numarul initial era: "); show(head);
		add1(&head);
		printf("Numarul +1 este:     "); show(head);
	} else {
		printf("Zero este o valoare invalida! \n");
		printf("Introduceti un numar cu cel mult 9 cifre, diferit de 0: "); scanf("%ld", &numar);
		goto LOOP;
	}
	
	getch();
}
