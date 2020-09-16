#include <bits/stdc++.h> 
using namespace std; 
  

struct Node { 
    int data; 
    struct Node* next; 
}; 
  
struct Node* Reverse(struct Node* head, int k) 
{ 
    
    stack<Node*> mystack; 
    struct Node* current = head; 
    struct Node* prev = NULL; 
  
    while (current != NULL) { 
  
        
        int count = 0; 
        while (current != NULL && count < k) { 
            mystack.push(current); 
            current = current->next; 
            count++; 
        } 
  
        
        while (mystack.size() > 0) { 
  
             
            if (prev == NULL) { 
                prev = mystack.top(); 
                head = prev; 
                mystack.pop(); 
            } else { 
                prev->next = mystack.top(); 
                prev = prev->next; 
                mystack.pop(); 
            } 
        } 
    } 
  
    prev->next = NULL; 
  
    return head; 
} 
  

void push(struct Node** head_ref, int new_data) 
{ 
    
    struct Node* new_node =  
          (struct Node*)malloc(sizeof(struct Node)); 
  
    
    new_node->data = new_data; 
  
    
    new_node->next = (*head_ref); 
  
    
    (*head_ref) = new_node; 
} 
  
void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
} 
    
  
int main(void) 
{ 
    int k, flag=0;
    struct Node* head = NULL; 
  
    do
    {
        int choice, val;
		printf("1 to insert\n 2 to stop\n");
	    scanf("%d", &choice);
		switch (choice) {
			case 1: printf("Enter the value: ");
				scanf("%d", &val);
				push(&head, val);
				break;
            case 2:flag=1; 
                break;
        }
    }while(flag!=1);

    printf("\nGiven linked list \n"); 
    printList(head); 

    printf("\nEnter k value\n");
    scanf("%d", &k);
    head = Reverse(head, k); 
  
    printf("\nReversed Linked list \n"); 
    printList(head); 
  
    return 0; 
} 