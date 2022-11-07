#include<iostream>
#include<fstream>
using namespace std;

class shopping{
private:
  int pcode;
  float price;
  float discount;
  string pname;
public:
  void menu();
  void adminstrator();
  void buyer();
  void add();
  void edit();
  void rem();
  void list();
  void receipt();
};
void shopping :: menu(){
  m:
  int choice;
  string email;
  string password;
  cout<<"\t\t\t                         \n";
  cout<<"\t\t\t     SUPERMARKET MENU    \n";
  cout<<"\t\t\t                         \n";
  cout<<"\t\t\t_________________________\n";
  cout<<"\t\t\t                         \n";
  cout<<"\t\t\t|      1)Adminstrator    \n";
  cout<<"\t\t\t|                        \n";
  cout<<"\t\t\t|      2)Buyer           \n";
  cout<<"\t\t\t|                        \n";
  cout<<"\t\t\t|      3)Exit            \n";
  cout<<"\t\t\t|                        \n";
  cout<<"\t\t\t     Please Select       \n";
  cin>>choice;
  switch(choice){
    case 1:
      cout<<" Please Login \n";
      cout<<" Enter Email  \n";
      cin>>email;
      cout<<" Enter Password \n";
      cin>>password;
      if(email=="nikhil125@gmail.com" && password == "iloveProgramming"){
        adminstrator();
      }
      else{
        cout<<"invalid password/email";
      }
      break;
    case 2:
    {
      buyer();
    }
    case 3:
    {
      exit(0);
    }
    default:
    {
      cout<<"please select from given option";
    }
  }
  goto m;
}
void shopping:: adminstrator(){
  m:
  int choice;
  cout<<"\n\n\t\t\t Adminstrator MENU\n";
  cout<<"\t\t\t|___1)Add The product____\n";
  cout<<"\t\t\t|_______________________\n";
  cout<<"\t\t\t|__2)Modify The Product__\n";
  cout<<"\t\t\t|_______________________\n";
  cout<<"\t\t\t|__3)Delete The Product__\n";
  cout<<"\t\t\t|_______________________\n";
  cout<<"\t\t\t|__4)Back To Main Menu___\n";

  cout<<"\n\t\t\t Please Enter Your Choice";
  cin>>choice;

  switch(choice){
    case 1:
    add();
    break;
    case 2:
    edit();
    break;
    case 3:
    rem();
    break;
    case 4:
    menu();
    break;
    default:
    cout<<"invalid Choices";
  }
  goto m;
}
void shopping:: buyer(){
  m:
  int choice;
  cout<<"\t\t\t\t Buyer \n";
  cout<<"\t\t\t\t_________ \n";
  cout<<"                     ";
  cout<<"\t\t\t\t 1) Buy Product \n";
  cout<<"                      ";
  cout<<"\t\t\t\t 2) Go Back \n";
  cout<<"\t\t\t\t\t Enter your choice \n";
  cin>>choice;

  switch(choice){
    case 1:
    receipt();
    break;
    case 2:
    menu();
    default:
    cout<<"Invalid Choice";
  }
  goto m;
}
void shopping:: add(){
  m:
  fstream data;
  int c;
  int token=0;
  float p;
  float d;
  string n;
  cout<<"\n Add new Product";
  cout<<"\n product code of product: ";
  cin>>pcode;
  cout<<"\n Name Of Product: ";
  cin>>pname;
  cout<<"\n Price Of Product: ";
  cin>>price;
  cout<<"\n Discount On Product: ";
  cin>>discount;

  data.open("database.txt",ios::in);

  if(!data){
    data.open("database.txt",ios::app|ios::out);
  //  data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
    data.close();
  }else{
    data>>c>>n>>p>>d;
    while(!data.eof()){
      if(c== pcode){
        token++;
      }
      data>>c>>n>>p>>d;
    }
    data.close();
  }
  if(token == 1){
    goto m;
  }else{
    data.open("database.txt",ios::app|ios::out);
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
    data.close();
  }
   cout<<"\n\n\t\t\t record inserted";
}

void shopping :: edit(){
  fstream data,data1;
  int pkey;
  int token = 0;
  int c;
  float p;
  float d;
  string n;
  cout<<"\n\n\t\t\t Modify The Record";
  cout<<"\n\n\t\t\t Product Code:";
  cin>>pkey;

  data.open("database.txt",ios::in);
  if(!data){
    cout<<"\n\n File Dosnt Exist";
  }else{
    data1.open("database.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>discount;
    while(!data.eof()){
      if(pkey == pcode){
        cout<<"\n\t\t Product New Code";
        cin>>c;
        cout<<"\n\t\t Name of The Product";
        cin>>n;
        cout<<"\n\t\t Price:";
        cin>>p;
        cout<<"\n\t\t Discount: ";
        cin>>d;
        data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
        cout<<"\n\t\t\t Record Edited";
        token++;
      }else{
        data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
      }
      data>>pcode>>pname>>price>>discount;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");
    if(token == 0){
      cout<<"\n\t\t Record Not Found Sorry";
    }
  }
}
void shopping::rem(){
  fstream data,data1;
  int pkey;
  int token = 0;
  cout<<"delete Product \n";
  cout<<" Enter Product Code \n";
  cin>>pkey;
  data.open("database.txt",ios::in);
  if(!data){
    cout<<"file Dos'nt Exist";
  }else{
    data1.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>discount;
    while(!data.eof()){
      if(pcode == pkey){
        cout<<"Packet Deleted SucessFully \n";
        token++;
      }else{
        data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
      }
      data>>pcode>>pname>>price>>discount;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token == 0){
      cout<<"Record not Found \n";
    }
  }
}
void shopping:: list(){
  fstream data;
  data.open("database.txt",ios::in);
  cout<<"\n\n\n|_____________________\n";
  cout<<"proNo\t\tName\t\tPrice\n";
  cout<<"\n\n\n|_____________________\n";
  data>>pcode>>pname>>price>>discount;
  while(!data.eof()){
    cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
    data>>pcode>>pname>>price>>discount;
  }
  data.close();
}
void shopping:: receipt(){
  fstream data;

  int arrc[100];
  int arrq[100];
  char choice;
  int c = 0;
  float amount = 0;
  float discount = 0;
  float total = 0;
  cout<<"\n\n\t\t\t Receipt";
  data.open("database.txt",ios::in);
  if(!data){
    cout<<"\n\n Empty Database";
  }else{
    data.close();

    list();
    cout<<"please Place the order \n";

    do{
      m:
      cout<<"Enter Product Code \n";
      cin>>arrc[c];
      cout<<"Enter the product Quantity \n";
      cin>>arrq[c];
      for(int i = 0; i < c; i++){
        if(arrc[c]==arrc[i]){
          cout<<"Duplicate Code Try Again \n";
          goto m;
        }
      }
      c++;
      cout<<"do you want to buy another product if Yes press 'y' else 'no'";
      cin>>choice;
    }while(choice == 'y');

    cout<<"\n\n\t\t_____________Reciept_________";
    cout<<"\nProduct No\t Product Name \t Product Quantity \t price \t Amount\t Amount with Discount \n";

    for(int i = 0; i < c; i++){
      data.open("database.txt",ios::in);
      data>>pcode>>pname>>price>>discount;
      while(!data.eof()){
        if(pcode == arrc[i]){
          amount = arrq[i]*price;
          discount = amount-(amount*discount/100);
          total = total+discount;
          cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t"<<discount;
        }
        data>>pcode>>pname>>price>>discount;
      }
    }
    data.close();
  }
  cout<<"Total Amount : "<<total;
}
int main(){
  shopping s;
  s.menu();
}
