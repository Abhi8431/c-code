#include <iostream>
using namespace std;

class Student{
    int id;
    char name[10];
    float m1;
    float m2;
    float m3;
    float avg;

    public:
        void read();
        void display();
        void calc();
        friend int getTopper(Student arr[2]);
};

void Student :: read(){
    cout<<"Enter the id: ";
    cin>>id;
    cout<<"Enter the name: ";
    cin>>name;
    cout<<"Enter marks 1: ";
    cin>>m1;
    cout<<"Enter marks 2: ";
    cin>>m2;
    cout<<"Enter marks 3: ";
    cin>>m3;
}

void Student :: calc(){
    if(m1>m3 && m2>m3){
        avg = (m1 + m2) / 2;
    }
    else if(m2 > m1 && m3 > m1){
        avg = (m2 + m3) / 2;

    }
    else{
        avg = (m1 + m3) / 2;
    }
}

int getTopper(Student arr[2]){
    int max = arr[0].avg;
    int ind = -1;
    for(int i=0;i<3;i++){
        if(arr[i].avg>max){
            max = arr[i].avg;
            ind = i;
        }
    }
    return ind;
}

void Student :: display(){
    cout<<"|\t"<<id<<"\t|\t"<<name<<"\t|\t"<<avg<<"\t|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
}

int main(){
    Student s[3];
    for(int i=0;i<3;i++){
        s[i].read();
        s[i].calc();
    }
    cout<<"\n-------------------------------------------------"<<endl;
    cout<<"|\tID"<<"\t|\t"<<"NAME"<<"\t|\t"<<"AVG\t|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    for(int i=0;i<3;i++){
        s[i].display();
    }

    int top_ind = getTopper(s);
    cout<<"\n\n\t\t------TOPPER------\n";
    cout<<"\n-------------------------------------------------"<<endl;
    cout<<"|\tID"<<"\t|\t"<<"NAME"<<"\t|\t"<<"AVG\t|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    s[top_ind].display();

    
}
