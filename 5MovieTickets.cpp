#include<iostream>
using namespace std;
class MovieTicket{
    int X=0; //customer ID
    int Y; //movie ID
    public:
    int AvailableSeats1 = 100;  //there are two movies in the theatre: 1 and 2
    int AvailableSeats2 = 100;
    void Action(){
    string action;//what does the customer want to do?
    abc:
    cin>>action;
    cin>>X;//0,1,2,12
    if(action =="book"){
        cout<<"enter movie to book:";
        cin>>Y;
        if(Y==1 && (X==1 || X==12)){
            cout<<"false";
        }
        else if(Y==2 && (X==2 || X==12)){
            cout<<"false";
        }
        else if(Y==1){
            AvailableSeats1--;
            cout<<"true";
            X=1;
        }
        else if(Y==2){
            AvailableSeats2--;
            cout<<"true";
            X=2;
        } 
        else if(Y==1 && X==2){
            AvailableSeats1--;
            cout<<"true";
            X=12;
        }
        else if(Y==2 && X==1){
            AvailableSeats2--;
            cout<<"true";
            X=12;
        }   } 
    else if(action=="cancel"){
        int duration;
        cout<<"Enter duration:";
        cin>>duration;
        if (duration<=30){
        cout<<"ENter movie to cancel";
        cin>>Y;
        if(Y==1 && (X==1)){
            cout<<"true";
            AvailableSeats1++;
            X=0;
        }
        else if(Y==2 && (X==2)){
             cout<<"true";
            AvailableSeats2++;
            X=0;
        }
        else if(Y==1 && X==12){
            AvailableSeats1++;
            cout<<"true";
            X=2;
        }
        else if(Y==2 && X==12){
            AvailableSeats2++;
            cout<<"true";
            X=1;
        } 
        else if(Y==1 && X==2){
            cout<<"false";
        }
        else if(Y==2 && X==1){
            cout<<false;
        }  }
        else if(action=="cancel" && duration>30){
            cout<<"NOT APPLICABLE";
        }
    }
    else if(action=="check"){
        cout<<"The movie IDs booked are:"<<X;
    }
    else if(action=="available"){
        cout<<"ENter movie ID";
        cin>>Y;
        cout<<"The number of available seats are:";
        if(Y==1){
            cout<<AvailableSeats1;
        }
        else if(Y==2){
            cout<<AvailableSeats2;
        }
    }
    int terminate;
    cout<<endl<<"If you wish to terminate the program enter 1 else 0";
    cin>>terminate;
    if(terminate==0){
        goto abc;
    }
}
};
int main(){
    MovieTicket a1;
    a1.Action();
    return 0;
}