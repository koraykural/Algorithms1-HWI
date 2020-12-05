/**
 * Reads N orders from sales.txt file.
 * Sorts them with quicksort algorithm.
 * Writes them back into sorted.txt file.
 */
#include <time.h>
#include <chrono>
#include "./include/OrderList.h"

using namespace std;

int main(int argc, char *argv[])
{
	// Check command line arguments
	if (argc != 2)
	{
		cerr << "N argument is not provided." << endl;
		return 1;
	}

	// Parse command line arguments
	int N = stoi(argv[1]);

	// Create order list from file
	OrderList orders;
	orders.add_from_file("sales.txt", N);

	// Start time
	auto start = chrono::high_resolution_clock::now();

	// Sort sales
	orders.sort();

	// End time
	auto stop = chrono::high_resolution_clock::now();

	// Calculate duration
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	// Print elapsed time in microseconds
	cout << N << " sales are sorted in " << duration.count() << " microseconds." << endl;

	orders.write_to_file("sorted.txt");

	return 0;
}
