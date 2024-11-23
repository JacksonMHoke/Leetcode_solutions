/*
Restaraunt Class design

What can the system do
- Reserve tables
- Have customer sit down, order, pay, tip, and leave
- Manage employees
    - Assign hours to employee
    - Pay employees hourly rate + tips accrued
- Refund customers
- Menu
    - Order off menu
    - Calculate price of meal using menu

Restaraunt
- has tables
- has employees
- has menu
- check for open tables
- match customer with table
- put customer on waitlist
- queue of orders

Table
- has customers
- has seats
- has availability
- check availability at time
- submit order
- pay for order
- reserve time
- cancel reservation

Employee : Person
- Has paycheck
- Stores shifts worked
- Stores future shifts

Customer : Person
- id
- name

Menu
- list of items matched with prices
- calculate price of order

*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Restaurant {
public:

private:
    vector<Table> tables;
    vector<Employee> employees;
    Menu menu;
};

class Table {
public:

private:
    vector<Customer> customers;
    int seats;
    vector<pair<int, int>> availability;
    Order order;
};

class Person {
public:

private:
    string name;
};

class Customer : public Person {
public:

private:
    int rewardPoints;
};

class Employee : public Person {
public:

private:
    int pay;
    vector<vector<int>> shifts;
    vector<vector<int>> futureShifts;
};

class Menu {
public:

private:
    vector<MenuItem*> menuItems;
};

class MenuItem {
public:

private:
    int id;
    string name;
    int cost;

    bool hasDairy;
    bool hasNuts;
};

class Food : MenuItem {
public:

private:
    bool vegetarian;
    bool vegan;
};

class Drink : MenuItem {
public:

private:
    bool hasAlchohol;
};

class Order {
public:

private:
    vector<MenuItem*> itemsToCook;
    vector<MenuItem*> itemsReceived;
    int timeOfOrder;
};