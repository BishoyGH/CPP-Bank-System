using namespace std;
#pragma once

class Person
{
protected:
  string name, password;

public:
  // Constructors

  Person();
  Person(string name, string password);

  // Setters

  void setName(string name);
  void setPassword(string password);

  // Getters

  string getName();
  string getPassword();

  // Methods

  // Pure Virtual Display Function to Convert Person To an Abstracted Class
  virtual void display() = 0;
};