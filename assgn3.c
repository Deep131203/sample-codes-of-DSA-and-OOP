#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
struct Node *createNode(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
struct Node *createCircularLinkedList(int n) {
if (n <= 0) {
return NULL;
}
struct Node *head = createNode(1);
struct Node *prev = head;
int i;
for ( i = 2; i <= n; i++) {
struct Node *newNode = createNode(i);
prev->next = newNode;
prev = newNode;
}
prev->next = head;
return head;
}
int josephus(struct Node **head, int k) {
if (*head == NULL) {
return -1;
}
struct Node *current = *head;
struct Node *prev = NULL;
while (current->next != current) {
int i;
for (i = 1; i < k; i++) {
prev = current;
current = current->next;
}
prev->next = current->next;
printf("Eliminated: %d\n", current->data);
free(current);
current = prev->next;
}
int survivor = current->data;
free(current);
*head = NULL;
return survivor;
}
int main() {
int n, k;
printf("Enter the number of people and k value: ");
scanf("%d %d", &n, &k);
struct Node *head = createCircularLinkedList(n);
printf("Elimination order:\n");
int survivor = josephus(&head, k);
printf("Survivor: %d\n", survivor);
return 0;
}