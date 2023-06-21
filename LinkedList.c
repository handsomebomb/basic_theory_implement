#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    union {
        unsigned int all;
        struct{
            unsigned int gin    : 5;
            unsigned int rum    : 5;
            unsigned int vodka  : 5;
            unsigned int brandy : 5;
            unsigned int whisky : 5;
            unsigned int tequila: 5;
            unsigned int rsvd   : 2;
        }b;
    }data;
    struct node* next;
}node;

void insertAtEnd(node** head_ref, unsigned int new_data);
void displayList(node* node);

int main()
{
    struct node* head = NULL;
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 25);
    
    displayList(head);
    printf("Hello World");

    return 0;
}

void insertAtEnd(node** head_ref, unsigned int new_data) {

    node* new_node = (node*)malloc(sizeof(node));
    node* last = *head_ref;
    new_node->data.all = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void displayList(node* node) {
    while (node != NULL) {
        printf("All: %d ",     node->data.all);
        printf("Gin: %d ",     node->data.b.gin);
        printf("Rum: %d ",     node->data.b.rum);
        printf("Vodka: %d ",   node->data.b.vodka);
        printf("Brandy: %d ",  node->data.b.brandy);
        printf("Whisky: %d ",  node->data.b.whisky);
        printf("Tequila: %d ", node->data.b.tequila);
        printf("\n");
        node = node->next;
    }
    printf("\n");
}
