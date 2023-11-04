#include<iostream>

using namespace std;



struct node
{
	int data;
	node *parent;
	node *left;
	node *right;

	node(int val)
	{
		data = val;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

};


struct binary_tree
{
	node *root;

	binary_tree()
	{
		root = NULL;
	}

	void insert(node *z)
	{
		node *y = NULL;
		node *x = root;

		while(x!=NULL)
		{
			y = x;
			if(z->data < x->data) x = x->left;
			else x = x->right;
		}

		z->parent=y;

		if(y==NULL) root=z;
		else
		{
			if(z->data < y->data) y->left = z;
			else y->right = z;
		}
	}

	node* search(int data)
	{
		node *temp = root;
		while(temp!=NULL && temp->data!=data)
		{
			if(data < temp->data) temp = temp->left;
			else temp = temp->right;
		}

		return temp;
	}

	node* tree_min(node *x)
	{
		if(x!=NULL)
		{
			while(x->left!=NULL)
			{
				x = x->left;
			}
			return x;
		}
		else return NULL;
	}

	void inorder_tree_walk(node *x)
	{
		if(x!=NULL)
		{
			inorder_tree_walk(x->left);
			cout << x->data << "	";
			inorder_tree_walk(x->right);
		}
	}

	node* get_root()
	{
		return root;
	}

	node* tree_successor(node *x)
	{
		node *scc;
		if(x->right!=NULL){
            x=x->right;
            scc=tree_min(x);
		}
		else{
            x=x->parent;
            if(x->left==NULL){
                x=x->parent;
            }
            return x->parent;
		}
	}

	node* tree_delete(node *x)
	{
        node *del;
        node *temp;
        if(x->right==NULL&&x->left==NULL){
            del=x;
            delete(x);
            return del;
        }
        else if(x->right!=NULL&&x->left==NULL){
            del=x;
            x->parent=temp;
            temp->right=x->right;
            delete(x);
            return del;
        }
        else if(x->right==NULL&&x->left!=NULL){
            del=x;
            x->parent=temp;
            temp->left=x->left;
            delete(x);
            return del;
        }
        else{
            del=x;
            temp=tree_successor(x);
            x=temp;
            return del;
            delete(del);
        }
	}

};

int main()
{
	binary_tree bt;
	node *x, *ret;
	int data, ch, key;

	while(1)
	{
		printf("\n----------MENU----------\n");
		printf("\n(1)INSERT");
		printf("\n(2)TREE_MIN");
		printf("\n(3)SEARCH");
		printf("\n(4)INORDER-VIEW");
		printf("\n(5)SUCCESSOR");
		printf("\n(6)DELETE");
		printf("\n(7)EXIT");
		printf("\n------------------------\n");

		scanf("%d",&ch);

		switch(ch)
		{
			case 1: // insert
					printf("\n------------------------------");
					printf("\nEnter Integer Data : ");
					scanf("%d",&data);
					printf("\n------------------------------");

					x = new node(data);

					bt.insert(x);
					printf("\n...........Inserted...........\n");
					break;

			case 2: // Tree min
					ret = bt.tree_min(bt.get_root());

					if(ret == NULL) printf("\n......Tree is empty......\n");
					else
					{
						printf("\n------------------------------");
						printf("\nMinimum Data : ");
						printf("%d",ret->data);
						printf("\n------------------------------");
					}
					break;

			case 3: // Search
					printf("\nEnter Data : ");
					scanf("%d",&key);
					ret = bt.search(key);
					if(ret == NULL)printf("\nNOT FOUND\n");
					else
					{
						printf("\n------------------------------");
						printf("\nData : ");
						printf("%d",ret->data);
						printf("\n------------------------------");
					}
					break;

			case 4: // Inorder traversal
					bt.inorder_tree_walk(bt.get_root());
					break;

			case 5:
					printf("\nEnter Data : ");
					scanf("%d",&key);
					ret = bt.search(key);
					if(ret == NULL)printf("Not found");
					else
					{
						ret = bt.tree_successor(ret);
						if(ret == NULL)printf("No successor available\n");
						else
						{
							printf("\n------------------------------");
					        printf("\nSuccessor Data : ");
							printf("%d",ret->data);
					        printf("\n------------------------------");
						}
					}
					break;

			case 6: // delete
	            	printf("\nEnter Data : ");
					scanf("%d",&key);
					ret = bt.search(key);
				    if(ret == NULL)printf("Not found");
					else
					{
						ret = bt.tree_delete(ret);
				        printf("\n------------------------------");
			     		printf("\nDeleted Data : ");
				        printf("%d",ret->data);
				 		printf("\n------------------------------");
				       	delete ret;
					}
					break;
			case 7: // Exit
					exit(0);
					break;

			default:
					printf("\nWRONG CHOICE\n");
					break;
		}
	}
	return 0;

}
