//Phonebook Application
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct phone{
    struct phone* prev;
    char name[50];
    char phonenum[20];
    struct phone* next;
};
struct phone* head=NULL;
struct phone* tail=NULL;
void start()
{
    struct phone *new;
    new = (struct phone*)malloc(sizeof(struct phone));
    char n[50],p[20];
    printf("Hello, You are now about to enter the first data into the phonebook!!!\n");
    printf("Enter name: \n");
    scanf("%s",n);
    strcpy(new->name,n);
    Inv1:
    printf("Enter phone number: \n");
    scanf("%s",p);
    if(strlen(p)!=10)
    {
        printf("Invalid phone number! Please enter a valid number!\n");
        goto Inv1;
    }
    strcpy(new->phonenum,p);
    new->prev=NULL;
    new->next=NULL;
    head = new;
    tail=new;
    printf("\nCool.You have successfully added the first entry into your phonebook.\n");
    printf("Try exploring more features!!\n\n");

}

void insert()
{
    struct phone* temp2= head;
    struct phone *new1;
    new1 = (struct phone*)malloc(sizeof(struct phone));
    char n[50],p[20];
    printf("\nYou are now about to INSERT an entry into the phonebook!!!\n");
    printf("Enter name: \n");
    scanf("%s",n);
    strcpy(new1->name,n);
    Inv:
    printf("Enter phone number: \n");
    scanf("%s",p);
    if(strlen(p)!=10)
    {
        printf("Invalid phone number! Please enter a valid number!\n");
        goto Inv;
    }
    strcpy(new1->phonenum,p);
    if(head==NULL)
    {
        head = new1;
        tail = new1;
    }
    else
    {
        while(temp2->next!=NULL)
        {
            temp2 = temp2->next;
        }
        new1->prev = temp2;
        temp2->next = new1;
        new1->next = NULL;
        tail = new1;
    }
    printf("\nEntry added successfully!\n");
}

void search()
{
    printf("Enter the name you want to search : ");
    char search_name[50];
    scanf("%s",search_name);
    struct phone* temp = head;
    while(temp!=NULL)
    {

        if(strcmp(temp->name,search_name)==0)
        {
            printf("Name - '%s' found in your phonebook!!\n",search_name);
            printf("DETAILS : \n");
            printf("\nName : %s\t Phone number : %s\n",search_name,temp->phonenum);
            return;

        }
        temp=temp->next;
    }
    printf("Name - '%s' not found in your phonebook.\n",search_name);
    srch:
    printf("Do you want to add the details?\t1.YES 2.NO\n");
    int search_var;
    scanf("%d",&search_var);
    if(search_var==1)
    {
        insert();
    }
    else if(search_var==2)
    {
        return;
    }
    else
    {
        printf("Invalid option!");
        goto srch;
    }
}

