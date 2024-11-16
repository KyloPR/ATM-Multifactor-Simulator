//ATM simulator created by Michael, Juan, Alej
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include <iostream>
#include <string>
using namespace std;

struct User { //Connects with the int for enteredUserID, enteredPIN, and enteredCode
    int userID, PIN, multifactorCode;
    string name;
};

int main() {
    int menuOption;
    char returnMenu;
    bool authenticated = false;

    //Users that have unique IDs, PINs, multifactor codes
    User users[] = {
        {920, 5671, 29221, "Michael"}, {67890, 987, 24680, "Juan"}, {12345, 5432, 13579, "Alej"}
    };

    int enteredUserID, enteredPIN, enteredCode;

    cout << "><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";

    cout << R"(
                                                                                 
                                                                                
                                                                                
                                @@@@@   @@@@@                                   
                                @@@@@   @@@@@                                   
                                @@@@@@@@@@@@@                                   
                             @@@@@@@@@@@@@@@@@@@@@                              
                        **@@@@@@@@@@@###@@@@@@@@@@@@*                           
                       @@@@@@@@@@@@@@   @@@@@   @@@@@@@                         
                    @@@@@@      @@@@@   @@@@@       @@@@                        
                    @@@@@@      @@@@@   @@@@@       @@@@                        
                    @@@@@@      @@@@@   @@@@@                                   
                     @@@@@@@@   @@@@@   @@@@@                                   
                        @@@@@@@@@@@@@   @@@@@                                   
                          @@@@@@@@@@@   @@@@@                                   
                               @@@@@@@@@@@@@@                                   
                                @@@@@@@@@@@@@                                   
                                @@@@@@@@@@@@@@@                                 
                                @@@@@   @@@@@@@@@@                              
                                @@@@@   @@@@@@@@@@@@@                           
                                @@@@@   @@@@@   @@@@@@@@                        
                                @@@@@   @@@@@     @@@@@@                        
                                @@@@@   @@@@@       @@@@@@                      
                    &           @@@@@   @@@@@       @@@@@@                      
                    @@@@        @@@@@   @@@@@     @@@@@@                        
                    @@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@                         
                     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                           
                            @@@@@@@@@@@@@@@@@@@                                 
                                @@@@@@@@@@@@@                                   
                                @@@@@   @@@@@                                   
                                #%%%%   #%%%%           
    )" << endl;

    cout << "><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";

    cout << "Welcome to the ATM \n";
    cout << "Enter your User ID: ";
    cin >> enteredUserID;

    for (const auto& user : users) {
        if (enteredUserID == user.userID) {
            cout << "Enter your PIN: ";
            cin >> enteredPIN;

            if (enteredPIN == user.PIN) {
                cout << "Enter your multifactor code: ";
                cin >> enteredCode;

                if (enteredCode == user.multifactorCode) {
                    authenticated = true;
                    cout << "Welcome, " << user.name << "!\n";

                    cout << "********************************************\n";
                    break;
                }
                else {
                    cout << "Invalid multifactor code\n";
                }
            }
            else {
                cout << "Invalid PIN\n";
            }
            break;
        }
    }

    if (!authenticated) {
        cout << "Invalid User ID \n";
    }

    // Access menu if authenticated
    while (authenticated) {
        cout << "Insert one of the options below\n";
        cout << "1- Withdraw money\n";
        cout << "2- Deposit money\n";
        cout << "3- Exit\n";
        cin >> menuOption;

        switch (menuOption) {
        case 1:
            cout << "Withdrawal process initiated...\n";
            break;

        case 2:
            cout << "Deposit process initiated...\n";
            break;

        case 3:
            cout << "Thank you for using this software.\n";
            authenticated = false;
            break;

        default:
            cout << "Invalid choice. Please choose: 1, 2, or 3\n";
            continue;
        }

        if (menuOption != 3) {
            cout << "Would you like to return to the menu? (Y/N): ";
            cin >> returnMenu;
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
            if (returnMenu == 'N' || returnMenu == 'n') {
                cout << "Thank you for using this software.\n";
                break;
            }
        }
    }
    return 0;
}