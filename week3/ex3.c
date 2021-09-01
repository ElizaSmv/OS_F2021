#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    struct Node* next;
};
typedef struct Node* List;

List create_node(int);
void print_list(List*);
void insert_node(List*, List);
void delete_node(List*, List);

int main() {
    List one = create_node(1);
    printf("Create:");
    print_list(&one);

    List two = create_node(3);
    insert_node(&one, two);
    printf("Add:");
    print_list(&one);

    List three = create_node(2);
    insert_node(&two, three);
    printf("Add:");
    print_list(&one);

    List four = create_node(8);
    insert_node(&one, four);
    printf("Add: ");
    print_list(&one);
    delete_node(&one, four);
    printf("Delete: ");
    print_list(&one);

    List five = create_node(8);
    delete_node(&one, five);
    printf("Delete: ");
    print_list(&one);
    return 0;
}

List create_node(int x) {
    List node = (List) malloc(sizeof(struct Node));
    node->x = x;
    node->next = NULL;
    return node;
}

void print_list(List* one) {
    List current = *one;
    while (current != NULL) {
        printf("%d ", current->x);
        current = current->next;
    }
    putchar('\n');
}

void insert_node(List* end, List node) {
    if (*end == NULL) {
        return;
    }
    if ((*end)->next == NULL) {
        (*end)->next = node;
    }
    else {
        node->next = (*end)->next;
        (*end)->next = node;
    }
}

void delete_node(List* one, List node) {
    // Deleting the first element in the list
    if (*one == node) {
        node->next = NULL;
        return;
    }
    List current = *one;
    List previous;
    while (current != NULL && current != node) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    previous->next = current->next;
    current->next = NULL;
}



