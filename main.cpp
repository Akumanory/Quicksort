#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

template<typename T>
void swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template<typename T>
bool comp(const T &a, const T &b);

template<typename T, typename Compare>
void quicksort(T *first, T *last, Compare comp)
{
    int size = last - first;

    cout << "Size = " << size << endl;

    // swap((first + 1), (first + 4));

#pragma region 
    // Bubble sort for test
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (comp(*(first + j), *(first + j + 1)))
            {
                swap((first + j), (first + j + 1));
            }
            
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << *(first + i) << endl;
    }
#pragma endregion
    
    // cout << *first << endl;
    // cout << *(++first) << endl;
    // cout << *last << endl;
}


int main()
{
    int a[10] = {1, 1, 1, 2, 2, 3, 3, 4, 4, 4};
    quicksort(a, a + 10, [](int a, int b) { return a < b; });

    // int a[] = { 1, 2, 4, 6, 7, 8 };
    // int found = binary_search(a, 6, 0, 5);

    // std::cout << (found ? "yes" : "no") << std::endl;

    
    // int temp = 1;
    // double *first = &a[0];
    // double *second = &a[1];
    // double *third = &a[2];

    // cout << sizeof(*first) << endl;
    // cout << sizeof(temp) << endl;
    
    // cout << first << endl;
    // cout << second << endl;
    // cout << third - first << endl;
}