#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class node{
    public:
        int info;
        node *next;
        node(int item)
        {
            info=item;
            next=nullptr;
        }
};
class linked_list{
    node *start,*end;
    public:
        linked_list()
        {
            start=end=nullptr;
        }
        void add_first(int item)
        {
            node *newptr=new node(item);
            if(start==nullptr)
            {
                start=end=newptr;
            }
            else
            {
                newptr->next=start;
                start=newptr;
            }
        }
        void add_last(int item)
        {
            node *newptr=new node(item);
            if(start==nullptr)
            {
                start=end=newptr;
            }
            else
            {
                end->next=newptr;
                end=newptr;
            }
        }
        void add_before(int item, int loc)
        {
            if(start==nullptr)
            {
                cout<<"List is empty\n";
                return;
            }
            if(start->info==loc)
            {
                add_first(item);
                return;
            }
            node *ptr=start;
            while(ptr != end and ptr->next->info != loc)
            {
                ptr=ptr->next;
            }
            if(ptr == end)
            {
                cout<<"Location not found\n";
                return;
            }
            node *newptr=new node(item);
            newptr->next=ptr->next;
            ptr->next=newptr;
        }
        void add_after(int item, int loc)
        {
            if(start==nullptr)
            {
                cout<<"List is empty\n";
                return;
            }
            if(end->info==loc)
            {
                add_last(item);
                return;
            }
            node *ptr=start;
            while(ptr != end and ptr->info != loc)
            {
                ptr=ptr->next;
            }
            if(ptr == end)
            {
                cout<<"Location not found\n";
                return;
            }
            node *newptr=new node(item);
            newptr->next=ptr->next;
            ptr->next=newptr;
        }
        void del_first()
        {
            if(start==nullptr)
            {
                cout<<"Underflow\n";
                return;
            }
            node *ptr=start;
            if(start==end)
            {
                start=end=nullptr;
            }
            else
            {
                start=start->next;
            }
            cout<<ptr->info<<" deleted\n";
            delete ptr;
        }
        void del_last()
        {
            if(start==nullptr)
            {
                cout<<"Underflow\n";
                return;
            }
            node *ptr=start;
            if(start==end)
            {
                start=end=nullptr;
            }
            else
            {
                while(ptr->next != end)
                {
                    ptr=ptr->next;
                }
                end=ptr;
                ptr=ptr->next;
                end->next=nullptr;
            }
            cout<<ptr->info<<" deleted\n";
            delete ptr;
        }
        void del_node(int loc)
        {
            if(start==nullptr)
            {
                cout<<"Underflow\n";
                return;
            }
            if(start->info == loc)
            {
                del_first();
                return;
            }
            if(end->info == loc)
            {
                del_last();
                return;
            }
            node *ptr1,*ptr2;
            ptr1=start->next;
            ptr2=start;
            while(ptr1!=end and ptr1->info != loc)
            {
                ptr2=ptr1;
                ptr1=ptr1->next;
            }
            if(ptr1==end)
            {
                cout<<"Location not found\n";
                return;
            }
            ptr2->next=ptr1->next;
            cout<<"Deleted\n";
            delete ptr1;
        }
        void display()
        {
            if(start==nullptr)
            {
                cout<<"List is empty\n";
                return;
            }
            node *ptr=start;
            while (ptr!=nullptr)
            {
                cout<<ptr->info<<" ";
                ptr=ptr->next;
            }
            cout<<endl;
           
        }
};

int main()
{
    int n,item,loc;
    linked_list l1;
    do
    {
        system("cls");
        cout<<"1. Add First\n";
        cout<<"2. Add Last\n";
        cout<<"3. Add before\n";
        cout<<"4. Add After\n";
        cout<<"5. Del first\n";
        cout<<"6. Del last\n";
        cout<<"7. del node\n";
        cout<<"8. display\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice:";
        cin>>n;
        switch (n)  
        {
        case 1:
            cout<<"Enter item:";
            cin>>item;
            l1.add_first(item);
            break;
        case 2:
            cout<<"Enter item:";
            cin>>item;
            l1.add_last(item);
            break;
        case 3:
            cout<<"Enter item and location:";
            cin>>item>>loc;
            l1.add_before(item,loc);
            break;
        case 4:
            cout<<"Enter item and location:";
            cin>>item>>loc;
            l1.add_after(item,loc);
            break;
        case 5:
            l1.del_first();
            break;
        case 6:
            l1.del_last();
            break;
        case 7:
            cout<<"Enter item to delete:";
            cin>>item;
            l1.del_node(item);
            break;
        case 8:
            l1.display();
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input\n";
            break;
        }
        getch();
    } while (n != 0);
   
}