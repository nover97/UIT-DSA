/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 100

struct NODE
{
	char info;
	NODE *pNext;
};
NODE *CreateNode(char x)
{
	NODE *p = new NODE;
	p->info = x;
	p->pNext = NULL;
	return p;
}
struct stack
{
	NODE *top;
};
bool empty(const stack &s)
{
	return (s.top == NULL);
}
void CreateEmptyStack(stack &s)
{
	s.top = NULL;
}
void push(stack &s, char x)
{
	NODE *p = CreateNode(x);
	if (s.top == NULL)
		s.top = p;
	else
	{
		p->pNext = s.top;
		s.top = p;
	}
}
void pop(stack &s)
{
	if (s.top == NULL)
		return;
	NODE *p = s.top;
	s.top = s.top->pNext;
	delete p;
}
char &top(stack s)
{
	return s.top->info;
}

//###INSERT CODE HERE -
int Rank(char x)
{
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	if (x == '^')
		return 3;
}
bool isOperator(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
		return 1;
	return 0;
}
void Input_infix(char *infix, int &ni)
{
	ni = 0;
	char x;
	cin >> x;
	while (x != '#')
	{
		infix[ni++] = x;
		cin >> x;
	}
}
void infix_to_postfix(char *infix, int &ni, char postfix[], int &np)
{
	stack s;
	CreateEmptyStack(s);
	np = 0;
	char token;
	for (int i = 0; i < ni; i++)
	{
		token = infix[i];
		if (isOperator(token))
		{
			while (!empty(s) && isOperator(top(s)) && Rank(top(s)) >= Rank(token))
			{
				postfix[np++] = top(s);
				pop(s);
			}
			push(s, token);
		}
		else if (token == '(')
			push(s, token);
		else if (token == ')')
		{
			while (top(s) != '(')
			{
				postfix[np++] = top(s);
				pop(s);
			}
			pop(s);
		}
		else
			postfix[np++] = token;
	}
	while (!empty(s))
	{
		postfix[np++] = top(s);
		pop(s);
	}
}
void Output(char postfix[], int np)
{
	for (int i = 0; i < np; i++)
		cout << postfix[i] << " ";
}
int main()
{
	char infix[MAXN], postfix[MAXN];
	int ni, np;

	Input_infix(infix, ni);

	infix_to_postfix(infix, ni, postfix, np);

	Output(postfix, np);

	return 0;
}
