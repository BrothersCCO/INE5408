#ifndef CASHIER_H_
#define CASHIER_H_

#include <string>

using std::string;

enum CashierProcessBehavior { FAST, MEDIUM, SLOW };

class Cashier {
	string name;
	double _salary;
	int _efficiency;

public:
	Cashier(const string&, double, int, int, bool);
	virtual ~Cashier();

	double salary() const;
};

#endif /* CASHIER_H_ */
