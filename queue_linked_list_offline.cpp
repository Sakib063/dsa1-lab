#include<iostream>

using namespace std;

struct node
{
	int val;
	node *next;

	node(int val)
	{
		this->val = val;
		this->next = NULL;
	}

};

struct queue
{
	node *head;

	queue()
	{
		head = NULL;
	}

	void enQueue(int val)
	{
		if(isFull()){
            cout<<"Queue overflow"<<endl;
		}
		else{
            node *temp=new node(val);
            temp->next=head;
            head=temp;
		}
	}

	int deQueue()
	{
        int n;
		if(isEmpty()){
            cout<<"Queue underflow"<<endl;
            return NULL;
		}
		else if(head->next==nullptr){
            node *temp=head;
            n=temp->val;
            head=NULL;
            delete(temp);
		}
		else{
            node *tail=head;
            node *temp;
            while(tail->next!=nullptr){
                temp=tail;
                tail=tail->next;
            }
            n=tail->val;
            temp->next=nullptr;
            delete(tail);
		}
		return n;
	}

	bool isEmpty()
	{
		if(head==NULL)return true;
		else return false;
	}

	bool isFull()
	{
        return false;
	}

	void print()
	{
		node *cur = this->head;
		while(cur!=NULL)
		{
			cout << cur->val << "	  ->	";
			cur = cur->next;
		}
		cout << "Null" ;
		cout << endl;
	}

};


int main()
{

	queue q;

	q.enQueue(10);
	q.enQueue(20);
	q.print();

	int a = q.deQueue();
	cout << a << endl;
	q.print();

	int b = q.deQueue();
	cout << b << endl;
	q.print();

	return 0;
}
