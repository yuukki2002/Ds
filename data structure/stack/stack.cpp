#include <iostream>
using namespace std;
#define MAXSIZE 100
#define ElemtType char

// 顺序存储结构的栈

typedef struct {
    ElemtType data[MAXSIZE];
    int top;
} Stack;

void InitStack(Stack &s) {
    s.top = -1;
}

bool StackEmpty(Stack s){
    return s.top == -1;
}

bool Push(Stack &s, ElemtType x){
    if(s.top == MAXSIZE - 1){
        cout << "Stack overflow" << endl;
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool Pop(Stack &s, ElemtType &x){
    if(s.top == -1){
        cout << "Stack underflow" << endl;
        return false;
    }
    x = s.data[s.top--];
    return true;
}

bool GetTop(Stack s, ElemtType &x){
    if(s.top == -1){
        cout << "Stack underflow" << endl;
        return false;
    }
    x = s.data[s.top];
    return true;
}

// 堆栈的应用：括号匹配

bool Match(){
    Stack s;
    InitStack(s);
    char c;
    cin>>c;
    while(c!='\0'){
        switch(c){
            case '(':
            case '[':
            case '{':
                Push(s, c);
                break;
            case ')':
                if(StackEmpty(s) || GetTop(s) != '(')
                    return false;
                Pop(s, c);
                break;
            case ']':
                if(StackEmpty(s) || GetTop(s) != '[')
                    return false;
                Pop(s, c);
                break;
            case '}':    
                if(StackEmpty(s) || GetTop(s) != '{')
                    return false;
                Pop(s, c);
                break;
        }
        cin>>c;
    }
    return StackEmpty(s);
}

// 堆栈的应用：中缀表达式转后缀表达式
typedef enum {
    ADD=1, SUB=1, MUL=2, DIV=2
    } Operator;

Operator GetOperator(char c){
    switch(c){
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
    }
}

void InfixToPostfix(){
    Stack s;
    InitStack(s);
    char Infix[MAXSIZE],Postfix[MAXSIZE];
    int cnt = 0;
    cin>>Infix;
    for(int i=0;i<MAXSIZE;i++){
        if(Infix[i] == '\0')
            break;
        if(Infix[i] >= '0' && Infix[i] <= '9')
            Postfix[cnt++] = Infix[i];
        else if(Infix[i] == '(')
            Push(s, Infix[i]);
        else if(Infix[i] == ')'){
            char c;
            while(GetTop(s, c) && c != '('){
                Pop(s, c);
                Postfix[cnt++] = c;
            }
            Pop(s, c);  // 弹出'('
        }
        else if(Infix[i] == '+' || Infix[i] == '-' || Infix[i] == '*' || Infix[i] == '/'){
            char c;
            while(GetTop(s, c) && GetOperator(c) >= GetOperator(Infix[i])){// 栈顶运算符优先级高
                Pop(s, c);
                Postfix[cnt++] = c;
            }
            Push(s, Infix[i]);
        }
        
    }

    for (int i = 0; i < cnt; i++){
        cout << Postfix[i];
        cout << endl;
    }
}

// 堆栈的应用：后缀表达式求值
int value(char c){
    return c - '0';
}

int EvaluatePostfix(){
    Stack s;
    InitStack(s);
    char Postfix[MAXSIZE];
    int cnt = 0;
    cin>>Postfix;
    for(int i=0;i<MAXSIZE;i++){
        if(Postfix[i] == '\0')
            break;
        if(Postfix[i] >= '0' && Postfix[i] <= '9')
            Push(s, Postfix[i] - '0');
        else{
            char a, b;
            Pop(s, b);
            Pop(s, a);

            switch(Postfix[i]){
                case '+':
                    Push(s, a + b);
                    break;
                case '-':
                    Push(s, a - b);
                    break;
                case '*':
                    Push(s, a * b);
                    break;
                case '/':
                    Push(s, a / b);
                    break;
            }
        }
    }
}