#include "AdminManager.h"
using namespace std;
#pragma once

void AdminManager::chooseToBack(Admin *admin)
{
  cout << "\nChoose an Option" << endl;
  cout << "\t[0] Go Back." << endl;
  int c;
  while (true)
  {
    cout << "Your Choice: ";
    cin >> c;
    if (c == 0)
    {
      goBackToAdminMenu(admin);
    }
    break;
  }
}
void AdminManager::goBackToAdminMenu(Admin *admin)
{
  cout << "\nRedirected In 3 Seconds" << endl;
  Sleep(3000);
  AdminOptions(admin);
}
void AdminManager::rewriteAdmins(Admin *admin)
{
  FileManager fm;
  map<int, Admin> admins = fm.getAllAdmins();
  // Delete Old Admin Data
  admins.erase(admin->getId());
  // Insert New Admin Data
  admins.insert(pair<int, Admin>(admin->getId(), *admin));
  // Remove Data On File
  fm.removeAllAdmins();
  // Write New Data On File
  for (auto a : admins)
  {
    fm.addAdmin(a.second);
  }
}

void AdminManager::printAdminMenu()
{
  cout << "\t[01] Add New Client." << endl;
  cout << "\t[02] Search For Client" << endl;
  cout << "\t[03] List All Clients" << endl;
  cout << "\t[04] Edit Client Info" << endl;
  cout << "\t[05] Add New Employee." << endl;
  cout << "\t[06] Search For Employee" << endl;
  cout << "\t[07] List All Employees" << endl;
  cout << "\t[08] Edit Employee Info" << endl;
  cout << "\t[09] Display My Info" << endl;
  cout << "\t[10] Update Name" << endl;
  cout << "\t[11] Update Password" << endl;
  cout << "\t[12] Go Back" << endl;
  cout << "\t[13] Exit" << endl;
}

Admin *AdminManager::login(int id, string password)
{
  FileManager fm;
  auto admins = fm.getAllAdmins();
  try
  {
    if (admins[id].getPassword() != password)
      throw exception();
  }
  catch (exception &e)
  {
    cout << "Wrong Data Entered. Please Try Again." << endl;
    Screens::loginScreen(3);
  }
  return new Admin(admins[id].getId(), admins[id].getName(), admins[id].getPassword(), to_string(admins[id].getSalary()));
}

