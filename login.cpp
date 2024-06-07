#include<iostream>
#include<math.h>
#include<string>

using namespace std;

class registration {
    public:
    string Firstname;
    string Lastname;
    string emailid;
    string password; //it should contain atleast a number and alphabet as well as special character and should be 8 chars long.
    string renter;
    int contact[10];
    char Gender;
    
    void checking(string password,string renter) {
        int i=1;
        while(password!=renter) {
            cout<<"Wrong password! Please enter again to confirm: ";
            cin>>renter;
            i++;
        }
        cout<<password<<"\n";
    }
    void size(string password){
        int i=1;
        while(sizeof(password)<8){
            cout<<"Password should have atleast 8 digits: ";
            cin>>password;
         i++;
        }
       
    }
    void alpha(char Gender){
       if(Gender=='f'||Gender=='m'||Gender=='F'||Gender=='M') {
            cout<<"your gender is :"<<Gender<<"\n";
            
        }
        int i=1;
        while(Gender!='f' || Gender!='m'|| Gender!='F'|| Gender!='M')
       {
        break;
        cout<<"Error! please enter gender again: ";
        cin>>Gender;
        if(Gender=='f'||Gender=='m'||Gender=='F'||Gender=='M') { //here if it gets equal print the f or m!
            cout<<"your gender is: "<<Gender<<"\n"; //loop mein condition lagayi!
            break;
        }
        i++;
        }
        
        
    }  
    
};

class Login:public registration{
      public:
      string username;
      string user;
      string pass;
      void checkuser(string username,string user){
       int i=1;
       while(username!=user){
        cout<<"You've entered wrong username please enter again: ";
        cin>>user;
        i++;
       }
       cout<<"the username is: "<<username<<"\n";
      }
      void checkpass(string password,string pass){
        int i=1;
        while(password!=pass) {
            cout<<"You've entered wrong password! please enter the password again: ";
            cin>>pass;
        }
        cout<<"the password is: "<<password<<"\n";
      }
};
  
int main() {
    /*cout<<"WELCOME_TO_THE_REGISTRATION_LOGIN_FORM\n";

    cout<<"REGISTER\n";
    registration r1;
    cout<<"Enter the first name: ";
   cin>>r1.Firstname;
   cout<<"Enter the last name: ";
   cin>>r1.Lastname;
   cout<<"Enter the email id:  ";
   cin>>r1.emailid;
   cout<<"Enter the password: ";
   cin>>r1.password;
   cout<<"Enter the password again: ";
   cin>>r1.renter;
   r1.checking(r1.password,r1.renter);
   cout<<"Enter the contact: ";
   
   for(int i=0;i<10;i++){
   cin>>r1.contact[i];
   }
   for(int i=0;i<10;i++){
    cout<<r1.contact[i];
       }
    cout<<"\n";
   cout<<"Enter the Gender: "<<"\n";
   cin>>r1.Gender;
   r1.alpha(r1.Gender);
   cout<<"Your data has been stored!\n\n\n";

   cout<<"The account already exists!"<<"\t"<<"LOGIN here if already have an account\n\n";
   Login l1;
   cout<<"Enter the Username: ";
   cin>>l1.user;
   cout<<"Enter the password: ";
   cin>>l1.pass;
   l1.checkuser("Raksha005",l1.user);
   l1.checkpass(r1.password,l1.pass); //we have compared the password of r1 to the pass of l1.
   cout<<"you have logged in!\n"; 
return 0;
}

   
