#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

typedef struct Node{

    int data;
    Node* next;

    Node(){
       next = NULL;
    }
};


void print_list(Node* node){

while(node!=NULL){
    cout<<node->data<<"  ";
    node=node->next;
}
cout<<endl;

}
void insert_node(Node** head,int data){

  Node* newnode = new Node();

  newnode->data = data;

  Node* last ;
  last = *head;


  if(*head==NULL){

    *head=newnode;


  }else{

    while(last->next != NULL)
        last=last->next;
    last->next=newnode;

  }

//  print_list(*head);

}

void insert_node1(Node* head,int data){

  Node* newnode = new Node();

  newnode->data = data;

  Node* last ;
  last = head;


  if(head==NULL){

    head=newnode;


  }else{

    while(last->next != NULL)
        last=last->next;
    last->next=newnode;

  }

  print_list(head);

}

void insert_front(Node** head,int data){

      Node* newnode = new Node();

      newnode->data = data;

      if(*head == NULL){

        *head=newnode;
      }else{

         newnode->next=*head;
         *head=newnode;

      }

}


void insert_mid(Node* previous,int data){

   Node* newnode = new Node();
   newnode->data = data;

   newnode->next = previous->next;

   previous->next=newnode;
}



int main(){

Node* head;
head=NULL;

insert_node(&head,1);
//insert_node(&head,2);
//insert_node(&head,4);
//insert_node(&head,5);
//insert_node(&head,7);

//insert_node1(head,2);
insert_node1(head,4);
insert_node1(head,6);

print_list(head);

insert_mid(head->next,3);

insert_front(&head,0);

print_list(head);

return 0;
}
