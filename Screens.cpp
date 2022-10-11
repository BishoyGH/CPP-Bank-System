#include "Screens.h"
#pragma once

void Screens::clearScreen()
{
  // Clear Screen
  cout << "\x1b[2J";
  // Move Cursor To First Row And First Column
  cout << "\x1b[1;1H";
}

void Screens::bankname()
{
  cout << "  .g8\"\"\"bgd   MM\"\"\"Mq.   MM\"\"\"Mq.       MM\"\"\"Yp,       db        MN.     M    MF    MM" << endl;
  cout << ".dP\'     `M   MM   `MM.  MM   `MM.      MM    Yb      ;MM:       MMN.    M    MM   .M\'" << endl;
  cout << "dM\'       `   MM   ,M9   MM   ,M9       MM    dP     ,V^MM.      M YMb   M    MM .d\"" << endl;
  cout << "MM            MMmmdM9    MMmmdM9        MM\"\"\"bg.    ,M  `MM      M  `MN. M    MMMMM." << endl;
  cout << "MM.           MM         MM             MM    `Y    AbmmmqMA     M   `MM.M    MM  VMA" << endl;
  cout << "`Mb.     ,\'   MM         MM             MM    ,9   A\'     VML    M     YMM    MM   `MM." << endl;
  cout << "  `\"bmmmd\'    MML.       MML.           MMmmmd9  .AMA.   .AMMA.  ML.    YM    MML.   MMb." << endl;
}
void Screens::welcome()
{
  clearScreen();
  cout << "Welcome To: \n\n";
  bankname();
  Sleep(1000);
  loginScreen(loginAs());
}

void Screens::loginOptions()
{
  clearScreen();

  cout << "Please Choose a Number: " << endl;
  cout << "\t[1] Login As Client." << endl;
  cout << "\t[2] Login As Employee." << endl;
  cout << "\t[3] Login As Admin." << endl;
  cout << "\t[4] Exit Program." << endl;
}
int Screens::loginAs()
{
  loginOptions();
  int choice;
  cout << "Your Choice: ";
  cin >> choice;
  return choice;
}
void Screens::invalid(int c)
{
  cout << c << " Is Invalid Input. Please Try Again" << endl;
  Sleep(3000);
  loginScreen(loginAs());
}

void Screens::logout()
{
  clearScreen();

  cout << "Program Will Exit In 3 Seconds." << endl;
  Sleep(3000);
  system("exit");
}

void Screens::loginScreen(int c)
{
  int id;
  string password;
  if (c == 1 || c == 2 || c == 3)
  {
    cout << "Your Id: ";
    cin >> id;
    cout << "Your Password: ";
    cin >> password;
  }
  switch (c)
  {
  case 1:
  {
    ClientManger::clientOptions(ClientManger::login(id, password));
    break;
  }
  case 2:
  {
    EmployeeManager::employeeOptions(EmployeeManager::login(id, password));
    break;
  }
  case 3:
  {
    AdminManager::AdminOptions(AdminManager::login(id, password));
    break;
  }
  case 4:
  {
    logout();
    break;
  }
  default:
  {
    invalid(c);
  }
  }
}
void Screens::runApp()
{
  welcome();
}