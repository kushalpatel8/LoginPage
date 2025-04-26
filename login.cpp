#include <bits/stdc++.h>
using namespace std;

class Page
{
    string userName, Email, password;
    string userSearch, passSearch, emailSearch;
    fstream file;

public:
    void login();
    void signup();
    void forget();
}obj;

int main () {
    char ch;
    cout << "\n1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice :: ";
    cin  >> ch;

    switch(ch) {
        case '1' :
            cin.ignore();
            obj.login();
            break;
        
        case '2' :
            cin.ignore();
            obj.signup();
            break;
        
        case '3' :
            cin.ignore();
            obj.forget();
            break;

        case '4' :
            return 0;
        
        default : 
            cout << "Invalid Selection.....";
    }
}

void Page :: signup() {
    cout << "\n Enter Your Username : ";
    getline(cin, userName);
    cout << "\n Enter your Email address :";
    getline(cin, Email);
    cout << "\n Enter your password : ";
    getline(cin, password);

    file.open("LoginData.txt", ios :: out | ios :: app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}

void Page :: login() {

    cout << "----------LOGIN---------" << endl;
    cout << "Enter Your user Name :: " <<endl;
    getline(cin, userSearch);
    cout << "Enter Your Passward ::" <<endl;
    getline (cin, passSearch);

    file.open("LoginData.txt", ios :: in);
    getline(file, userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while (!file.eof()) {
        if(userName == userSearch) {
            if (password == passSearch) {
            cout << "\nAccount Login Succesfull....";
            cout << "\nUserName :: " << userName <<endl;
            cout << "\nEmail :: "  << Email << endl;
            }
            else {
                cout << "Passward is incorrect...";
            }
        }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
    }
}


void Page :: forget() {
    cout << "\nEnter your username :: ";
    getline(cin, userName);
    cout << "\n Enter your Email :: ";
    getline(cin, emailSearch);
    
    file.open("LoginData.txt", ios :: in);
    getline(file,userName, '*');
    getline(file,Email, '*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName == userSearch){
            if(Email == emailSearch){
                cout<<"\nAccount Found...!"<<endl;
                cout<<"Your Password :: "<<password<<endl;
            }else{
                cout<<"Not found...!\n";
            }
        }else{
            cout<<"\nNot fount...!\n";
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    }
    file.close();

}