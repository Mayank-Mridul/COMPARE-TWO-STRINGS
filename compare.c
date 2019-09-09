#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char c;
    struct Node *next;
};
struct Node* newNode(char c)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->c = c;
    temp->next = NULL;
    return temp;
};
int compare(struct Node *list1, struct Node *list2);

int main()
{
    int t,n;
    
    scanf("%d",&t);
    
    char x;
    while(t--)
    {
        scanf("%d",&n);
        scanf("%c",&x);
        
        struct Node *list1 = newNode(x);
        struct Node *temp=list1;
        int i;
        for(i=0; i<n-1; i++)
        {
            scanf(" %c",&x);
            temp->next = newNode(x);
            temp=temp->next;
        }
        int m;
        scanf("%d",&m);
        scanf("%c",&x);
        struct Node *list2 = newNode(x);
        temp=list2;
        for(i=0; i<m-1; i++)
        {
            scanf(" %c",&x);
            temp->next = newNode(x);
            temp=temp->next;
        }
        printf("%d", compare(list1, list2));
    }
    return 0;
}


int compare(struct Node*list1,struct Node*list2)
{
    
    int c = 0;
    
    struct Node *temp1,*temp2;
    
    temp1 = list1;
    
    temp2 = list2;
    
    
    while(temp1!=NULL || temp2!=NULL){
        if(temp1->c != temp2->c){
            c=1;
        }
        
        if(c==1){
            if(temp1->c > temp2->c)
            return 1;
            
            if(temp1->c < temp2->c)
            return -1;
        }
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    if(temp1){
        return -1;
    }
    
    if(temp2){
        return 1;
    }
    
    if(c==0)
    return 0;
    
}