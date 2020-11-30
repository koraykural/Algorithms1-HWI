/**
 * 
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
  bool compare(int, int);
  void swap(int, int);

public:
  OrderList();
  void add_from_file(string, int);
  void push(const Order &);
  void print();
  int get_length();
};

#endif
