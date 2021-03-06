#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    //structer constructer
    Node(){
        data=0;
        next=NULL;
    }
    //parameter constructor
    Node(int v){
        data=v;
        next=NULL;
    }
};
class LinkedList{
public :
    struct Node *head;
    struct Node *tail;
    int size;
    //constructor 
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }
    //paramaterized constructor
    LinkedList(struct Node*head,struct Node *tail,int size){
     this->head=head;
     this->tail=tail;
     this->size=size;
    }
   //size of linkedlist
   int Size(){
       return this->size;
   }
   //linked list is empty or not
   bool isEmpty(){
       return this->size==0;
   }
   // add element in front of linked list
   void addFirst(int data){
       struct Node *node=new Node(data);
       node->next=head;
       this->head=node;
       //if linked list is empty it means tail and head both are same
       if(this->tail==NULL) this->tail=node;
      this->size++;
   }
   // add element at last position 
   void addLast(int data){
       struct Node *node=new Node(data);
       if(this->head==NULL){
           this->addFirst(data);
       }else{
            this->tail->next=node;
            this->tail=node;
       }
     this->size++;
   }
   //get Node at ith position
   struct Node* getNodeAt(int index){
       if(index > this->size&&index<=0) {
           throw "invalid index!";
       }else{
         struct Node *temp=head;
         while(temp->next!=NULL&&index-2>=0){
             index--;
             temp=temp->next;
         }
         return temp;
       }
   }
    //Add data at given index
 void addAt(int index,int data){
     if(index<1||index>size) throw "Invalid index!";
     else if(index==1) this->addFirst(data);
     else if(index==this->size) this->addLast(data);
     else{
         struct Node *temp=this->getNodeAt(index-1);
         struct Node *newNode=new Node(data);
         newNode->next=temp->next;
         temp->next=newNode;
         this->size++;
     } 
 }
// remove first element from the linkedlist
 struct Node* removeFirst(){
     if(this->size==0){
         throw "List is empty";
     }
     struct Node *temp=this->head;
     if(this->size==1){
         this->head=NULL;
         this->tail=NULL;
     }else {
        this->head=this->head->next;
      return temp;
     }
       this->size--;
 }
 //remove last element from the linkedlist
 struct Node* removeLast(){
     if(this->isEmpty()){
         throw"List is empty";
     }
     else if(this->size==1){
         this->removeFirst();
     }
     else{
         struct Node* temp=this->getNodeAt(size-1);
        struct Node* temp1=temp->next;
         temp->next=NULL;
         this->tail=temp;
         return temp1;
     }
     this->size--;
 }

 //remove At given postiton
 struct Node* removeAt(int index){
       if(index<1||index>size) throw "Invalid index!";
      else if(index==1) return this->removeFirst();
      else if(index==this->size) return this->removeLast();
      else {
         struct Node *temp=getNodeAt(index-1);
         struct Node *temp1=temp->next;
         temp->next=temp->next->next;
          this->size--;
         return temp1;
     }
 }
 //display linkedlist
 void display(){
     if(this->head==NULL){
         throw "List is empty";
     }
     struct Node* temp=this->head;
     while(temp!=NULL){
         cout<<temp->data<<" -> ";
         temp=temp->next;
     }
     cout<<"end"<<endl;
 }
 //iterative data reverese
 void ReverseDI(){
     int si=1;
     int ei=this->size;
     while(si<=ei){
         struct Node* siNode=getNodeAt(si);
         struct Node* eiNode=getNodeAt(ei);
         int temp;
           temp=siNode->data;
           siNode->data=eiNode->data;
           eiNode->data=temp;
           si++;
           ei--;
     }
 }
