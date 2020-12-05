/**
 * Order vector container. Inherits and implements QuickSorter.
 */
#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <fstream>
#include <vector>
#include "Order.h"
#include "QuickSorter.h"

using namespace std;

class OrderList : public QuickSorter
{
private:
  vector<Order> dataset;
  int length;

  // QuickSorter virtual methods
  bool compare(int, int) const;
  void swap(int, int);

public:
  OrderList();
  void add_from_file(string, int);
  void write_to_file(string) const;
  void push(const Order &);
  void print() const;
  int get_length() const;
};

#endif
