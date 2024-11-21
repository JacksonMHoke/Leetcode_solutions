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