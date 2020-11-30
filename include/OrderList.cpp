/**
 * OrderList class implementation.
 */

#include <iostream>
#include "OrderList.h"
#include "Order.h"

using namespace std;

OrderList::OrderList()
{
  length = 0;
}

void OrderList::push(const Order &val)
{
  dataset.push_back(val);
  length++;
}

void OrderList::print()
{
  for (int i = 0; i < length; i++)
  {
    cout << dataset[i] << endl;
  }
}

bool OrderList::compare(int smaller_data_index, int bigger_data_index)
{
  return dataset[smaller_data_index] < dataset[bigger_data_index];
}

void OrderList::swap(int first_index, int second_index)
{
  Order temp = dataset[first_index];
  dataset[first_index] = dataset[second_index];
  dataset[second_index] = temp;
}

int OrderList::get_length()
{
  return length;
}

void OrderList::add_from_file(string filename, int N)
{
  ifstream file;
  file.open("sales.txt");

  if (!file)
  {
    cerr << "File cannot be opened!";
    exit(1);
  }

  string line;

  // Read header line into dummy variable
  getline(file, line);

  for (int i = 0; i < N; i++)
  {
    // Read country
    getline(file, line, '\t');
    string country = line;

    // Read item type
    getline(file, line, '\t');
    string item_type = line;

    // Read order id
    getline(file, line, '\t');
    unsigned int order_id = stoi(line);

    // Read units sold
    file >> line;
    int units_sold = stoi(line);

    // Read total profit
    file >> line;
    int total_profit = stoi(line);

    // Create order and append to dataset
    Order order = Order(country, item_type, order_id, units_sold, total_profit);
    push(order);

    // Read newline to dummy variable
    getline(file, line, '\n');
  }
}