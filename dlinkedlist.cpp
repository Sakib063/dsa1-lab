#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct double_linked_list
{
    node *head;
    node *tail;

    double_linked_list()
    {
        head=NULL;
        tail=NULL;
    }

    void insert_first(int val)
    {
        node *temp=new node;
        temp->data=val;
        if(head==NULL){
            temp->next=nullptr;
            temp->prev=nullptr;
            head=temp;
            tail=temp;
        }
        else{
            temp->next=head;
            temp->prev=nullptr;
            temp=head;
        }
    }

    void insert_last(int val)
    {
        if(tail==NULL){
           insert_first(val);
        }
        else{
            node *temp=new node;
            temp->data=val;
            tail->next=temp;
            temp->prev=tail;
            temp->next=nullptr;
            tail=temp;
        }
    }

    node* search_in_list(int val)
    {
        node *temp=head;
        while(temp!=NULL){
            if(temp->data==val)return temp;
            else{
                temp=temp->next;
            }
        }
        return NULL;
    }

    node* search_in_list_reverse(int val)
    {
        node *temp=tail;



        while(temp!=NULL){
            if(temp->data==val)return temp;
            else{
                temp=temp->prev;
            }
        }
        return NULL;
    }

    void insert_middle(int val,int pre)
    {
        if(head==NULL){
            insert_first(val);
        }
        else{
            node *crt=new node;
            crt->data=val;

            node *temp=search_in_list(pre);
            node *temp1=temp->next;
            crt->next=temp1;
            crt->prev=temp;
            temp->next=crt;
            temp1->prev=crt;
        }
    }

    void delete_first()
    {
        if(head==NULL)return;
        else if(head->next==NULL){
            node *temp=head;
            head=NULL;
            tail=NULL;

            delete(temp);
        }
        else{
            node *temp=head;
            head=head->next;
            temp->prev=nullptr;

            delete(temp);
        }
    }

    void delete_last()
    {
        if(tail==NULL)return;
        else if(tail->prev=NULL){
            delete_first();
        }
        else{
            node *temp=tail;
            tail=tail->prev;
            temp->prev=nullptr;
            tail->next=nullptr;

            delete(temp);
        }
    }

    void delete_middle(int val)
    {
        node *dlt=search_in_list(val);
        node *dlt_nxt=dlt->next;
        node *dlt_pre=dlt->prev;

        dlt_pre->next=dlt_nxt;
        dlt_nxt->prev=dlt_pre;

        dlt->next=nullptr;
        dlt->prev=nullptr;

        delete(dlt);
    }

    void show_list()
    {
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<", ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void show_list_reverse()
    {
        node *temp=tail;
        while(temp!=NULL){
            cout<<temp->data<<", ";
            temp=temp->prev;
        }
        cout<<endl;
    }

    void convert_circular_list()
    {
        tail->next=head;
        head->prev=tail;
    }

    void show_list_circular()
    {
        node *temp=head;
        while(temp!=tail->next){
            cout<<temp->data<<", ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void insert_in_order(int val)
    {
        node *temp=head;
        while(temp->data>val){
            temp=temp->next;
        }
        insert_middle(val,temp->data);
    }
};


int main()
{
    double_linked_list linked_list;
    int user;
    int val,pre;
    node *y=new node;

    while(1){
        cout << "---MENU---" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Show All " << endl;
        cout << "3. Search " << endl;
        cout << "4. Insert Last " << endl;
        cout << "5. Insert Middle " << endl;
        cout << "6. Insert In Order " << endl;
        cout << "7. delete first " << endl;
        cout << "8. delete last " << endl;
        cout << "9. delete middle " << endl;
        cout << "10. search reverse " << endl;
        cout << "11. show list reverse " << endl;
        cout << "12. circular list " << endl;
        cout << "13. show circular list " << endl;
        cout << "14. Exit" <<endl;

        cin>>user;

        switch(user)
        {
        case 1:
            cin>>val;
            linked_list.insert_first(val);
            break;
        case 2:
            linked_list.show_list();
            break;
        case 3:
            cin>>val;
            linked_list.search_in_list(val);
            break;
        case 4:
            cin>>val;
            linked_list.insert_last(val);
            break;
        case 5:
            cin>>val;
            cin>>pre;
            linked_list.insert_middle(val,pre);
            break;
        case 6:
            cin>>val;
            linked_list.insert_in_order(val);
            break;
        case 7:
            linked_list.delete_first();
            break;
        case 8:
            linked_list.delete_last();
            break;
        case 9:
            cin>>val;
            linked_list.delete_middle(val);
            break;
        case 10:
            cin>>val;
            linked_list.search_in_list_reverse(val);
            break;
        case 11:
            linked_list.show_list_reverse();
            break;
        case 12:
            linked_list.convert_circular_list();
            break;
        case 13:
            linked_list.show_list_circular();
            break;
        case 14:
            return 0;
            break;
        default:
            cout<<"Invalid input"<<endl;
        }
    }
    return 0;
}
