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

template<typename T>
T* middleOfThree(T *a, T *b, T *c) 
{ 
    if (*a > *b)  
    { 
        if (*b > *c) 
            return b; 
        else if (*a > *c) 
            return c; 
        else
            return a; 
    } 
    else 
    { 
        if (*a > *c) 
            return a; 
        else if (*b > *c) 
            return c; 
        else
            return b; 
    } 
} 

template<typename T, typename Compare>
void quicksort(T *first, T *last, Compare comp)
{
    int size = last - first;
    if (size > 1)
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << *(first + i) << " ";    
        }
        cout << endl;

        //Find Median
        int firstElementValue = *(first);
        int lastElementValue = *(last - 1);
        int middleElementPointer = (size - 1) / 2;
        int middleElementValue = *(first + middleElementPointer);

        int* medianPointer = middleOfThree(first, first + middleElementPointer, last - 1);
        int medianValue = *(medianPointer);

        // cout << "Test " << first << endl;
        cout << "First element = " << firstElementValue << endl;
        cout << "Last element = " << lastElementValue << endl;
        cout << "Middle element = " << middleElementValue << endl;
        cout << "Median value = " << medianValue << endl;


        // Обозначить i и j
        int* i = first;
        int* j = last - 1;

        cout << "i = " << *i << endl;
        cout << "j = " << *j << endl;

        // первая итерация сортировки

        while (i <= j) 
        {
            if (medianPointer == i && medianPointer == j)
            {
                if (medianPointer == first)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
            else
            {
                if(comp(*medianPointer, *i) || medianPointer == i)
                {
                    if (comp(*j, *medianPointer) || medianPointer == j) 
                    {
                        swap(i,j);
                        i++;
                        j--;
                    }
                    else
                    {
                        j--;
                    }   
                }
                else
                {
                    i++;
                }
            }
        }
    
        cout << "After partition " << endl;
        cout << "i(index) = " << i - first << endl;
        cout << "j(index) = " << j - first<< endl;

        for (size_t i = 0; i < size; i++)
        {
            cout << *(first + i) << " ";    
        }
        cout << endl;


        quicksort(first, j + 1, comp);
        quicksort(j + 1, last, comp);

        // for (int i = 0; i < size; i++)
        // {
        //     cout << *(first + i) << " ";
        // }
    }
    
    

    

// #pragma region 
    // Bubble sort for test
    // for (int i = 0; i < size; i++)
    // {
        // for (int j = 0; j < size - i - 1; j++)
        // {
            // if (comp(*(first + j), *(first + j + 1)))
            // {
                // swap((first + j), (first + j + 1));
            // }
            // 
        // }
    // }
// 
    // for (int i = 0; i < size; i++)
    // {
        // cout << *(first + i) << endl;
    // }
// #pragma endregion
    
    // cout << *first << endl;
    // cout << *(++first) << endl;
    // cout << *last << endl;
}


int main()
{
    int a[8] = {2, 8, 4, 3, 1, 6, 9, 7};
    quicksort(a, a + 8, [](int a, int b) { return a > b;});

    // int a[5] = {4,8,6,9,7};
    // quicksort(a, a + 5, [](int a, int b) { return a < b; });

    

    for (auto &&i : a)
    {
        cout << i << " ";
    }
    

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