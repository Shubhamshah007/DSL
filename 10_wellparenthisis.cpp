#include<iostream>
using namespace std;
class stack{
    public:
    char stck[20];
    int top=-1;
    void push(char);
    void pop();
    bool isempt();
    //bool isfull();
};
void stack::push(char x){
    top++;
    stck[top]=x;
}
void stack::pop(){
    top--;
}
bool stack::isempt(){
    if(top==-1)return true;
    return false;
}
int main(){
    char c[20];
    stack st;
    cout<<"Enter your expression :";
    cin>>c;
    int b1,b2,b3;
    b1=b2=b3=0;
    int i=0;
    while(c[i]!='\0'){
        if(c[i]=='['){
            b1++;
            st.push(c[i]);
        }
        else if(c[i]=='{'){
            b2++;
            st.push(c[i]);
        }
        else if(c[i]=='('){
            b3++;
            st.push(c[i]);
        }
        else if(c[i]==']'){
            b1--;
            st.pop();
        }
        else if(c[i]=='}'){
            b2--;
            st.pop();
        }
        else if(c[i]==')'){
            b3--;
            st.pop();
        }
        i++;
    }
    if(st.isempt() && b1==0 && b2 ==0 && b3==0){
       cout<<"\nYour expression is well parenthesised\n"; 
    }
    else{
        cout<<"\nYour expression is not well parenthesised\n";
    }
}