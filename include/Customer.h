#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include "Dish.h"

class Customer {
public:
    Customer(std::string c_name, int c_id);

    virtual std::vector<int> order(const std::vector<Dish> &menu) = 0;

    virtual std::string toString() const = 0;

    std::string getName() const;

    int getId() const;

    virtual Customer *clone() const = 0;

    virtual ~Customer() = 0;

    virtual std::string getType() const = 0;

private:
    const std::string name;
    const int id;

};


class VegetarianCustomer : public Customer {
public:
    VegetarianCustomer(std::string name, int id);

    std::vector<int> order(const std::vector<Dish> &menu);

    std::string toString() const;

    VegetarianCustomer *clone() const;

    ~VegetarianCustomer() override;

    std::string getType() const;

private:
};


class CheapCustomer : public Customer {
public:
    CheapCustomer(std::string name, int id);

    std::vector<int> order(const std::vector<Dish> &menu);

    std::string toString() const;

    CheapCustomer *clone() const;

    std::string getType() const;

    ~CheapCustomer() override;

private:
    bool isOrdered;
};


class SpicyCustomer : public Customer {
public:
    SpicyCustomer(std::string name, int id);

    std::vector<int> order(const std::vector<Dish> &menu);

    std::string toString() const;

    SpicyCustomer *clone() const;

    std::string getType() const;

    ~SpicyCustomer() override;

private:
    bool isSpicy;
};


class AlchoholicCustomer : public Customer {
public:
    AlchoholicCustomer(std::string name, int id);

    std::vector<int> order(const std::vector<Dish> &menu);

    std::string toString() const;

    AlchoholicCustomer *clone() const;

    ~AlchoholicCustomer() override;

    std::string getType() const;

private:
    int lastPaidPrice;
    int lastAlcID;
};


#endif