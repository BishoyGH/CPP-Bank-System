#include "Person.h"
#include "Client.h"
#include "Validation.h"
#include "FilesHelper.h"
using namespace std;
#pragma once
/******************************************************
 * Constructors
 *******************************************************/

// Create Default Client - Not Required
Client::Client()
{
  this->id = FilesHelper::getLast(FilesHelper::lastClientIdFile);
  this->balance = Validation::minClientBalance;
}

// Create New Client
Client::Client(string name, string password, string balance) : Person(name, password)
{
  this->id = FilesHelper::getLast(FilesHelper::lastClientIdFile);
  this->balance = Validation::validateAmount(balance, Validation::minClientBalance, "Balance");
}

// Create New CLient Using Line From a File
Client::Client(int id, string name, string password, string balance) : Person(name, password)
{
  this->id = id;
  this->balance = stod(balance);
}

/******************************************************
 * Getters
 *******************************************************/

int Client::getId()
{
  return this->id;
}
double Client::getBalance()
{
  return this->balance;
}

/******************************************************
 * Methods
 *******************************************************/

// Deposit

void Client::deposit(double amount)
{
  this->balance += amount;
}

// Withdraw

void Client::withdraw(double amount)
{
  if (amount < this->balance)
  {
    this->balance -= amount;
  }
  else
  {
    cout << "Your Balance Is Not Enough To Withdraw This Amount!" << endl;
  }
}

// Transfer To

void Client::transferTo(double amount, Client &recipient)
{
  if (amount < this->balance)
  {
    this->balance -= amount;
    recipient.balance += amount;
  }
  else
  {
    cout << "Your Balance Is Not Enough To Transfer This Amount!" << endl;
  }
}

// Check Balance

void Client::checkBalance()
{
  cout << "Your Balance Currently is: " << this->balance << endl;
}

// Display All Info

void Client::display()
{
  cout << this->getName() << " Data: " << endl
       << "----------------\n"
       << "Id: \t\t" << this->id << endl
       << "Name: \t\t" << this->name << endl
       << "Balance: \t" << this->balance << endl
       << "========================\n";
}