void AdminManager::AdminOptions(Admin *admin)
{
  Screens::clearScreen();
  cout << "Welcome " << admin->getName() << endl;
  cout << "Please Choose a Number: " << endl;
  printAdminMenu();
  int choice;
  cout << "Your Choice: ";
  cin >> choice;
  switch (choice)
  {
  // Add New Client
  case 1:
  {
    string name, password, balance;
    Screens::clearScreen();

    // Known Issue : Using getline causing Issues

    cout << "New Client Name: ";
    cin >> name;

    cout << "New Client Password: ";
    cin >> password;

    cout << "New Client Balance: ";
    cin >> balance;
    auto client = new Client(name, password, balance);

    admin->addClient(*client);

    cout << "Client Created Successfully" << endl;

    chooseToBack(admin);
    break;
  }
  // Search For Client
  case 2:
  {
    Screens::clearScreen();
    int id;
    cout << "Client Id: ";
    cin >> id;
    auto client = admin->searchClient(id);
    if (client->getId() == 0)
    {
      cout << "Client Is Not Found. Please Try Again";
      goBackToAdminMenu(admin);
      break;
    }
    client->display();
    chooseToBack(admin);
    break;
  }
  // List All Clients
  case 3:
  {
    Screens::clearScreen();
    admin->listClient();
    chooseToBack(admin);
    break;
  }
  // Edit Client Info
  case 4:
  {
    int id;

    cout << "Client Id: ";
    cin >> id;
    auto client = admin->searchClient(id);
    if (client->getId() == 0)
    {
      cout << "Client Is Not Found. Please Try Again";
      goBackToAdminMenu(admin);
      break;
    }
    Screens::clearScreen();

    cout << "Old Client Data: " << endl;
    cout << "------------------------" << endl;
    cout << "Name: " << client->getName() << endl;
    cout << "Password: " << client->getPassword() << endl;
    cout << "Balance: " << client->getBalance() << endl;
    cout << "\n\n";

    string name, password;
    double balance;

    // Known Issue : Using getline causing Issues

    cout << "New Name: ";
    cin >> name;
    cout << "New Password: ";
    cin >> password;
    cout << "New Balance: ";
    cin >> balance;

    admin->editClient(id, name, password, balance);

    cout << "\n\nClient Updated" << endl;

    chooseToBack(admin);
    break;
  }
  // Add New Employee
  case 5:
  {
    string name, password, salary;
    Screens::clearScreen();

    cout << "New Employee Name: ";
    cin >> name;

    cout << "New Employee Password: ";
    cin >> password;

    cout << "New Employee Balance: ";
    cin >> salary;
    auto employee = new Employee(name, password, salary);

    admin->addEmployee(*employee);

    cout << "Employee Created Successfully" << endl;

    chooseToBack(admin);
    break;
  }
  // Search For Employee
  case 6:
  {
    Screens::clearScreen();
    int id;
    cout << "Employee Id: ";
    cin >> id;

    auto employee = admin->searchEmployee(id);
    if (employee->getId() == 0)
    {
      cout << "Employee Is Not Found. Please Try Again";
      goBackToAdminMenu(admin);
      break;
    }
    employee->display();
    chooseToBack(admin);
    break;
  }
  // List All Employees
  case 7:
  {
    Screens::clearScreen();
    admin->listEmployee();
    chooseToBack(admin);
    break;
  }
  // Edit Employee Info
  case 8:
  {
    int id;

    cout << "Client Id: ";
    cin >> id;
    auto employee = admin->searchEmployee(id);
    if (employee->getId() == 0)
    {
      cout << "Employee Is Not Found. Please Try Again";
      goBackToAdminMenu(admin);
      break;
    }

    Screens::clearScreen();

    cout << "Old Employee Data: " << endl;
    cout << "------------------------" << endl;
    cout << "Name: " << employee->getName() << endl;
    cout << "Password: " << employee->getPassword() << endl;
    cout << "Salary: " << employee->getSalary() << endl;
    cout << "\n\n";

    string name, password;
    double salary;

    // Known Issue : Using getline causing Issues

    cout << "New Name: ";
    cin >> name;
    cout << "New Password: ";
    cin >> password;
    cout << "New Salary: ";
    cin >> salary;

    admin->editEmployee(id, name, password, salary);

    cout << "\n\n Employee Updated" << endl;

    chooseToBack(admin);
    break;
  }
  // Display My Info
  case 9:
  {
    Screens::clearScreen();
    admin->display();
    chooseToBack(admin);
    break;
  }
  // Update Name
  case 10:
  {
    string name;
    cout << "Enter New Name: ";
    getline(cin, name, '\n');
    admin->setName(Validation::validateName(name));
    cout << "Your Name Now Is: " << admin->getName() << endl;
    rewriteAdmins(admin);
    goBackToAdminMenu(admin);
    break;
  }
  // Update Password
  case 11:
  {
    string password;
    cout << "Enter New Password: ";
    getline(cin, password, '\n');
    password = Validation::validatePassword(password);
    admin->setPassword(password);
    cout << "Your Password Has Been Updated." << endl;
    rewriteAdmins(admin);
    goBackToAdminMenu(admin);
    break;
  }
  // Go Back
  case 12:
  {
    Screens::clearScreen();
    cout << "You Logged Out. Redirected In 3 Seconds";
    Sleep(3000);
    Screens::loginScreen(Screens::loginAs());
    break;
  }
  // Exit
  case 13:
  {
    Screens::logout();
    break;
  }
  default:
  {
    cout << choice << " is Invalid Input.";
  }
  }
}