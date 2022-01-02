#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *next;
};
struct stack
{
    node *phead;
};
bool empty(stack k)
{
    return k.phead == NULL;
}
void CreateEmptyStack(stack &k)
{
    k.phead = NULL;
}
void push(stack &k, int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    if (!empty(k))
        p->next = k.phead;
    k.phead = p;
}
int top(stack &k)
{
    if (!empty(k))
        return k.phead->info;
    return NULL;
}
int pop(stack &k)
{
    node *p = k.phead;
    k.phead = p->next;
    delete p;
}
void PrintStack(stack &k)
{
    for (node *i = k.phead; i != NULL; i = i->next)
        cout << i->info;
}

void DecToBin(stack &k, int n)
{
    push(k, n % 2);
    if (n >= 2)
        return DecToBin(k, n / 2);
}
void decimal_to_binary(int n)
{
    stack k;
    CreateEmptyStack(k);
    DecToBin(k, n);
    PrintStack(k);
}
int main()
{
    decimal_to_binary(192);
    return 0;
}
