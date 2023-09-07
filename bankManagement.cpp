#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

class BankAccount{
    private:
        string name;
        int accountNum;
        double balance;

    public:
        //constructor
        BankAccount(string n, int acc, double bal){
            name = n;
            accountNum = acc;
            balance = bal;
        }

        //getters
        string getName(){
            return name;
        }

        int getAccountNum(){
            return accountNum;
        }

        double getBalance(){
            return balance;
        }

        void deposit(double amount){
            balance += amount;
        }
        void withdraw(double amount){
            if (balance >= amount){
                balance -= amount;
                cout<<"\tWithdrawn successfully!"<<endl;
            }
            else{
                cout<<"\tInsufficient Balance."<<endl;
            }
            
        }
};

class BankManagement{
    private:
        vector<BankAccount> accounts;

    public:
        void addAccount(string name, int accountNum, double balance){
            accounts.push_back(BankAccount(name, accountNum, balance));
        }
        void showAccounts(){
            cout<<"\tAll Accounts:\n"<<endl;

            for (int i = 0; i < accounts.size(); i++){
                cout<<"1. Name: "<<accounts[i].getName()<<endl;
                cout<<"   Account Number: "<<accounts[i].getAccountNum()<<endl;
                cout<<"   Balance: "<<accounts[i].getBalance()<<endl;
                cout<<""<<endl;
                sleep(1);
            }
        }
        void searchAccount(int accountNum){
            cout<<"\t\nAccount Holder:\n"<<endl;

            for(int i = 0; i<accounts.size(); i++){
                if(accounts[i].getAccountNum() == accountNum){
                    cout<<"Name: "<<accounts[i].getName()<<endl;
                    cout<<"Account Number: "<<accounts[i].getAccountNum()<<endl;
                    cout<<"Balance: "<<accounts[i].getBalance()<<endl;
                    cout<<""<<endl;
                    
                    break;
                }
            }
            sleep(1);
        }
        //return pointer so that actual bank account is updated
        BankAccount* findAccount(int accountNum){
            for (int i = 0; i < accounts.size(); i++)
            {
                if(accounts[i].getAccountNum() == accountNum){
                    return &accounts[i]; //return address of array element (account)
                }
            }
            return 0;
        }
        
};

int main(int argc, char const *argv[])
{
    BankManagement bank;
    int currentChoice;

    do
    {
        cout<<"--- Bank Management System ---\n"<<endl;
        cout<<"\t    :: Main Menu ::\n"<<endl;
        cout<<"\t1. Create New Account"<<endl;
        cout<<"\t2. All Accounts"<<endl;
        cout<<"\t3. Search Account"<<endl;
        cout<<"\t4. Deposit "<<endl;
        cout<<"\t5. Withdraw "<<endl;
        cout<<"\t6. Exit\n "<<endl;
        
        cout<<"Please enter the desired choice: ";

        cin>>currentChoice;
        cout<<""<<endl;

        switch (currentChoice)
        {   
            //create new account
            case 1:{
                
                string name;
                int accountNum;
                double balance;

                cout<<"\n\tEnter your name: ";
                cin>>name;
                cout<<"\tEnter account number: ";
                cin>>accountNum;
                cout<<"\tEnter initial balance: ";
                cin>>balance;

                bank.addAccount(name, accountNum, balance);
                cout<<"\t\nAccount created successfully!"<<endl;
                break;
            }
            //show all account holders
            case 2:{
                bank.showAccounts();
                break;
            }
            //search for an account
            case 3:{
                int accountNum;
                cout<<"\tEnter account number: ";
                cin>>accountNum;

                bank.searchAccount(accountNum);
                break;
            }
            //deposit
            case 4:{
                int accountNum;
                double amount;
                cout<<"\tEnter account number: ";
                cin>>accountNum;

                BankAccount* account = bank.findAccount(accountNum);
                if (account != 0){
                    cout<<"\tEnter deposit amount: ";
                    cin>>amount;
                    account -> deposit(amount); //update account's balance
                    cout<<"\t"<<amount<<" deposited successfully!"<<endl;
                }
                else{
                    cout<<"Account not found."<<endl;
                }
                break;
            }
            //withdraw
            case 5:{
                int accountNum;
                double amount;
                cout<<"\tEnter account number: ";
                cin>>accountNum;

                BankAccount* account = bank.findAccount(accountNum);
                if (account != 0){
                    cout<<"\tEnter withdraw amount: ";
                    cin>>amount;
                    account -> withdraw(amount); //update account's balance
                    cout<<"\t"<<amount<<" withdrawn successfully!"<<endl;
                }
                else{
                    cout<<"Account not found."<<endl;
                }
                break;
            }
        }

    } while (currentChoice != 6);

    return 0;
}