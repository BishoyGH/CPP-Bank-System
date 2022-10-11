#include "EmployeeManager.h"
using namespace std;
#pragma once

void EmployeeManager::chooseToBack(Employee *employee)
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
      goBackToEmployeeMenu(employee);
    }
    break;
  }
}

void EmployeeManager::goBackToEmployeeMenu(Employee *employee)
{
  cout << "\nRedirected In 3 Seconds" << endl;
  Sleep(3000);
  employeeOptions(employee);
}

void EmployeeManager::rewriteEmployees(Employee *employee)
{
  FileManager fm;
  map<int, Employee> employees = fm.getAllEmployees();
  // Delete Old Employee Data
  employees.erase(employee->getId());
  // Insert New Employee Data
  employees.insert(pair<int, Employee>(employee->getId(), *employee));
  // Remove Data On File
  fm.removeAllEmployees();
  // Write New Data On File
  for (auto e : employees)
  {
    fm.addEmployee(e.second);
  }
}

void EmployeeManager::printEmployeeMenu()
{
  cout << "\t[1] Add New Client." << endl;
  cout << "\t[2] Search For Client" << endl;
  cout << "\t[3] List All Clients" << endl;
  cout << "\t[4] Edit Client Info" << endl;
  cout << "\t[5] Display My Info" << endl;
  cout << "\t[6] Update Name" << endl;
  cout << "\t[7] Update Password" << endl;
  cout << "\t[8] Go Back" << endl;
  cout << "\t[9] Exit" << endl;
}

Employee *EmployeeManager::login(int id, string password)
{
  FileManager fm;
  auto employees = fm.getAllEmployees();
  try
  {
    if (employees[id].getPassword() != password)
      throw exception();
  }
  catch (exception &e)
  {
    cout << "Wrong Data Entered. Please Try Again." << endl;
    Screens::loginScreen(2);
  }
  return new Employee(employees[id].getId(), employees[id].getName(), employees[id].getPassword(), to_string(employees[id].getSalary()));
}

void EmployeeManager::employeeOptions(Employee *employee)
{
  Screens::clearScreen();
  cout << "Welcome " << employee->getName() << endl;
  cout << "Please Choose a Number: " << endl;
  printEmployeeMenu();
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

    employee->addClient(*client);

    cout << "Client Created Successfully" << endl;

    chooseToBack(employee);

    break;
  }
  // Search For Client
  case 2:
  {
    Screens::clearScreen();
    int id;
    cout << "Client Id: ";
    cin >> id;
    auto client = employee->searchClient(id);
    if (client->getId() == 0)
    {
      cout << "Client Is Not Found. Please Try Again";
      goBackToEmployeeMenu(employee);
      break;
    }
    client->display();
    chooseToBack(employee);
    break;
  }
  // List All Clients
  case 3:
  {
    Screens::clearScreen();
    employee->listClient();
    chooseToBack(employee);
    break;
  }
  // Edit Client Info
  case 4:
  {
    int id;

    cout << "Client Id: ";
    cin >> id;
    auto client = employee->searchClient(id);
    if (client->getId() == 0)
    {
      cout << "Client Is Not Found. Please Try Again";
      goBackToEmployeeMenu(employee);
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

    employee->editClient(id, name, password, balance);

    cout << "\n\nClient Updated" << endl;

    chooseToBack(employee);
    break;
  }
  // Display Info
  case 5:
  {
    Screens::clearScreen();
    employee->display();
    chooseToBack(employee);
    break;
  }
  // Update Name
  case 6:
  {
    string name;
    cout << "Enter New Name: ";
    getline(cin, name, '\n');
    employee->setName(Validation::validateName(name));
    cout << "Your Name Now Is: " << employee->getName() << endl;
    rewriteEmployees(employee);
    goBackToEmployeeMenu(employee);
    break;
  }
  // Update Password
  case 7:
  {
    string password;
    cout << "Enter New Password: ";
    getline(cin, password, '\n');
    password = Validation::validatePassword(password);
    employee->setPassword(password);
    cout << "Your Password Has Been Updated." << endl;
    rewriteEmployees(employee);
    goBackToEmployeeMenu(employee);
    break;
  }
  //  Go Back
  case 8:
  {
    Screens::clearScreen();
    cout << "You Logged Out. Redirected In 3 Seconds";
    Sleep(3000);
    Screens::loginScreen(Screens::loginAs());
    break;
  }
  // Exit
  case 9:
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