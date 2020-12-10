/**
 * Order class implementation.
 */

#include <string>
#include <iostream>
#include <iomanip>
#include "Order.h"

Order::Order(string c, string it, unsigned int id, int us, double tp)
{
  country = c;
  item_type = it;
  order_id = id;
  units_sold = us;
  total_profit = tp;
}

int Order::operator<(const Order &r) const
{
  if (country != r.country)
  {
    return country < r.country;
  }
  else
  {
    return total_profit < r.total_profit;
  }
}

std::ostream &operator<<(std::ostream &os, const Order &val)
{
  os << val.country << '\t';
  os << val.item_type << '\t';
  os << val.order_id << '\t';
  os << val.units_sold << '\t';
  os << std::fixed << std::setprecision(2) << val.total_profit << '\n';
  return os;
}
