#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct {
 struct Node *head;
} List;

void initList(List *list){
  list->head = NULL;
}

void print_list(List *list){
  if(list->head != NULL){
    struct Node *current = list->head;
    while(current != NULL){
      printf("%d ", current->data);
      current = current->next;
    }
  }
  printf("\n");
}

void insert_node(List *list, int data){
  if(list->head == NULL){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    list->head = newNode;
  } else {
    struct Node *current = list->head;
    while(current->next != NULL)
      current = current->next;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    current->next = newNode;
  }
}

void delete_node(List *list,int data){
  if(list->head != NULL){
    struct Node *current = list->head;
    if(current->data == data)
      current = NULL;
    else {
      while(current->next != NULL){
        if(current->next->data == data){
          current->next = current->next->next;
          break;
        }
        current = current->next;
      }
    }
  } 
}

int main(){
  List *lst = (List*)malloc(sizeof(List));
  initList(lst);
  insert_node(lst, 5);
  insert_node(lst, 6);
  insert_node(lst, 0);
  delete_node(lst, 6);
  print_list(lst);
    

  return 0;
}


