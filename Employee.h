#include "Person.h"
using namespace std;
#pragma once

class Employee : public Person
{
protected:
  int id;
  double salary;

public:
  // Constructor

  Employee();
  Employee(string name, string password, string salary);
  Employee(int id, string name, string password, string salary);

  // Getters

  double getSalary();
  int getId();

  // Methods

  void display();

  void addClient(Client &client);
  Client* searchClient(int id);
  void listClient();
  void editClient(int id, string name, string password, double balance);
};
