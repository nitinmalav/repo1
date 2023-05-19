#include<iostream>
using namespace std;
class node{
    public:
        int info;
        node *left,*right;
        node(int item)
        {
            info=item;
            left=right=nullptr;
        }
};
class BST{
    node *root;
    pair<node*,node*> p;
    void inord(node* root)
    {
        if(root==nullptr)
            return;
        inord(root->left);
        cout<<root->info<<" ";
        inord(root->right);
    }
    public:
        BST()
        {
            root=nullptr;
        }
        pair<node*,node*> find(int item)
        {
            node *ptr,*save;
            ptr=root;
            save=nullptr;
            while(ptr!=nullptr)
            {
                if(ptr->info==item)
                    break;
                save=ptr;
                if(item<ptr->info)
                    ptr=ptr->left;
                else
                    ptr=ptr->right;
            }
            return pair<node*,node*>(ptr,save);
        }
        void add_bst(int item)
        {
            pair<node*, node*> p;
            p=find(item);
            node *ptr, *save;
            ptr=p.first;
            save=p.second;
            if(ptr != nullptr)
            {
                cout<<"Duplicate item\n";
                return;
            }
            node *newptr=new node(item);
            if(save == nullptr)
            {
                root=newptr;
            }
            else
            {
                if(item<save->info)
                    save->left=newptr;
                else
                    save->right=newptr;
            }
        }
        void inorder()
        {
            inord(root);
            cout<<endl;
        }
    private:
        void case_a(node*ptr, node* save)
        {
            node *child;
            if(ptr->left != nullptr)
                child=ptr->left;
            else if( ptr->right != nullptr)
                child=ptr->right;
            else    
                child=nullptr;
            if(save==nullptr)
            {
                root=child;
            }
            else
            {
                if(ptr->info<save->info)
                    save->left=child;
                else
                    save->right=child;
            }
        }

        void case_b(node*ptr, node*save)
        {
            node *succ,*par_succ;
            succ=ptr->right;
            par_succ=ptr;
            while(succ->left != nullptr)
            {
                par_succ=succ;
                succ=succ->left;
            }
            case_a(succ,par_succ);
            if(save==nullptr)
            {
                root=succ;
            }
            else
            {
                if(ptr->info < save->info)
                    save->left=succ;
                else
                    save->right=succ;
            }
            succ->left=ptr->left;
            succ->right=ptr->right;

        }
    public:
        void del_bst(int item)
        {
            pair<node*, node*> p;
            p=find(item);
            node* ptr,*save;
            ptr=p.first;
            save=p.second;
            if(ptr==nullptr)
            {
                cout<<"Item not found";
                return;
            }
            if(ptr->left != nullptr and ptr->right != nullptr)
            {
                case_b(ptr,save);
            }
            else
            {
                case_a(ptr,save);
            }
            cout<<ptr->info<<" Deleted\n";
            delete ptr;
        }
};
int main()
{
    BST b1;
    b1.add_bst(10);
    b1.add_bst(8);
    b1.add_bst(9);
    b1.add_bst(12);
    b1.add_bst(11);
    b1.add_bst(13);
    b1.add_bst(7);
    b1.inorder();
    b1.del_bst(11);
    b1.inorder();
    b1.del_bst(8);
    b1.inorder();
}