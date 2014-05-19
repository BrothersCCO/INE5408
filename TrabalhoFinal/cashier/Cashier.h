#ifndef CASHIER_H_
#define CASHIER_H_

#include <string>

using std::string;

class Cashier {
	string name;
	double wage;

public:
	Cashier(const string&, const double);
	virtual ~Cashier();
};

#endif /* CASHIER_H_ */
