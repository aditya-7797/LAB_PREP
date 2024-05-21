#include<iostream>
#include<stack>

using namespace std;

int Binary_num[32];


void decimal_to_binary(int n){

    int i = 0;
    while(n > 0){

        Binary_num[i]= n % 2;
        n /= 2;
        i++;
    }


}




int main(){
    
    stack<int> s;

    
    s.push(1);
    cout<<"You are in Room 1";
    s.push(2);
    cout<<"You are in Room 2";

    s.push(3);
    cout<<"You are in Room 3";

    s.push(4);
    cout<<"You are in Room 4";

    s.push(5);
    cout<<"You are in Room 5";
    cout<<"Enter secreate code in decimal format";
    int n;
    cin>>n;
    decimal_to_binary(n);



    for(int i=1;i<6;i++){
        s.pop();
    }

    cout<<"You are in Room 1";
    cout<<"You can unlock treasure with following code";
    for(int i =0;i<12;i++){

        cout<<Binary_num[i];

    }


    return 0;

}