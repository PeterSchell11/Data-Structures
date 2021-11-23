#include <iostream>
#include <string>
using namespace std;

class Customer{ //customer class def
  private:
    string custID;
    string custName;
    string custAddress;

  public:
    Customer();
    virtual void registerCustomerInfo();
    virtual void printCustomerInfo();
};

void Customer::registerCustomerInfo(){
  //Customer info Input
  cout << "Enter Customer ID : " ; cin>>custID;
  cout << "Enter Name Of Customer : " ; cin>>custName;
  cout << "Enter customer address : " ; cin>>custAddress;
}

void Customer::printCustomerInfo() { // print customer info
  cout << "Customer ID : " << custID << endl;
  cout << "Name : " << custName << endl;
  cout << "Adddress : "<< custAddress<< endl;
}


class General: public Customer{
  //General Customer class derived from customer class
  public:
    General();
    void registerCustomerInfo(){
      Customer::registerCustomerInfo();
    }
    void printCustomerInfo(){
      cout << "Customer Type : General\n";
      Customer::printCustomerInfo();
    }
};

class PreferredCustomer : public Customer{
  private:
    string tier;
  public:
    PreferredCustomer();
    void registerCustomerInfo(){

      Customer::registerCustomerInfo(); //  base class function call
      
      int choice;
      cout<<"Enter Customer Tier"<<endl;
      cout<<"\t1- Tier1"<<endl;
      cout<<"\t2- Tier2"<<endl;
      cout<<"\t3- Tier3"<<endl;
      cout<<"\nChoice : ";cin>>choice;
      //Possible while here?
      switch(choice){
      case 1:
      tier = "Tier1";break;
      case 2:
      tier = "Tier2";break;
      case 3:
      tier = "Tier3";break;
      default:
      cout<<"Invalid Entry"<<endl;
      }
    }

    void printCustomerInfo(){
      cout << "Customer Type : Preferred : " << tier << endl;
      Customer::printCustomerInfo();
    }
};

class BlacklistedCustomer : public Customer{
  private:
    string blacklistDate;
  public:
    BlacklistedCustomer();
    void registerCustomerInfo(){
      Customer::registerCustomerInfo();
      cout << "Enter BlackListed Date : ";
      cin>>blacklistDate;
    }
    void printCustomerInfo(){
      cout << "Customer Type : BlackListed" << "\nBlacklisted Date: " << blacklistDate << endl;
      Customer::printCustomerInfo();
    }

  };


//default constructors for classes
Customer::Customer() { custID = custName = custAddress = "" ; }
General::General(){} 
PreferredCustomer::PreferredCustomer() { tier = "" ; }
BlacklistedCustomer:: BlacklistedCustomer() { blacklistDate = "" ; }


int main() {
  Customer* customer[100];
  int choice, i = 0;;

  cout << "\nSelect Customer Type" << endl;
  cout << "1. General Customer." << endl;
  cout << "2. Preferred Customer." << endl;
  cout << "3. BlackListed Customer."<< endl;
  cout << "\nChoice : "; cin >> choice;
  cout << "\n\n";

  switch(choice){
    case 1:{
    customer[i] = new General(); break;// dynamic allocation of memory and create object
    }
    case 2:{
    customer[i] = new PreferredCustomer(); break;   // dynamic allocation of memory and create object
    }
    case 3:{
      customer[i] = new BlacklistedCustomer(); break;   // dynamic allocation of memory and create object
    
    } 
  }
  customer[i]->registerCustomerInfo();   
  cout<<endl;
  customer[i]->printCustomerInfo();

  i++;
}
