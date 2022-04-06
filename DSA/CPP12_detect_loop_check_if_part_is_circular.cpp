#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory freed for node with value "<<value<<endl;
    }
};
void insertathead(node* &head,int d){
    //new node creation at front
    node* temp=new node(d);
    temp->next=head;
    head=temp;

}
bool detectLoop(node* head){
    if(head==NULL)return false;
    map<node*,bool> visited;
    node* temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"present at "<<temp->data<<endl;
            return true;

        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* node1=new node(5);
    node* head=node1;
    node* tail=node1;
    // print(head);

    insertathead(head,4);    
    insertathead(head,3);    insertathead(head,2);    
    insertathead(head,1);    insertathead(head,0);
    tail->next=head->next->next->next;//to create loop
    // print(head);
    if(detectLoop(head)){
        cout<<"loop present"<<endl;
    }
    else{cout<<"loop not present";}


return 0;
}