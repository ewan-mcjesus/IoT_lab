#include <bits/stdc++.h>
using namespace std;

int present, p;
struct node
{
    int info = 0;
    node *right = NULL, *left = NULL;
} *root = NULL;

node *search(int n)
{
    cout << "in search\n";
    present = 0;
    node *par;
    node *np = root;

    while (np != NULL)
    {
        if (np->info == n)
        {
            present = 1;
            return np;
        }
        if (np->info > n)
        {
            cout << np->info << " left ";
            par = np;
            np = np->left;
        }
        else if (np->info < n)
        {
            cout << np->info << " right ";
            par = np;
            np = np->right;
        }
    }

    return par;
}

void insert(int n)
{
    cout << "in insert1\n";
    node *s = search(n);
    cout << "back in insert\n";

    node *np = new node;
    np->info = n;
    if (root == NULL)
    {
        root = np;
        return;
    }
    if (present)
    {
        cout << "already present\n";
        return;
    }
    else
    {
        if (n > s->info)
            s->right = np;
        else
            s->left = np;
    }
    return;
}

void traverse_pre(node *np = root)
{

    if (np == NULL)
        return;
    cout << np->info << " ";

    traverse_pre(np->left);
    traverse_pre(np->right);

    // cout << "\n";
}

void traverse_in(node *np = root)
{

    if (np == NULL)
        return;

    traverse_in(np->left);
    cout << np->info << " ";

    traverse_in(np->right);

    // cout << "\n";
}

void traverse_post(node *np = root)
{

    if (np == NULL)
        return;

    traverse_post(np->left);
    traverse_post(np->right);
    cout << np->info << " ";

    // cout << "\n";
}

void del(int n)
{
    node *s = search(n);
    if (!present)
    {
        cout << "element not present\n";
        return;
    }
    if (s->left == NULL && s->right == NULL)
        s = NULL;
    
}

int main()
{
    int ch;
    bool cont = true;
    while (ch)
    {
        cout << "enter choice: \n 1. insert\n 2.default\n 3.traverse\n ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int x;
            cin >> x;
            insert(x);
            break;
        case 2:
            int x;
            cin >> x;
            del(x);

        case 3:
            traverse_pre();
            cout << "\n";
            break;
        case 4:
            traverse_in();
            cout << "\n";
            break;
        case 5:
            traverse_post();
            cout << "\n";
        default:
            break;
        }
    }
}