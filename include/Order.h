/**
 * Order class.
 * 
 * Each row in the sales.txt is considered a Order object.
 */
#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>

using namespace std;

class Order
{
private:
  string country;
  string item_type;
  unsigned int order_id;
  int units_sold;
  double total_profit;

public:
  Order(string, string, unsigned int, int, double);
  Order(const Order &);
  int operator<(const Order &) const;
  friend std::ostream &operator<<(std::ostream &, const Order &);
};

#endif
