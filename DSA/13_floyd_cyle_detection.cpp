#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
node* floyddetectionloop(node* head){
    if(head==NULL)return NULL;
    // cout<<head->next->next->data<<endl;
    node* slow=head;
    node* fast=head;
    while(slow!=NULL&&fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            cout<<"1st meet at "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* getStartingNodeOfCycle(node* head){
    if(head==NULL)return NULL;
    node* intersection=floyddetectionloop(head);
    if(intersection==NULL)return NULL;
    //as slow is head and fast is head->next that means that intersection pointer here shoul be 1 ahead of the point
    //make slow=head and fast=head to get slow=head and intersection=1stmeet node only
    node* slow=head;
        // cout<<"slow "<<slow->data<<endl;
        // cout<<"intersection "<<intersection->data<<endl;
        // cout<<"slow "<<slow->next->data<<endl;
        // cout<<"intersection "<<intersection->next->data<<endl;
        // cout<<"slow "<<slow->next->next->data<<endl;
        // cout<<"intersection "<<intersection->next->next->data<<endl;
        // cout<<"slow "<<slow->next->next->next->data<<endl;
        // cout<<"intersection "<<intersection->next->next->next->data<<endl;
        // cout<<"slow "<<slow->next->next->next->next->data<<endl;
        // cout<<"intersection "<<intersection->next->next->next->next->data<<endl;
        // cout<<"slow "<<slow->next->next->next->next->next->data<<endl;
        // cout<<"intersection "<<intersection->next->next->next->next->next->data<<endl;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeLoop(node* head){
    if(head==NULL)return;
    node* cycleStart=getStartingNodeOfCycle(head);
    if(cycleStart==NULL)return ;//head
    node* temp=cycleStart;
    while(temp->next!=cycleStart){
        temp=temp->next;
    }
    temp->next=NULL;
}
int main()
{
    node* node1=new node(6);
    node* head=node1;
    node* tail=node1;//if tail is initialized at null then it need to be handled to point correct last node
    // print(head);

    insertathead(head,5);insertathead(head,4);insertathead(head,3);insertathead(head,2);insertathead(head,1);insertathead(head,0);
    insertathead(head,-1);
    insertathead(head,-2);
    insertathead(head,-3);
    insertathead(head,-4);
    print(head);
    tail->next=head->next->next->next->next;
    cout<<head->next->next->next->next->data<<endl;
    auto start1 = high_resolution_clock::now();
    if(floyddetectionloop(head)==NULL){
        cout<<"loop is not present "<<endl;
    }
    else{cout<<"loop is present"<<endl;}
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "time for floyd = "<<duration1.count() << endl;
    //tc-O(n) 
    //sc-O(1) only variable there
    auto start = high_resolution_clock::now();
    node* temp=getStartingNodeOfCycle(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "time for start node detection = "<<duration.count() << endl;
    cout<<"staring node of cyle is " <<temp->data<<endl;
    removeLoop(head);
    if(floyddetectionloop(head)==NULL){
        cout<<"loop is not present "<<endl;
    }
    else{cout<<"loop is present"<<endl;}
    cout<<head->data<<" "<<tail->data<<endl;
return 0;
}