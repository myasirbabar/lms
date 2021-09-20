#include <iostream>
#include <iomanip>
#include <string>
#include<stdlib.h>
#include <conio.h>

using namespace std;
void outputrecord(int** arr, int lab, int sta, string user)
{
    if(user == "admin"){
        cout << setw(15) << left << lab + 1 << left;
        for(int j = 0; j < sta; j++){
            if(arr[lab][j] == 0){
                cout << j+1 << ": " << setw(10) << left << "empty ";
            }
            else{
                cout << j + 1 << ": " << setw(10) << left << arr[lab][j];
            }
        }
    }

    else{
        cout << setw(15) << left << lab + 1 << left;
        for(int j = 0; j < sta; j++){
            if(arr[lab][j] == 0){
                cout << j+1 << ": " << setw(10) << left << "vacant";
            }
            else{
                cout << j + 1 << ": " << setw(10) << left << "In Use";
            }
        }
    }
}
void display(int ** arr, string user)
{
    int station = 5, lab = 0;
    outputrecord(arr, lab+0, station+0, user);
            cout << endl;
    outputrecord(arr, lab+1, station+1, user);
            cout << endl;
    outputrecord(arr, lab+2, station-1, user);
            cout << endl;
    outputrecord(arr, lab+3, station-2, user);
            cout << endl;

}
void welcome()
{
    cout << "\t\t\t\t\tLAB MANAGEMENT SYSTEM" << endl << endl;
}
int availability(int lab_no, int ** record)
{
     int com_no, temp = 0;
     if(lab_no == 1)
        com_no = 5;
else if(lab_no == 2)
        com_no = 6;
else if(lab_no == 3)
        com_no = 4;
else if(lab_no == 4)
        com_no = 3;

        for(int i = 0; i < com_no; i++){
            if(record[lab_no-1][i] !=0)
                temp++;
        }
    return temp;
}
void search_in(int t_labs, int ** record, int check_login)
{
    int com_no, flag = 0;
 for(int i = 0; i < t_labs; i++){
         if(i == 0)
          com_no = 5;
    else if(i == 1)
          com_no = 6;
    else if(i == 2)
          com_no = 4;
    else if(i == 3)
          com_no = 3;

    for(int j =0; j < com_no; j++){
        if(record[i][j] == check_login){
            cout << "User : " << check_login << " is on SYSTEM " << j + 1 << " in LAB " << i + 1 << endl;
                flag = 1;
        }
    }

    if(i == 3){
            if(flag == 0){
                cout << "No user exist with login : " << check_login << endl;
           }
        }
    }

}
string password()
{
            string admin_password; // password == "pucit"
            char temp_password[32];
            START:
                int i = 0;
                char a;

                for(i=0;;)
                {
                    a= getch();
                    if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
                    {
                        temp_password[i]=a;
                        ++i;
                        cout<<"*";
                    }
                    if(a=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        --i;
                    }
                    if(a=='\r')
                    {
                        temp_password[i]='\0';

                        break;
                    }
                }
            admin_password = temp_password;
            return admin_password;
}
int main()
{
                                                    welcome();

    int option, op_student, op_admin;
    int t_labs = 4;
    int ** record = new int*[t_labs];
    record[0] = new int[5];
    record[1] = new int[6];
    record[2] = new int[4];
    record[3] = new int[3];
                                    // INITIALIZE ARRAY TO ZERO
    for(int j = 0; j < 5; j++){
            record[0][j] = 0;
        }
    for(int j = 0; j < 6; j++){
            record[1][j] = 0;
        }
    for(int j = 0; j < 4; j++){
            record[2][j] = 0;
        }
    for(int j = 0; j < 3; j++){
            record[3][j] = 0;
        }

                                    //PROGRAM START
    MENU1:
    cout << "\t\tMAIN MENU\n";
    cout << "Select an option from menu below " << endl;
    cout << "\t1.STUDENT\n\t2.ADMINISTRATOR\n\t99.QUIT " << endl;
    cout << "Enter : ";
    cin >> option;
    cout << endl;

    while(option != 99){

                                // ENTER AS A STUDENT
        if(option == 1){
            system("cls");
            welcome();
            cout << "\t\tYou have entered as a student into the system " << endl;
            STU_MENU:
            cout << "Select an option from menu below " << endl;
            cout << "\t1.Log in\n\t2.Log out\n\t0.Back to main menu\n\t99.QUIT " << endl;
            cout << "Enter : ";
            cin >> op_student;
            cout << endl;

                // STUDENT LOG IN
            if(op_student == 1){
            LOGIN:
                cout << "\nCheck the availability and login into system\n" << endl;
                cout << setw(40) << left << "LAB NUMBER" << "COMPUTER STATIONS" << endl;
                display(record, "student");
                cout << endl;
                cout << endl;
                int login, lab_no, com_no;
                cout << "Enter: login ID  Lab no(1-4) Computer no : ";
                cin >> login >> lab_no >> com_no;

                while(lab_no < 1 || lab_no > 4){
                    cout << "Enter correct lab number (1-4): ";
                    cin >> lab_no;
                }

                if(lab_no == 1){
                INRANGE1:
                while(com_no < 1 || com_no > 5){
                    cout << "Enter correct computer number in (1-5): ";
                    cin >> com_no;
                }
                int temp = availability(lab_no, record);
                if(temp == 5){
                    cout << "No Seat Available In This Lab. Try Another. " << endl << endl;
                    goto MENU1;
                }
                while (record[lab_no-1][com_no-1] != 0){
                    cout << "Slot not available!! Select again : ";
                    cin >> com_no;
                    goto INRANGE1;
                }
                record[lab_no-1][com_no-1] = login;
                cout << "Logged in successfully !!" << endl;
            }

                if(lab_no == 2){
                INRANGE2:
                while(com_no < 1 || com_no > 6){
                    cout << "Enter correct computer number in (1-6): ";
                    cin >> com_no;
                }
                int temp = availability(lab_no, record);
                if(temp == 6){
                    cout << "No Seat Available In This Lab. Try Another. " << endl << endl;
                    goto MENU1;
                }
                while (record[lab_no-1][com_no-1] != 0){
                    cout << "Slot not available!! Select again : ";
                    cin >> com_no;
                    goto INRANGE2;
                }
                record[lab_no-1][com_no-1] = login;
                cout << "Logged in successfully !!" << endl;
                }

                if(lab_no == 3){
                INRANGE3:
                while(com_no < 1 || com_no > 4){
                    cout << "Enter correct computer number (1-4): ";
                    cin >> com_no;
                }
                int temp = availability(lab_no, record);
                if(temp == 4){
                    cout << "No Seat Available In This Lab. Try Another. " << endl << endl;
                    goto MENU1;
                }
                while (record[lab_no-1][com_no-1] != 0){
                    cout << "Slot not available!! Select again : ";
                    cin >> com_no;
                    goto INRANGE3;
                }
                record[lab_no-1][com_no-1] = login;
                cout << "Logged in successfully !!" << endl;

                }

                if(lab_no == 4){
                INRANGE4:
                while(com_no < 1 || com_no > 3){
                    cout << "Enter correct computer number in (1-3): ";
                    cin >> com_no;
                }
                int temp = availability(lab_no, record);
                if(temp == 3){
                    cout << "No Seat Available In This Lab. Try Another. " << endl << endl;
                    goto MENU1;
                }
                while (record[lab_no-1][com_no-1] != 0){
                    cout << "Slot not available!! Select again : ";
                    cin >> com_no;
                    goto INRANGE4;
                }
                record[lab_no-1][com_no-1] = login;
                cout << "Logged in successfully !!" << endl;
                }
                cout << endl;
                }

            // STUDENT LOG OUT
            else if(op_student == 2){
            LOGOUT:
                int lab_no, com_no;
                cout << "Enter: Lab no (1-4) Computer number : ";
                cin >> lab_no >> com_no;

                while(lab_no < 1 || lab_no > 4){
                    cout << "Enter correct lab number in(1-4): ";
                    cin >> lab_no;
                }

                if(lab_no == 1){
                    while(com_no < 1 || com_no > 5){
                    cout << "Enter correct computer number in (1-5): ";
                    cin >> com_no;
                }
            }

                if(lab_no == 2){
                    while(com_no < 1 || com_no > 6){
                        cout << "Enter correct computer number in (1-6): ";
                        cin >> com_no;
                    }
                }

                if(lab_no == 3){
                    while(com_no < 1 || com_no > 4){
                        cout << "Enter correct computer number in (1-4): ";
                        cin >> com_no;
                    }
                }

                if(lab_no == 4){
                    while(com_no < 1 || com_no > 3){
                        cout << "Enter correct computer number in (1-3): ";
                        cin >> com_no;
                }
                }

                if(record[lab_no-1][com_no-1] == 0){
                    cout << "Already No user exist on this system " << endl;
                }

                else{
                    record[lab_no-1][com_no-1] = 0;
                    cout << "Logged off successfully !!" << endl;
                }
                cout << endl;
                }

            // BACK TO MAIN MENU
            else if(op_student == 0){
                system("cls");
                welcome();
                goto MENU1;
            }

            // QUIT
            else if(op_student == 99){
                cout << endl;
                goto END;
            }

            // IF NOT FROM MENU
            else {
                cout << "In correct selection !!" << endl;
                goto STU_MENU;
            }

        }


                                // ENTER AS ADMINISTRATOR
        else if(option == 2){
                system("cls");
                welcome();
                // password == "pucit"
            cout << "Enter administration password : ";
            string admin_password = password();

            while (admin_password != "pucit"){
                cout << "\nIncorrect password! Try again : ";
                admin_password = password();
            }

            cout << endl << endl;
            cout << "\t\tYou have entered as a ADMIN into the system " << endl;
            ADMIN_MENU:
            cout << "Select an option from menu below " << endl;
            cout << "\t1.Display login information \n\t2.Search a login information\n\t3.Log in a Student\n\t4.Log out a student\n\t5.LOG OUT AS ADMIN \n\t0.Back to main menu\n\t99.QUIT " << endl;
            cout << "Enter : ";
            cin >> op_admin;
            cout << endl;

        while (op_admin != 5){

            // DISPLAY LOGIN INFORMATION
            if(op_admin == 1){
                  cout << setw(40) << left << "LAB NUMBER" << "COMPUTER STATIONS" << endl;
                  display(record, "admin");
                  cout << endl;
                  cout << endl;
                }

            // SEARCH A LOGIN
            else if(op_admin == 2){

                int check_login, flag;
                cout << "Enter login ID : ";
                cin >> check_login;
                cout << endl;
                search_in(t_labs, record, check_login);
                cout << endl;
            }

            // LOG IN A STUDENT
            else if(op_admin == 3){
                goto LOGIN;
            }

            // LOG OUT A STUDENT
            else if(op_admin == 4){
                    goto LOGOUT;
            }

            // BACK TO MAIN MENU
            else if(op_admin == 0){
                system("cls");
                welcome();
                goto MENU1;
            }

            // QUIT
            else if(op_admin == 99){
                cout << endl;
                goto END;
            }

            // IF NOT FROM MENU
            else {
                cout << "In correct selection !!" << endl;
                goto ADMIN_MENU;
            }

                  goto ADMIN_MENU;
                }
                    system("cls");
                    welcome();
            }


                                // OPTION NOT FROM MENU
        else{
            cout << "Select from the menu " << endl;
        }

                                // RE DISPLAY MENU
        goto MENU1;
    }
                               // DELETE RECORD
    for(int i = 0; i < t_labs; i++){
        delete [] record[i];
    }
    delete [] record;

    END:
    cout << "---------------" << endl;
    cout << " PROGRAM ENDED " << endl;
    cout << "---------------" << endl;
    cout << endl;
    cout << "Developed By Muhammad Yasir " << endl;
    return 0;
}
