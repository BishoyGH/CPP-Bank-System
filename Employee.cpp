#include "Person.h"
#include "Employee.h"
#include "FilesHelper.h"
#include "FileManager.h"
using namespace std;
#pragma once
/******************************************************
 * Constructors
 *******************************************************/

// Default Constructor - Not Required
Employee::Employee()
{
  this->id = FilesHelper::getLast(FilesHelper::lastEmployeeIdFile);
  this->salary = Validation::minEmployeeSalary;
}
// Create New Employee
Employee::Employee(string name, string password, string salary) : Person(name, password)
{
  this->id = FilesHelper::getLast(FilesHelper::lastEmployeeIdFile);
  this->salary = Validation::validateAmount(salary, Validation::minEmployeeSalary, "Salary");
}
// Create New Employee Using Line From a File
Employee::Employee(int id, string name, string password, string salary) : Person(name, password)
{
  this->id = id;
  this->salary = stod(salary);
}

/******************************************************
 * Getters
 *******************************************************/

double Employee::getSalary()
{
  return this->salary;
}
int Employee::getId()
{
  return this->id;
}

/******************************************************
 * Methods
 *******************************************************/

// Display All Info

void Employee::display()
{
  cout << this->getName() << " Info" << endl
       << "----------------\n"
       << "Id: \t\t" << this->id << endl
       << "Name: \t\t" << this->name << endl
       << "Salary: \t" << this->salary << endl
       << "========================\n";
}

// Add New Client

void Employee::addClient(Client &client)
{
  FileManager fm;
  fm.addClient(client);
}

// Search All Clients

Client *Employee::searchClient(int id)
{
  FileManager fm;
  map<int, Client> clients = fm.getAllClients();
  Client client = clients[id];
  if (client.getName() == "EMPTY ACCOUNT")
  {
    cout << "Client Not Found!" << endl;
    return new Client(0, client.getName(), client.getPassword(), to_string(0));
  }
  // We Can't Return client Because It's a Local Variable;
  return new Client(client.getId(), client.getName(), client.getPassword(), to_string(client.getBalance()));
}

// List All Clients

void Employee::listClient()
{
  FilesHelper::getClients();
}

// Edit Client

void Employee::editClient(int id, string name, string password, double balance)
{
  Client *c = searchClient(id);
  if (c->getName() == "EMPTY ACCOUNT")
  {
    cout << "Client Is Not Found. Please Try Again." << endl;
    // If The Client Account Not Fount Exit
    return;
  }
  else
  {
    c->setName(Validation::validateName(name));
    c->setPassword(Validation::validatePassword(password));
    if (balance >= c->getBalance())
    {
      // If Old Balance >= New Balance Deposit(new Balance - Old Balance)
      c->deposit(balance - c->getBalance());
    }
    else if (balance < c->getBalance())
    {
      // If new Balance < Old Balance Withdraw(Old Balance - New Balance)
      c->withdraw(c->getBalance() - balance);
    }
    else if (balance < 0)
    {
      // If New Balance Is Negative
      cout << "Balance Can't Be Less Than Zero. Please Try Again!" << endl;
    }
  }
  FileManager fm;
  map<int, Client> clients = fm.getAllClients();
  clients.erase(id);
  clients.insert(pair<int, Client>(id, *c));
  fm.removeAllClients();
  for (auto client : clients)
  {
    fm.addClient(client.second);
  }
}