/**
 * QuickSorter is an abstract class.
 * 
 * Classes that inherit QuickSorter will have the functionality of sorting
 * any dataset with quick sort algorithm.
 * 
 * @author Koray Kural
 */
#ifndef QUICKSORTER_H
#define QUICKSORTER_H

using namespace std;

class QuickSorter
{
public:
  virtual bool compare(int smaller_data_index, int bigger_data_index) const = 0;
  virtual void swap(int first_index, int second_index) = 0;
  virtual int get_length() const = 0;

  // Sort dataset with quick sort algorithm
  void sort()
  {
    quick_sort(0, get_length() - 1);
  }

private:
  /**
   * Recursive quick sort function. Bounds are inclusive.
   * 
   * @param lower_bound {int} Starting index of the segment to be sorted.
   * @param higher_bound {int} Ending index of the segment to be sorted.
   */
  void quick_sort(int lower_bound, int higher_bound)
  {
    // Return if leaf or an error occured
    if (lower_bound >= higher_bound)
    {
      return;
    }

    // First element is pivot
    int pivot_index = lower_bound;

    // Index of the first data with a value greater than the pivots
    int first_high_index = lower_bound + 1;
    while (first_high_index <= higher_bound && compare(first_high_index, pivot_index))
    {
      first_high_index++;
    }

    // Iterate remaining data
    for (int i = first_high_index + 1; i <= higher_bound; i++)
    {
      // If finds a value smaller than the pivots,
      if (compare(i, pivot_index))
      {
        // Replace it with the first higher value.
        swap(i, first_high_index);
        first_high_index++;
      }
    }

    // Set pivot to the correct position, latest smaller data
    int new_pivot_index = first_high_index - 1;
    if (pivot_index != new_pivot_index)
    {
      swap(pivot_index, new_pivot_index);
    }

    // QuickSort left side and right side of the pivot
    quick_sort(lower_bound, new_pivot_index - 1);
    quick_sort(new_pivot_index + 1, higher_bound);
  }
};

#endif
