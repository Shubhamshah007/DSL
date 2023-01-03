#include<iostream>
using namespace std;
int front=-1;
int rear=-1;
#define N 3
int arr[N];
void display(){
    if(front==-1 || front==rear)cout<<"Queue is empty";
    cout<<"Your current front is "<<front<<" and rear is "<<rear<<endl;
    if(rear>=front){
        for(int i=front%(N);i<=rear;i++){
            cout<<i<<" "<<arr[i]<<endl;
        }
    }
    else{
        for(int i=front;i<N;i++){
            cout<<i<<" "<<arr[i]<<endl;
        }
        for(int i=0;i<=rear;i++){
            cout<<i<<" "<<arr[i]<<endl;
        }
    }
}
bool isfull(){
    if(rear==N-1 && front==0){
        //cout<<"Queue is full 4\n";
        return true;
    }
    else if(rear==(front-1)%(N-1)){
        //cout<<"Queue is full 5\n";
        return true;
    }  
    return false;
    
}
bool isempt(){
    if(front==-1){
        return true;
    }
    return false;
}
void push(){
    if(isfull()){
        cout<<"Queue is full\n";
        return;
    }
    cout<<"Enter the element :";
    int n;
    cin>>n;
    if(rear==N-1){
        rear=0;
        arr[rear]=n;
        display();
        return;
    }
    else{    
        rear++;
        if(front==-1)front=0;
        arr[rear]=n;
        display();
        return;
    }   
}
void pop(){
    if(isempt()==true){
        cout<<"Queue is empty\n";
        return;
    }
    else if(front==rear){
    front=rear=-1;
    }
    else if(front==N-1){
        front=0;
    }
    else{
        front++;
    }   
    if(front==rear)front=rear=-1;
    display();
}

void qfront(){
    if(front==rear){
        cout<<"Queue is empty";
    }
    cout<<arr[front];
}
int main(){
    int s;
    do{
        cout<<"\n**Menu**\n";
        cout<<"1.Push()\n";
        cout<<"2.Pop()\n";
        cout<<"3.Front()\n";
        cout<<"4.Display()\n";
        cout<<"5.Break\n";
        cout<<"Enter your choice :";
        cin>>s;
        switch(s){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            qfront();
            break;
            case 4:
            //cout<<"l";
            display();
            break;
            case 5:
            break;
        }
    }while(s!=5);
}