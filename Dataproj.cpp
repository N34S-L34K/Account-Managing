#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Account {
    string Username;
    string Email;
    string Password;
    string Sex;
    string Age;
    string Birthday;
};

void Add_Account(vector<Account>& accounts) {
    Account account;
    cout << "ENTER E-MAIL ADDRESS: ";
    cin >> account.Email;
    cout << "CREATE PASSWORD: ";
    cin >> account.Password;
    cout << "ENTER USERNAME: ";
    cin >> account.Username;
    cout << "Sex: ";
    cin >> account.Sex;
    cout << "ENTER AGE: ";
    cin >> account.Age;
    cout << "ENTER BIRTHDAY: ";
    cin >> account.Birthday;

    accounts.push_back(account);
    cout << "ACCOUNT CREATED" << endl;
}

void Display_Accounts(const vector<Account>& accounts) {
    cout << "\nCURRENT ACCOUNTS:" << endl;
    for (size_t i = 0; i < accounts.size(); ++i) {
        cout << "\nAccount " << i + 1 << ":\n";
        cout << " Username: " << accounts[i].Username << endl;
        cout << " Email: " << accounts[i].Email << endl;
    }
}

void Delete_Account(vector<Account>& accounts) {
    Display_Accounts(accounts);
    int number_del;
    cout << "SELECT ACCOUNT NUMBER TO DELETE: ";
    cin >> number_del;
    number_del--;  

    if (number_del >= 0 && number_del < accounts.size()) {
        accounts.erase(accounts.begin() + number_del);
        cout << "ACCOUNT DELETED" << endl;
    } else {
        cout << "NO ACCOUNT TO DELETE" << endl;
    }
}

Account* Login(vector<Account>& accounts) {
    string email, password;
    cout << "ENTER E-MAIL ADDRESS: ";
    cin >> email;
    cout << "ENTER PASSWORD: ";
    cin >> password;

    for (auto& account : accounts) {
        if (account.Email == email && account.Password == password) {
            cout << "LOGGED IN SUCCESSFULLY" << endl;
            return &account;
        }
    }

    cout << "INVALID LOGIN" << endl;
    return nullptr;
}

void See_Information(const Account& account) {
    cout << "\nACCOUNT INFORMATION\n";
    cout << "USERNAME: " << account.Username << endl;
    cout << "EMAIL: " << account.Email << endl;
    cout << "SEX: " << account.Sex << endl;
    cout << "AGE: " << account.Age << endl;
    cout << "BIRTHDAY: " << account.Birthday << endl;
}

int main() {
    vector<Account> accounts;
    int option;

    while (true) {
        cout << "\nOPTIONS:\n";
        cout << "1. LOG IN\n";
        cout << "2. SIGN UP\n";
        cout << "3. DELETE ACCOUNT\n";
        cout << "4. DISPLAY ACCOUNTS\n";
        cout << "5. EXIT\n";
        cout << "SELECT OPTION: ";
        cin >> option;

        switch (option) {
            case 1: {
                Account* account = Login(accounts);
                if (account) {
                    See_Information(*account);
                }
                break;
            }
            case 2:
                Add_Account(accounts);
                break;
            case 3:
                Delete_Account(accounts);
                break;
            case 4:
                Display_Accounts(accounts);
                break;
            case 5:
                return 0;
            default:
                cout << "CHOOSE BETWEEN 1-5" << endl;
        }
    }

    return 0;
}
