#include "Person.h"

using namespace std;
#pragma once

class Client : public Person
{
private:
  int id;
  double balance;

public:
  // Constructor
  Client();
  Client(string name, string password, string balance);
  Client(int id, string name, string password, string balance);
  // Getters
  int getId();
  double getBalance();
  // Methods
  void deposit(double amount);
  void withdraw(double amount);
  void transferTo(double amount, Client &recipient);
  void checkBalance();
  void display();
};