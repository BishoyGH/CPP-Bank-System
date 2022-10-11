#include "Validation.h"
using namespace std;
#pragma once
/*******************************************
 * Attributes
 *******************************************/

int Validation::minNameLength = 5;
int Validation::maxNameLength = 20;

int Validation::minPasswordLength = 8;
int Validation::maxPasswordLength = 20;

double Validation::minClientBalance = 1500;
double Validation::minEmployeeSalary = 5000;

char Validation::delimiter = '\t'; // Seperator Used Between Each Value in Files

/*******************************************
 * General Helpers
 *******************************************/

bool Validation::isValidLength(string str, int minLength, int maxLength)
{
  if (str.size() < minLength || str.size() > maxLength)
  {
    return false;
  }
  return true;
}

// Values Shouldn't Contain The Delimiter That We Use To Sperate Values In Files
bool Validation::containsDelimiter(string value)
{
  // Check Every Character In value
  for (int i = 0; i < value.size(); i++)
  {
    if (value[i] == delimiter)
      return true;
  }
  return false;
}

// The Error Message That User Will Get When Using Delimiter In Value
void Validation::showDelimiterError(string valueName)
{
  cout << valueName << " Shouldn't Contain ";
  // Custom Error Messages For Tabs & Spaces
  (delimiter == '\t') ? cout << "Any Tabs" : cout << delimiter;
  (delimiter == ' ') ? cout << "Any Spaces" : cout << delimiter;
  cout << endl;
}

/*******************************************
 * Name Validation
 *******************************************/

bool Validation::isValidNameContent(string name)
{
  // Check Every Character in name
  for (int i = 0; i < name.size(); i++)
  {
    // Allowed Content : Alphabetic Characters and Spaces
    if (!isalpha(name[i]) && (name[i] != ' ') && (name[i] == delimiter))
      return false;
  }
  return true;
}

// Check If Name Is written In Valid Format And Return True or False
bool Validation::isValidName(string name)
{
  if (!isValidNameContent(name) || !isValidLength(name, minNameLength, maxNameLength))
    return false;
  return true;
}

// Keep Checking For Valid Input and Return Correct Name Format
string Validation::validateName(string name)
{
  while (!isValidName(name))
  {
    getline(cin, name, '\n');
    // Show Error Message For Invalid Name Length
    if (!isValidLength(name, minNameLength, maxNameLength))
      cout << "Name length is Invalid" << endl;

    // Show Error Message For Invalid Character Content: Alphabetic Characters & Spaces
    if (!isValidNameContent(name))
      cout << "Name should be in alphabetics only" << endl;

    // Show Error Message For Names Contains Delimiter
    if (containsDelimiter(name))
      showDelimiterError("Name");

    // Retake User Input And Store it in name Variable
    if (!isValidName(name))
      cout << "Please Enter A Valid Name: ";
  }
  return name;
}

/*******************************************
 * Password Validation
 *******************************************/

// Check If Password Is written In Valid Format And Return True or False
bool Validation::isValidPassword(string password)
{
  if (containsDelimiter(password) || !isValidLength(password, minPasswordLength, maxPasswordLength))
    return false;
  return true;
}

// Keep Checking For Valid Input and Return Correct Password Format
string Validation::validatePassword(string password)
{
  while (!isValidPassword(password))
  {
    getline(cin, password, '\n');
    // Show Error Message If Password Contains Delimiter
    if (containsDelimiter(password))
      showDelimiterError("Password");
    // Show Error Message For Invalid Password Length
    if (!isValidLength(password, minPasswordLength, maxPasswordLength))
      cout << "Password Length Is Invalid" << endl;
    // Retake User Input And Store it in password Variable
    if (!isValidPassword(password))
      cout << "Please Enter A Valid Password: ";
  }
  return password;
}

/*******************************************
 * Amount Validation (Balance Or Salary)
 *******************************************/

// Check If Amount is Less Than Minimum Amount
bool Validation::isSufficientAmount(double amount, double minAmount)
{
  if (amount < minAmount)
    return false;
  return true;
}

// Check If Amount Contains Charachter other Than Numbers or Floating Point (.)
bool Validation::isDigitAmount(string amount)
{
  // If The Amount String Is Empty Return False
  if (amount.size() == 0)
    return false;
  // Check For Every Character of Password
  for (int i = 0; i < amount.size(); i++)
  {
    // Allowed Characters is Digits and Floating Points
    if (!isdigit(amount[i]) && (amount[i] != '.'))
      return false;
  }
  return true;
}

// Check For Multiple Floating Points in Amount
bool Validation::hasMultipleFloatingPoints(string amount)
{
  int count = 0; // Initial Number Of Floating Points In Amount
  for (int i = 0; i < amount.size(); i++)
  {
    if (amount[i] == '.')
      count++;
  }
  if (count > 1)
    return true;
  return false;
}

// Try To Convert Amount String To Double Number And Return 0 If String has Invalid Input
double Validation::getValidAmount(string amount)
{
  try
  {
    if (!isDigitAmount(amount))
    {
      throw exception();
    }
    else
    {
      // stod(): Built-in Function That Convert String To Double
      return stod(amount);
    }
  }
  catch (exception &e)
  {
    return 0;
  }
}

// Check If Amount Is written In Valid Format And Return True or False
bool Validation::isValidAmount(string amount, double minAmount)
{
  // Try To Convert Amount String To Double Number If Failed Return 0 and Compare it Against Minimum Amount
  if (!isSufficientAmount(getValidAmount(amount), minAmount) ||
      !isDigitAmount(amount) ||
      hasMultipleFloatingPoints(amount) ||
      amount.size() == 0)
    return false;
  return true;
}
// Keep Checking For Valid Input and Return Correct Amount Format as Double
double Validation::validateAmount(string amount, double minAmount, string amountName = "Amount")
{
  while (!isValidAmount(amount, minAmount))
  {
    if (isDigitAmount(amount))
    {
      // Error Message If Amount Isn't Sufficient
      if (!isSufficientAmount(stod(amount), minAmount))
      {
        cout << amountName << " Is Not Sufficient. Minimum " << amountName << " is " << minAmount << endl;
      }
      // Error Message For Multiple Floating Points
      else if (hasMultipleFloatingPoints(amount))
      {
        cout << "Please Use Only One Floating Point in " << amountName << "." << endl;
      }
    }
    // Error Message For Empty String
    else if (amount.size() == 0)
    {
      cout << amountName << " is Empty." << endl;
    }
    // Error Message For Non Numeric Characters
    else
    {
      cout << amountName << " Should Be Numeric." << endl;
    }
    cout << "Please Enter Valid " << amountName << ": ";
    cin >> amount;
  }
  return stod(amount);
}