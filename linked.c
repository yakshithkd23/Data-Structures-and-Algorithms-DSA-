#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *left,*right;

};

typedef struct node *NODEPTR;
NODEPTR list = NULL, list1 = NULL;

int listempty();
void insert(int x);
int delet();
void display();
NODEPTR getnode();
void searchlist();
void insertnewnode(int x, int y);
void delelementafternewnode(int x);
void insertend(int x);
void deletendnode();
void readlist1();
void display1();
void mergelist();
void insertdoubly(int x);
int deletdoubly();
void  displaydoubly();
void insertcircular(int x);
int  deletcircular();

int main() {
    int x, y, choice;

    do {
        printf("\nEnter the choice:\n");
        printf("1. Insert\n2. Delete\n3. Display list\n4. Search\n5. Add new node\n6. Delete new node\n7. Insert at end\n8. Delete from end\n");
        printf("9. Read elements into List 1\n10. Display List 1\n11. Merge List 1 into List\n12.insert doubly\n13. delet doubly\n14. display doubly\n15. insert circular\n16. delete circular\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert into the list: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                if (listempty()) {
                    printf("Underflow: List is empty\n");
                } else {
                    x = delet();
                    printf("Deleted element: %d\n", x);
                }
                break;
            case 3:
                if (listempty()) {
                    printf("Underflow: List is empty\n");
                } else {
                    display();
                }
                break;
            case 4:
                searchlist();
                break;
            case 5:
                printf("Enter the value of the existing node (x): ");
                scanf("%d", &x);
                printf("Enter the value of the new node (y): ");
                scanf("%d", &y);
                insertnewnode(x, y);
                break;
            case 6:
                printf("Enter the value of the node (x) after which the element should be deleted: ");
                scanf("%d", &x);
                delelementafternewnode(x);
                break;
            case 7:
                printf("Enter the element to add at the end: ");
                scanf("%d", &x);
                insertend(x);
                break;
            case 8:
                deletendnode();
                break;
            case 9:
                readlist1();
                break;
            case 10:
                display1();
                break;
            case 11:
                mergelist();
                break;
            case 12:
                printf("enter the value insert into the doubly\n:");
                scanf("%d",&x);
                insertdoubly(x);
                break;
            case 13:
                if(listempty())
                {
                    printf("underflow\n");
                }
                x=deletdoubly();
                break;
            case 14:
                displaydoubly();
                break;
            case 15:
             printf("enter element \n");
             scanf("%d",&x);
               insertcircular(x);
               break;
            case 16:
            if(listempty()){
                printf("underflow\n");
            }
               x=deletcircular();
               break;
            default:
                printf("Invalid choice. Exiting...\n");
                break;
        }
    } while (choice >= 1 && choice <= 16);

    return 0;
}

NODEPTR getnode() {
    NODEPTR p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}

void insert(int x) {
    NODEPTR p = getnode();
    if (p == NULL) {
        printf("Memory is not available\n");
        return;
    }
    p->info = x;
    p->next = list;
    list = p;
}

int listempty() {
    return list == NULL;
}

int delet() {
    int x;
    NODEPTR p = list;
    x = p->info;
    list = p->next;
    free(p);
    return x;
}

void display() {
    NODEPTR p;
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    for (p = list; p != NULL; p = p->next) {
        printf("-->%d ", p->info);
    }
    printf("\n");
}

void searchlist() {
    NODEPTR p;
    int s, i = 1;
    printf("Enter the searching element: ");
    scanf("%d", &s);
    for (p = list; p != NULL; p = p->next) {
        if (p->info == s) {
            printf("Element is present at location: %d\n", i);
            return;
        }
        i++;
    }
    printf("Element not found in the list\n");
}

void insertnewnode(int x, int y) {
    NODEPTR p = list, q;

    while (p != NULL) {
        if (p->info == x) {
            q = getnode();
            q->info = y;
            q->next = p->next;
            p->next = q;
            printf("Inserted %d after %d in the list\n", y, x);
            return;
        }
        p = p->next;
    }
    printf("Element %d is not present in the list\n", x);
}

void delelementafternewnode(int x) {
    NODEPTR p = list, q;

    while (p != NULL && p->info != x) {
        p = p->next;
    }

    if (p != NULL && p->next != NULL) {
        q = p->next;
        p->next = q->next;
        printf("Deleted node with value %d after %d\n", q->info, x);
        free(q);
    } else if (p == NULL) {
        printf("Element %d not found in the list\n", x);
    } else {
        printf("No node exists after %d to delete\n", x);
    }
}

void insertend(int x) {
    NODEPTR p = getnode(), q;
    p->info = x;
    p->next = NULL;
    if (list == NULL) {
        list = p;
        return;
    }
    for (q = list; q->next != NULL; q = q->next);
    q->next = p;
}

void deletendnode() {
    NODEPTR p = list, q = NULL;
    if (list == NULL) {
        printf("List is empty. Nothing to delete\n");
        return;
    }
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    if (q != NULL) {
        q->next = NULL;
    } else {
        list = NULL;
    }
    free(p);
}
void readlist1() {
    int n, value;
    NODEPTR r , last= NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { 
        scanf("%d", &value);

        r= getnode();
        if (r == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        r->info = value;
        r->next = NULL;

        if (list1 == NULL) {
            list1 = r;
        } else {
            last->next = r;
        }
        last = r;
    }
}
void display1() {
    NODEPTR p1;
    if (list1 == NULL) {
        printf("List1 is empty\n");
        return;
    }
    printf("List1 elements: ");
    for (p1 = list1; p1 != NULL; p1 = p1->next) {
        printf("-->%d ", p1->info);
    }
    printf("\n");
}

void mergelist() {
    NODEPTR p;

    if (list1 == NULL) {
        printf("List1 is empty. Nothing to merge.\n");
        return;
    }

    if (list == NULL) {
        list = list1;
    } else {
        for (p = list; p->next != NULL; p = p->next);
        p->next = list1;
    }

    printf("Merged list: ");
    for (p = list; p != NULL; p = p->next) {
        printf("-->%d ", p->info);
    }
    printf("\n");
}

void insertdoubly(int x){
    NODEPTR p=getnode();
    p->info=x;
    p->left=NULL;
    if(list==NULL){
        p->right =NULL;
        list=p;

    }
    else{
        p->right=list;
        list->left=p;
        list=p;
    }
}
int deletdoubly(){
    NODEPTR p;
    int x;
    p=list;
    x=p->info;
    list=p->right;
    if(list!=NULL)
{
    list->left=NULL;
}
free(p);
return x;
    
}
void displaydoubly() {
    NODEPTR p;
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List elements (left <-- info --> right):\n");
    for (p = list; p != NULL; p = p->right) {
        printf("(%d <-- %d --> %d) ", 
               (p->left != NULL) ? p->left->info : -1,  // Left info or -1 if NULL
               p->info,                                // Current node's info
               (p->right != NULL) ? p->right->info : -1); // Right info or -1 if NULL
    }
    printf("\n");
}

void insertcircular(int x){
NODEPTR p;
p=getnode();
p->info=x;
if(list==NULL){
    list=p;
}
else{
    p->next=list->next;
}
list->next=p;
}

int deletcircular() {
    int x;
    NODEPTR p;

    if (list == NULL) { 
        printf("List is empty. Nothing to delete.\n");
        return -1; 
    }

    p = list->next; 
    x = p->info;    

    if (p == list) { 
        list = NULL; 
    } else {
        list->next = p->next; 
    }

    free(p); 
    return x; 
