#include <string>
#include <sstream>

class Date
{
  public:
    Date()
		: day(1), month(1), year(0)
	{
	}

	Date(const std::string &x)
		: Date()
	{
		std::stringstream(x) >> day >> month >> year;
	}

	Date(const int &x, const int &y, const int &z)
		: day(x), month(y), year(z)
	{
	}

	Date operator+ (const int& x) const;
	Date operator- (const int& x) const;
	Date operator= (const Date& x);
	Date operator+= (const int& x);
	Date operator-= (const int& x);
	Date operator++ ();
	Date operator++ (int);
	Date operator-- ();
	Date operator-- (int);
	bool operator== (const Date& x);
	bool operator!= (const Date& x);
	bool operator< (const Date& x);
	bool operator> (const Date& x);
	bool operator<= (const Date& x);
	bool operator>= (const Date& x);
	friend std::istream& operator>> (std::istream& stream, Date& x);
	friend std::ostream& operator<< (std::ostream& stream, const Date& x);
	friend void PrintString (const Date& x);

  private:
    int day, month, year;
	int amount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};