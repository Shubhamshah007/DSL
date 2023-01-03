#include<iostream>
using namespace std;
int front=-1;
int rear=-1;
#define N 7
int arr[N];
void display(){
    if(front==-1 || front==rear)cout<<"Queue is empty";
    cout<<"Your current front is "<<front<<" and rear is "<<rear<<endl;
    if(rear>=front){
        for(int i=front;i<=rear;i++){
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
void push_front(){
    if( (front==0 && rear==N-1) || (rear==(front-1)%(N-1))){
        cout<<"Queue is full";
        return;
    }
    cout<<"Enter element :\n";
    int n;
    cin>>n;
    if(front==0 && rear!=N-1){
        front=N-1;
    }
    else if(front==-1){
        front=rear=0;
    }
    else{
        front--;
    }
    arr[front]=n;
}

void push_back(){
    if( (front==0 && rear==N-1) || (rear==(front-1)%(N-1))){
        cout<<"Queue is full";
        return;
    }
    cout<<"Enter element :\n";
    int n;
    cin>>n;
    if(front!=0 && rear==N-1){
        rear=0;
    }
    else if(rear==-1 || front==-1){
        front=rear=0;
    }
    else{
        rear++;
    }
    arr[rear]=n;
}

void pop_front(){
    if(front==-1 || front==rear){
        cout<<"Queue is empty\n";
        return;
    }
    if(front==rear){
        front=rear=-1;
        return;
    }
    if(front==N-1){
        front=0;
        return;
    }
    front++;
}

void pop_back(){
    if(rear==front || rear==-1){
        cout<<"Queue is empty\n";
        return;
    }
    if(front==rear){
        front=rear=-1;
    }
    else if(rear==0){
        rear=N-1;
    }
    else{
        
    rear--;
    }
}

int main(){
    int s;
    do{
        cout<<"\n**Menu**\n";
        cout<<"1.Push_front()\n";
        cout<<"2.Pop_front()\n";
        cout<<"3.Push_back()\n";
        cout<<"4.Pop_back()\n";
        cout<<"5.Display()\n";
        cout<<"6.Break\n";
        cout<<"Enter your choice :";
        cin>>s;
        switch(s){
            case 1:
            push_front();
            display();
            break;
            case 2:
            pop_front();
            display();
            break;
            case 3:
            push_back();
            display();
            break;
            case 4:
            pop_back();
            display();
            break;
            case 5:
            display();
            break;
            case 6:
            break;
        }
    }while(s!=6);
}