void search_by_char()
{
    char sname,buf,buf1;
    scanf("%c",&buf);
    printf("Enter the character with which you want to search names in your phonebook : ");
    scanf("%c%c",&sname,&buf1);
    struct phone* temp = head;
    printf("DETAILS : \n");
    int flag=0;
    while(temp!=NULL)
    {

        if(toupper(sname)==(temp->name)[0] || tolower(sname)==(temp->name)[0])
        {
            printf("\nName : %s\t Phone number : %s\n",temp->name,temp->phonenum);
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("\nNames beginning with '%c' not found in your phonebook!!\n",sname);
    }
}

void update()
{
    printf("Enter the name of the person whose details you wish to edit : ");
    char upd_name[50];
    scanf("%s",upd_name);
    struct phone* temp = head;
    while(temp!=NULL)
    {

        if(strcmp(temp->name,upd_name)==0)
        {
            printf("Name - '%s' found in your phonebook!!\n",upd_name);
            printf("Enter the details to update the existing record : \n");
            printf("Enter name : ");
            char upd[50],upd_pnum[20];
            scanf("%s",upd);
            strcpy(temp->name,upd);
            updpoint:
            printf("Enter phone number : ");
            scanf("%s",upd_pnum);
            if(strlen(upd_pnum)!=10)
            {
                goto updpoint;
            }
            strcpy(temp->phonenum,upd_pnum);
            printf("\n\nDETAILS UPDATED SUCCESSFULLY!!\n");
            printf("\nUPDATED DETAILS : \n");
            printf("\nName : %s\t Phone number : %s\n",temp->name,temp->phonenum);
            return;

        }
        temp=temp->next;
    }
    printf("Name - '%s' not found in your phonebook.\n",upd_name);
    updt:
    printf("Do you want to add the details?\t1.YES 2.NO\n");
    int update_var;
    scanf("%d",&update_var);
    if(update_var==1)
    {
        insert();
    }
    else if(update_var==2)
    {
        return;
    }
    else
    {
        printf("Invalid option!");
        goto updt;
    }

}

void display()
{
    struct phone* temp;
    temp = head;
    if(head == NULL)
    {
        printf("Your phonebook is empty at the moment. Start adding entries soon!!\n");
        return;
    }
    printf("\nThe contents of your directory are:\n");
    printf("Sno.\tName\tPhone number\n");
    int i=1;
    while(temp!=NULL)
    {
        printf("%d\t%s\t%s\n",i,temp->name,temp->phonenum);
        i++;
        temp = temp->next;
    }
}

struct phone* CopyList(struct phone* head)
{
    struct phone* current = head;
    struct phone* newList = NULL;
    struct phone* tail = NULL;

    while (current != NULL)
    {

        if (newList == NULL)
        {
            newList = (struct phone*)malloc(sizeof(struct phone));
            strcpy(newList->name,current->name);
            strcpy(newList->phonenum,current->phonenum);
            newList->next = NULL;
            newList->prev = NULL;
            tail = newList;
        }
        else
        {
            tail->next = (struct phone*)malloc(sizeof(struct phone));
            tail->next->prev = tail;
            tail = tail->next;
            strcpy(tail->name,current->name);
            strcpy(tail->phonenum,current->phonenum);
            tail->next = NULL;
        }
        current = current->next;
    }

    return newList;
}

void sortList() {
    char temp[50];
    char temp1[20];
    if(head==NULL)
    {
        printf("Your phonebook is empty at the moment. Start adding entries soon!!\n");
        return;
    }
    struct phone* present = CopyList(head);
    struct phone* present1 = present;
    struct phone* index = NULL;

    for(; present->next != NULL; present = present->next) {
            for(index = present->next; index != NULL; index = index->next) {

                if(strcmp(present->name,index->name)>0) {
                    strcpy(temp,present->name);
                    strcpy(present->name,index->name);
                    strcpy(index->name,temp);

                    strcpy(temp1,present->phonenum);
                    strcpy(present->phonenum,index->phonenum);
                    strcpy(index->phonenum,temp1);
                }
            }
        }
        printf("\nThe contents of your directory in alphabetical order are:\n");
        printf("Sno.\tName\tPhone number\n");
        int i=1;
      while(present1!=NULL)
      {
            printf("%d\t%s\t%s\n",i,present1->name,present1->phonenum);
            i++;
            present1 = present1->next;
      }

}


void delete_data(char name[]) {
   int pos = 0;
   struct phone *pre_node;

   if(head==NULL) {
      printf("Phonebook is empty now!!\n");
      return;
   }

   if(strcmp(head->name,name)==0)
   {
      if(head->next != NULL) {
         head->next->prev = NULL;
         head = head->next;
         return;
      } else {
         head = NULL;
         printf("\nRECORD DELETED SUCCESSFULLY!!\n");
         printf("\nPhonebook is empty now!!\n");
         return;
      }
   }
   else if(strcmp(head->name,name)!=0 && head->next == NULL) {
      printf("\nName - '%s' not found in the Phonebook!!\n",name);
      return;
   }

   struct phone* current = head;

   while(current->next != NULL && strcmp(current->name,name)!=0 ) {
      pre_node = current;
      current = current->next;
   }

   if(strcmp(current->name,name)==0)
   {
      pre_node->next = pre_node->next->next;

      if(pre_node->next != NULL)
      {
         pre_node->next->prev = pre_node;
      }
      else
         tail = pre_node;

      free(current);
      printf("\nRECORD DELETED SUCCESSFULLY!!\n");
   }
   else
      printf("Name - '%s' not found in your phonebook!!\n",name);

}

void display_rev()
{
    struct phone* temp;
    temp = tail;
    if(head == NULL)
    {
        printf("Your phonebook is empty at the moment. Start adding entries soon!!\n");
        return;
    }
    printf("\nThe contents of your directory are:\n");
    printf("Sno.\tName\tPhone number\n");
    int i=1;
    while(temp!=NULL)
    {
        printf("%d\t%s\t%s\n",i,temp->name,temp->phonenum);
        i++;
        temp = temp->prev;
    }
}
//Driver Code
int main()
{
    /*
    PHONEBOOK APPLICATION FEATURES
    1.start()
    2.insert()
    3.delete()
    4.search()
    5.search_by_char()
    6.update()
    7.sort()
    8.display()
    9.display_rev()
    10.EXIT
    */
    printf("********PHONEBOOK APPLICATION********\n\n");
    printf("Hello User! Please enter your name: ");
    char uname[50];
    gets(uname);
    for (int i = 0; uname[i]!='\0'; i++) {
      if(uname[i] >= 'a' && uname[i] <= 'z') {
         uname[i] = uname[i] -32;
      }
   }
    printf("\nWELCOME %s TO OUR ONLINE PHONEBOOK\t\t\n\n",uname);
    int var;
    start();
    do{
        printf("\nOUR PHONEBOOK FEATURES:\n");
        printf("1. Insert contact into your phonebook.\n");
        printf("2. Delete contact from your phonebook.\n");
        printf("3. Display all contacts from your phonebook.\n");
        printf("4. Display all contacts from your phonebook from last inserted record to the first inserted one.\n");
        printf("5. Update a record of your phonebook.\n");
        printf("6. Search a record from your phonebook.\n");
        printf("7. Search a record from your phonebook using Character Search.\n");
        printf("8. Display all contacts of your phonebook in alphabetical order.\n");
        printf("9. EXIT\n");
        printf("\nEnter the number for the corresponding operation : ");
        scanf("%d",&var);
        switch(var)
        {
            case 1:
                insert();
                break;
            case 2:
            {
                printf("\nEnter the name you want to delete from the phonebook : ");
                char del_name[50];
                scanf("%s",del_name);
                delete_data(del_name);
                break;
            }
            case 3:
                display();
                break;
            case 4:
                display_rev();
                break;
            case 5:
                update();
                break;
            case 6:
                search();
                break;
            case 7:
                search_by_char();
                break;
            case 8:
                sortList();
                break;
            case 9:
                printf("\nTHANK YOU!! LOOKING FORWARD TO HELP YOU!!\n");
                exit(0);
            default:
                printf("\nINVALID OPTION!! TRY AGAIN.\n\n");
                break;
        }
    }while(var!=9);

    return 0;
}
