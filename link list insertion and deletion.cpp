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


void delete_front(Node** head){


     if(*head==NULL){
        cout<<"List is empty"<<endl;
        return;
     }

     Node *temp = *head;
     *head = temp->next;
     free(temp);
}

void delete_end(Node** head){

  if(*head==NULL){
        cout<<"List is empty"<<endl;
        return;

  }

  Node* last = *head;

  if(last->next==nullptr)
  {*head = nullptr;
    return;
  }



  Node* previous = NULL;

  while(last->next!=nullptr){
    previous = last;
    last = last->next;

  }

  previous->next=NULL;
  free(last);

}

void delete_after(Node** previous){

if(*previous== NULL){
        cout<<"List is empty"<<endl;
        return;

}

Node* temp = *previous;

if(temp->next==NULL)
{
    cout<<"we are at last node"<<endl;
        return;

}

temp = temp->next;

(*previous)->next = temp->next;
free(temp);



}


void delete_by_key(Node** head, int key){

        if(*head== NULL){
        cout<<"List is empty"<<endl;
        return;

}

Node *temp = *head;

  if(temp->data == key){
    if(temp->next==NULL)
    {*head=NULL;
      free(temp);
      return;
    }
    else{
        *head= temp->next;
        free(temp);
        return;
    }

  }

  Node* previous= NULL;
  while(temp!=NULL){

      // cout<<"inside loop";
       if(temp->data == key){
            if(temp->next!=nullptr){
                previous->next = temp->next;
                free(temp);
                return;
            }else{
                   cout<<"it is last node"<<endl;
                         return;

            }
       }
       previous = temp;
       temp= temp->next;
  }

  cout<<"Node not found with this key"<<endl;
                         return;

}

void delete_by_position(Node** head, int pos){

     if(*head==NULL)
        return;
     int i=0;

     Node* temp = *head;
     while(i<=pos && temp!= NULL){

        if(i==pos){
            if(i==0)
                delete_front(head);
            else if(temp->next==NULL)
                delete_end(head);
            else
                delete_by_key(head,temp->data);
        }
        i++;
        temp=temp->next;
     }

     if(i!=pos+1)
        cout<<"pos not found"<<endl;

}


void delete_recurse(Node** node){


  if(*node==NULL){

    return;
   }

   //*node = (*node)->next;

   delete_recurse(&((*node)->next));


   cout<<"element deleted  "<<(*node)->data<<endl;//<<(*node)->data;
   (*node) = NULL;
   free(*node);


}

void delete_list(Node** head){

   if(*head==NULL){

    cout<<"List is empty"<<endl;

    return;
   }

   delete_recurse(head);
   cout<<"list is deleted"<<endl;
}


void nth_recurse(Node** node,int& pos){
  if(*node==NULL)
    return ;


  nth_recurse(&((*node)->next),pos);

  pos--;
  if(pos==0){
        cout<<"nth element  "<<(*node)->data<<endl;
    return;
  }

}
void nth_from_end(Node** head,int pos){

   if(*head==NULL){
    return;
   }

   Node* node= *head;
   nth_recurse(&node,pos);




}


void count_key(Node* head,int key){

int c=0;
while(head!=NULL){

    if(head->data==key)
        c++;
    head=head->next;
}

cout<<"Number "<<key<<" occures "<<c<<" times"<<endl;
}

bool check_loop(Node* head){

   unordered_set<Node*> h;

   while(head!=NULL){

       if(h.find(head)!=h.end()){
        return true;
       }
       h.insert(head);
       head=head->next;
   }

   return false;
}



int main(){

Node* head;
head=NULL;

insert_node(&head,1);
insert_node(&head,2);
insert_node(&head,4);
insert_node(&head,5);
insert_node(&head,7);

//insert_node1(head,2);
//insert_node1(head,4);
//insert_node1(head,6);

print_list(head);

insert_mid(head->next,3);

insert_front(&head,0);

print_list(head);

delete_front(&head);

print_list(head);

delete_end(&head);

print_list(head);


delete_after(&head->next);

print_list(head);

delete_by_key(&head,4);

print_list(head);

delete_by_position(&head,2);

print_list(head);

insert_node(&head,8);
insert_node(&head,2);
insert_node(&head,9);

print_list(head);

nth_from_end(&head,2);
print_list(head);

count_key(head,2);

//head->next->next->next = head;

bool check= check_loop(head);

if(check)
    cout<<"loop"<<endl;
else
    cout<<"not loop"<<endl;

delete_list(&head);
print_list(head);




return 0;
}
