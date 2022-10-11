using namespace std;

#pragma once

class Validation
{
public:
  // Attributes
  static int minNameLength;
  static int maxNameLength;

  static int minPasswordLength;
  static int maxPasswordLength;

  static double minClientBalance;
  static double minEmployeeSalary;

  static char delimiter;

  // Validation Helpers

  static bool isValidLength(string str, int minLength, int maxLength);
  static bool containsDelimiter(string password);
  static void showDelimiterError(string valueName);

  // Name Validation

  static bool isValidNameContent(string name);
  static bool isValidName(string name);
  static string validateName(string name);

  // Password Validation

  static bool isValidPassword(string password);
  static string validatePassword(string password);

  // Amount Validation

  static bool isSufficientAmount(double amount, double minAmount);
  static bool isDigitAmount(string amount);
  static bool hasMultipleFloatingPoints(string amount);
  static double getValidAmount(string amount);
  static bool isValidAmount(string amount, double minAmount);
  static double validateAmount(string amount, double minAmount, string amountName);
};