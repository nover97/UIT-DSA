/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

struct NODE{
    float info;
    NODE *pNext;
};

NODE *CreateNode(float x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}
struct stack{
    NODE *top;
};
bool empty(const stack &s){
    return (s.top==NULL);
}
void CreateEmptyStack(stack &s){
    s.top=NULL;
}
void push(stack &s, float x){
    NODE *p=CreateNode(x);
    if(s.top==NULL) s.top= p;
    else {
        p->pNext=s.top;
        s.top=p;
    }
}
void pop (stack &s) {
    if(s.top==NULL) return;
    NODE *p= s.top;
    s.top=s.top->pNext;
    delete p;
}
float& top(stack s) {
    return s.top->info;
}
bool isOperator(char x){
    return ( (x=='-') || (x=='+')|| (x=='*') || (x=='/') || (x=='^') );
}
bool isBracket(char x){
    return ( (x=='(') || (x==')') );
}
void InputPostFix(char postix[], int &n){
    char k;
    cin >> k;
    n=0;
    while (k!='#'){
        postix[n++] = k;
        cin >> k;
    }
}

//###INSERT CODE HERE -

float calcu(float x, char a, float y){
	float c=0;
	switch(a){
	case '+': c=x+y; break;
	case '-': c=x-y; break;
	case '*': c=x*y; break;
	case '/': c=x/y; break;
	case '^': c=pow(x,y);	}
	return c;
}
float evaluate_expression(char *postfix,int np){
	stack s; CreateEmptyStack(s); char token;
	for(int i=0;i<np;i++){
		token=postfix[i];
		if(isOperator(token)){
			float b=top(s); pop(s);
			float a=top(s); pop(s);
			float c=calcu(a,token,b);
			push(s,c);	}
		else
			push(s,(int)token-48);	}
		return top(s);	
}
int main() {
    char postfix[MAXN];
    int np;

    InputPostFix(postfix, np);
    // Output(postfix, np);

    cout.precision(3);
    cout << evaluate_expression(postfix, np);

    return 0;
}