//reverse an linked list using pointer
void reversePI(){
  struct Node*curr=this->head;
  struct Node*currNext=this->head->next;
  while(currNext!=NULL){
      struct Node*tc=curr;
      struct Node*tcr=currNext;
      curr=currNext;
      currNext=currNext->next;
      tcr->next=tc;
  }
  struct Node *temp=this->head;
  this->head=this->tail;
  this->tail=temp;
  this->tail->next=NULL;
}
 //recursive pointer
 void reverseRP(){
   reverseRP(this->head);
   struct Node*temp=this->head;
   this->head=this->tail;
   this->tail=temp;
   this->tail->next=NULL;
 }
 void reverseRP(struct Node* node){
     if(node==this->tail){
         return;
     }
     reverseRP(node->next);
     node->next->next=node;
 }
 //recursively data  reverse
 //In every recursive call the new pointer point previous pointer after second call
 // new node pointer not point to head instead point at left which is pointer to head 
 //so change appear in pointer data where pointer not point to head data
 struct heapmover{
  struct Node *node;
  heapmover(struct Node *x){
      node=x;
  };
 };
 void reverseRD(){
     struct heapmover*h=new heapmover(this->head);
  reverseRD(h,this->head,1);
 }
 void reverseRD( struct heapmover*left,struct Node*right,int index){
  if(right==NULL){
      return;
  }
  reverseRD(left,right->next,index+1);
  if(index>this->size/2){
    int temp=left->node->data;
    left->node->data=right->data;
    right->data=temp;
    left->node=left->node->next;
  }
 }
 //get mid node of linkedlist
 struct Node* getMidNode(){
     struct Node*slow=this->head;
     struct Node*fast=this->head;
     while(fast->next!=NULL&&fast->next->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;
     }
     return slow;
 }
 //Kth node from the end of linkedlist
 int kthNodeEnd(int index){
     struct Node*fast=this->head;
     struct Node*slow=this->head;
     for(int i=1;i<=index;i++){
         fast=fast->next;
     }
     while(fast!=NULL){
         fast=fast->next;
         slow=slow->next;
     }
     return slow->data;
 }
 //merge two linked list
 LinkedList merge(LinkedList other){
      struct Node* thishead=this->head;
      struct Node* otherhead=other.head;
      LinkedList sorted;
      while(thishead!=NULL&&otherhead!=NULL){
          if(thishead->data<otherhead->data){
           sorted.addLast(thishead->data);
          thishead=thishead->next;
          }else{
              sorted.addLast(otherhead->data);
              otherhead=otherhead->next;
          }
      }
      while(thishead!=NULL){
           sorted.addLast(thishead->data);
          thishead=thishead->next;
      }
      while(otherhead!=NULL){
           sorted.addLast(otherhead->data);
          otherhead=otherhead->next;
      }
      return sorted;
 }
 //Mergesort
void Mergesort(){
    LinkedList sorted=MergeSortHelper(this->head,this->tail,this->size);
    this->head=sorted.head;
    this->tail=sorted.tail;
    this->size=sorted.size;
}
LinkedList MergeSortHelper(struct Node*head,struct Node *tail,int size){
    struct Node*midnode=this->getMidNode();
    struct Node* midnext=midnode->next;
    midnext->next=NULL;
    LinkedList list1(this->head,midnode,(this->size+1)/2);
    LinkedList list2(this->head,midnext,this->size);
    list1.Mergesort();
    list2.Mergesort();
   LinkedList sorted =list1.merge(list2);
    return sorted;
}
};

int main(){
    LinkedList list;
    for(int i=1;i<=5;i++){
        cout<<"Enter the "<<i<<" ith element in the linked list"<<endl;
        cout<<i*10<<endl;
        list.addFirst(i*10);
    }
    cout<<"Display function"<<endl;
    list.display();
    cout<<"Add element at "<<4<<"rd index"<<endl;
    list.addAt(4,60);
    list.display();
    cout<<"Remove node at 3rd index -> "<<list.removeAt(3)->data<<endl;
    list.display();
    list.reverseRD();
    cout<<"the reverse linked list-> ";
    list.display();
    cout<<"the mid node -> "<<list.getMidNode()->data<<endl;
    cout<<"the kth node from end -> "<<list.kthNodeEnd(2)<<endl;
    LinkedList other;
    for(int i=7;i<12;i++){
        other.addFirst(i*10);
    }
   LinkedList merged= list.merge(other);
   list.display();
   other.display();
     cout<<"Two linked list merge ::";
   merged.display();
   cout<<"Before sorting::";
   other.display();
   cout<<"After sorting::";
   other.Mergesort();
   other.display();
     
}
