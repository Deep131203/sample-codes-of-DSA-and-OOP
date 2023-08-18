#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
void insertNode(struct Node **head, int data, int position) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
if (position == 1) {
newNode->next = *head;
*head = newNode;
return;
}
struct Node *temp = *head;
int i;
for (i = 1; i < position - 1 && temp != NULL; i++) {
temp = temp->next;
}
if (temp == NULL) {
printf("Invalid position.\n");
free(newNode);
return;
}
newNode->next = temp->next;
temp->next = newNode;
}
void deleteNode(struct Node **head, int position) {
if (*head == NULL) {
printf("Linked list is empty.\n");
return;
}
struct Node *temp = *head;
if (position == 1) {
*head = (*head)->next;
free(temp);
return;
}
int i;
for (i = 1; i < position - 1 && temp != NULL; i++) {
temp = temp->next;
}
if (temp == NULL || temp->next == NULL) {
printf("Invalid position.\n");
return;
}
struct Node *toBeDeleted = temp->next;
temp->next = toBeDeleted->next;
free(toBeDeleted);
}
int countNodes(struct Node *head) {
int count = 0;
while (head != NULL) {
count++;
head = head->next;
}
return count;
}
void reversePrint(struct Node *head) {
if (head == NULL) {
return;
}
reversePrint(head->next);
printf("%d ", head->data);
}
void reverseList(struct Node **head) {
struct Node *prev = NULL;
struct Node *current = *head;
struct Node *nextNode;
while (current != NULL) {
nextNode = current->next;
current->next = prev;
prev = current;
current = nextNode;
}
*head = prev;
}
int main() {
struct Node *head = NULL;
insertNode(&head, 10, 1);
insertNode(&head, 20, 2);
insertNode(&head, 30, 2);
insertNode(&head, 40, 1);
printf("Linked list: ");
struct Node *temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
printf("Count of nodes: %d\n", countNodes(head));
printf("Reversed Linked list: ");
reversePrint(head);
printf("\n");
reverseList(&head);
printf("Linked list after reversal: ");
temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
deleteNode(&head, 2);
printf("Linked list after deleting node at position 2: ");
temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
return 0;
}