// Fixed: 1.) Seg fault from incorrect printing of the list
//        2.) Memory leak from not deleting the list

#include <iostream>
#include <string>
using namespace std;

//Classic Linked List

template<typename DataType>
struct Node {
    Node<DataType>* next;
    DataType data;
    
    Node<DataType>* insert(DataType newData){ //to add to the linked list we prepend a new node 
    //and we point it to the current node, returning the address of the new node
      Node<DataType>* newHead = new Node<DataType>(newData);
      newHead->next = this;
      return newHead; //update the pointer to this list to reflect the new node
    }
    Node(DataType inputData);
};

//Constructor takes an input
//Notice how odd it is to define a templated class function
template<typename DataType>
Node<DataType>::Node(DataType inputData){
    data = inputData;
    next = 0;
}

template<typename DataType>
void print_list(Node<DataType>* anode){
   Node<DataType>* temp = anode;
   while(temp != NULL){
      cout << temp->data << endl; 
      temp = temp->next;
   }
}


int main() {
   Node<int>* head = new Node<int>(100);
   for(int i = 90; i >= 0; i=i-10){
      head = head->insert(i);
   }
   
   print_list(head);

   // Clear memory
   Node<int>* temp = head;
   Node<int>* next = temp->next;
   while(temp != NULL){
       delete(temp);
       temp = next;
       if(temp != NULL)
          next = temp->next;
   }

   return 0;
} 