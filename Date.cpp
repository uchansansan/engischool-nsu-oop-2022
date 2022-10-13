#include <iostream>
#include "Date.h"

bool isLeap (int year)
{
  return year % 400 == 0 || (year % 400 != 0 && year % 100 != 0 && year % 4 ==0);
}

Date Date::operator+ (const int& x) const
{
  int days = this->day + x, months = this->month, years = this->year;
  
  for (int i = this->month - 1; 
      days > (isLeap(years)?this->amount[i] + 1: 
      this->amount[i]); i = (i + 1) % 12){
    if (i == 11)
    {
      years += 1;
    }
    days -= (isLeap(years)?this->amount[i] + 1: this->amount[i]);
    months = months % 12 + 1;
  }

  return { days, months, years };
}

Date Date:: operator- (const int& x) const
{
  int days = this->day - x, months = this->month, years = this->year;
  
  for (int i = (12 + this->month - 2) % 12; days <= 0; i = (12 + i - 1) % 12)
  {
    if (i + 1 == 12)
    {
      years -= 1;
    }
    days += (isLeap(years)?this->amount[i] + 1: this->amount[i]);
    months = (12 + months) % 12 - 1;
  }

  return { days, months, years };
}

Date Date:: operator= (const Date& x)
{
  this->day = x.day;
  this->month = x.month;
  this->year = x.year;

  return *this;
}

Date Date:: operator+= (const int& x) 
{
  *this = *this + x;

  return *this;
}

Date Date:: operator-= (const int& x)
{
  *this = *this - x;

  return *this;
}

Date Date:: operator++ ()
{
  *this += 1;

  return *this;
}

Date Date:: operator++ (int)
{
  Date temp = *this;

  ++*this;

  return temp;
}

Date Date:: operator-- ()
{
  *this -= 1;

  return *this;
}

Date Date:: operator-- (int)
{
  Date temp = *this;

  --*this;

  return temp;
}

bool Date:: operator== (const Date& x)
{
  return this->day == x.day && this->month == x.month && this->year == x.year;
}

bool Date:: operator!= (const Date& x)
{
  return !(*this == x);
}

bool Date:: operator< (const Date& x)
{
  return (this->year < x.year) || 
        (this->month < x.month && this->year == x.year) ||
        (this->day < x.day && this->month == x.month && this->year == x.year);
}

bool Date:: operator> (const Date& x)
{
  return *this != x && !(*this < x);
}

bool Date:: operator<= (const Date& x)
{
  return !(*this > x);
}

bool Date:: operator>= (const Date& x)
{
  return !(*this < x);
}

std::istream& operator>> (std::istream& stream, Date& x)
{
  stream >> x.day >> x.month >> x.year;

  return stream;
}

std::ostream& operator<< (std::ostream& stream, const Date& x)
{
  stream << x.day << ' ' << x.month << ' ' << x.year;
  
  return stream;
}

void PrintString (const Date& x)
{
  std::string stringMonth[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "dec"};

  std::cout << x.day << ' ' << stringMonth[x.month - 1] << ' ' << x.year;
}