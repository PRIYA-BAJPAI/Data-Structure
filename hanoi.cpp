#include<iostream>
#include<string>
using namespace std;
void Hanoi(int n,char from,char to,char Aux){
    if(n==1){
        cout<<"Move disk 1 from "<<from<<" to "<<to<<endl;  //1
        return;
    }
    Hanoi(n-1,from,Aux,to);  //2
    cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;  //3
    Hanoi(n-1,Aux,to,from);  //4
}
int main(){
    int n;
    cout<<"Enter no. of disks : ";
    cin>>n;
    char A='A';
    char B='B';
    char C='C';
    Hanoi(n,A,C,B);
    return 0;
}