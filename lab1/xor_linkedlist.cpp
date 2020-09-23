#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};
typedef struct node* NODE;

NODE XOR(NODE a, NODE b)
{
    return (NODE) ((uintptr_t) (a) ^ (uintptr_t) (b));

}
void insert_beg(NODE *head,int data)
{
	NODE newnode;
    	newnode=(NODE)malloc(sizeof(struct node));
    	newnode->data= data;
    	newnode->link= NULL;
    	if(*head==NULL)
    	{
		*head= newnode;
    	}
     	else
	{
		newnode->link=*head;
		(*head)->link=XOR((*head)->link,newnode);
		*head=newnode;
	}
}
void insert_end(NODE *head, int data)
{
	NODE newnode;
    	newnode=(NODE)malloc(sizeof(struct node));
    	newnode->data = data;
	newnode->link=NULL;
    	if(head==NULL)
        	{
            		*head = newnode;
        	}
    	else
    	{
        		NODE curr=*head;
        		NODE prev=NULL;
        		NODE x;
        		while(curr->link != prev)
        		{
            			x = curr;
            			curr = XOR(curr->link, prev);
			prev = x;
        		}
        		
        		curr->link = XOR(curr->link,newnode);
		newnode->link = curr;

    	}
}
void printNode(NODE *head)
{
    NODE curr;
    NODE prev=NULL;
    NODE next;
    curr = *head;
    while(curr!= NULL)
    {
        cout<< curr->data<<" ";
        next = XOR(prev,curr->link);
        prev = curr;
        curr = next;
    }
}
int main()
{
    NODE head = NULL;
    int x,y;
    cout<<"Enter no of elements to be inserted at the beginning"<<endl;
    int n;
    cin>>n;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert_beg(&head,x);
    }
    cout<<"Elements in the list are: "<<endl;
    printNode(&head);
    cout<<endl;
    cout<<"Enter no of elements to be inserted at the end"<<endl;
    int k;
    cin>>k;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<k;i++)
    {
        cin>>y;
        insert_end(&head,y);
    }
    cout<<"Elements in the list are: "<<endl;
    printNode(&head);
    return 0;

}


/*
Enter no of elements to be inserted at the beginning
2
Enter elements
4 5
Elements in the list are:
5 4
Enter no of elements to be inserted at the end
3
Enter elements
1 2 3
Elements in the list are:
5 4 1 2 3
*/