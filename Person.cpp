#include "Person.h"
#pragma once

/*********************************************
 * Constructors
 *********************************************/

Person::Person()
{
  this->name = "DEFAULT NAME";
  this->password = "----------";
}

Person::Person(string name, string password)
{
  this->name = Validation::validateName(name);
  this->password = Validation::validatePassword(password);
}

/*********************************************
 * Setters
 *********************************************/

void Person::setName(string name)
{
  this->name = name;
}

void Person::setPassword(string password)
{
  this->password = password;
}

/*********************************************
 * Getters
 *********************************************/

string Person::getName()
{
  return this->name;
}

string Person::getPassword()
{
  return this->password;
}