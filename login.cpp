#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#define MAX 1000
using namespace std;

/*class registration {
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
};*/


//Question-1
int binarySearch(int arr[], int low, int high, int x)
{ 

    if (high >= low) { 
        int mid = low + (high - low) / 2; 
        if (arr[mid] == x) 
            return mid; 

        if (arr[mid] > x) 
            return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x); 
    }
    return -1; 
}

//Question-2

class Stack { 
    int top; 

public: 
    int a[MAX]; // Maximum size of Stack 

    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
}; 

bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 

int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = a[top]; 
        return x; 
    } 
} 

bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 

//Question-3

struct Node 
{ 
    int data; 
    Node *next; 
}; 
  
// Function to insert in list 
void insert(int x, Node **head)  
{ 
    if(*head == NULL) 
    { 
        *head = new Node; 
        (*head)->data = x; 
        (*head)->next = NULL; 
        return; 
    } 
  
    Node *temp = new Node; 
    temp->data = (*head)->data; 
    temp->next = (*head)->next; 
    (*head)->data = x; 
    (*head)->next = temp; 
} 
  
// Function to print the list 
void print(Node *head)  
{ 
    Node *temp = head; 
    while(temp != NULL)  
    { 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
} 
  
Node *merge(Node *firstNode, 
            Node *secondNode)  
{ 
    Node *merged = new Node; 
    Node *temp = new Node;
    merged = temp; 

    while(firstNode != NULL &&  
          secondNode != NULL)  
    {     
        if(firstNode->data <=  
           secondNode->data)  
        { 
            temp->next = firstNode; 
            firstNode = firstNode->next; 
        } 
          
        else 
        { 
            temp->next = secondNode; 
            secondNode = secondNode->next; 
        } 
        temp = temp->next; 
    }   
  
    while(firstNode!=NULL)  
    { 
        temp->next = firstNode; 
        firstNode = firstNode->next; 
        temp = temp->next; 
    } 
  
    while(secondNode!=NULL)  
    { 
        temp->next = secondNode; 
        secondNode = secondNode->next; 
        temp = temp->next; 
    }
    return merged->next; 
} 
Node *middle(Node *head)  
{ 
    Node *slow = head; 
    Node *fast = head->next; 
     
    while(slow->next != NULL &&  
         (fast!=NULL && fast->next!=NULL))  
    { 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
    return slow; 
} 
  
// Function to sort the given list 
Node *sort(Node *head) 
{     
    if(head->next == NULL)  
    { 
        return head; 
    } 
  
    Node *mid = new Node; 
    Node *head2 = new Node; 
    mid = middle(head); 
    head2 = mid->next;    
    mid->next = NULL; 
    Node *finalhead = merge(sort(head), 
                            sort(head2));   
    return finalhead; 
} 



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

*/
    cout<<"Question-1\n";
    int arr[] = { 2, 3, 4, 10, 40 }; 
  
    // Element to be searched 
    int x = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = binarySearch(arr, 0, n - 1, x); 
    (result == -1) 
        ? cout << "Element is not present in array"<<"\n"
        : cout << "Element is present at index " << result<<"\n"; 

 cout<<"\n";

    cout<<"Question-2\n";

    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"; 
    
    //print top element of stack after popping 
    cout << "Top element is : " << s.peek() << endl; 
    
    //print all elements in stack : 
    cout <<"Elements present in stack : "; 
    while(!s.isEmpty()) 
    { 
        // print top element in stack 
        cout << s.peek() <<" "<<"\n"; 
        // remove top element in stack 
        s.pop(); 
    } 
  cout<<"\n";

    cout<<"Question-3\n";

     Node *head = NULL; 
    int n1[] = {7, 10, 5, 20, 3, 2}; 
    for(int i=0;i<6;i++)  
    {
        insert(n1[i], &head);    
    } 
    cout << "Sorted Linked List is: ";
    print(sort(head));
    cout<<"\n\n"; 

    //Question-4 
    /*Advantages of data structures-->
    1)Data modification is easy.
    2) takes very less time.
    3)easy to represent.
    4)takes less memory storage. 
    
    Application of data structures
    1)used in problem solving.
    2)used to build websites and apps etc.
    */
  

  //Question-5

  //time complexity--> Time complexity is used to choose the most effective code based on its execution time.
  //space complexity-->is used to choose the code which takes up very less storage in the memory.
  

   cout<<"Question-6\n";
   string first[] = { "Sachin", "Rakesh", "Sandeep", "Serena" };
    string second[] = { "Vaibhav", "Sandeep", "Rakesh", "Neha" };
    int n_ = sizeof(first) / sizeof(first[0]);
   
    // Print students of first list
    cout << "Students in first class :";
    for (int i = 0; i < n_; i++)
        cout << " " << first[i];
    cout << "\n";
 
    // Print students of second list
    cout << "Students in second class :";
    for (int i = 0; i < n_; i++)
        cout << " " << second[i];
    cout << "\n\n";
 
    vector<string> v(10);
    vector<string>::iterator it, st;
 
    // Sorting both the list
    sort(first, first + n_);
    sort(second, second + n_);
 
    // Using default operator<
    it = set_difference(first, first + n_, second, second + n_, v.begin());
 
    cout << "Students attending first class only are :\n";
    for (st = v.begin(); st != it; ++st)
        cout << ' ' << *st;
    cout << '\n';
    cout<<"\n";
    
    cout<<"Question-7\n";
    int arrayy[]={4,5,6};
    sort(arrayy,arrayy+3);

    do {
        cout<<arrayy[0]<<" "<<arrayy[1]<<" "<<arrayy[2]<<"\n";
    } while(next_permutation(arrayy,arrayy+3));
    cout<<"After sorting :" <<arrayy[0]<<" "<<arrayy[1]<<" "<<arrayy[2]<<"\n";

    return 0; 
}



  
   


















