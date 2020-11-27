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
T* partition(T *i, T *j, T* medianPointer, Compare comp)
{
    T* last = j;
    T* first = i;
    T medianValue = *medianPointer;
    T* pivot;

    while (i <= j) 
    {
        if (i == last || j == first)
        {
            break;
        }
        
        if(comp(medianValue, *i) || medianPointer == i)
        {
            if (comp(*j, medianValue) || medianPointer == j) 
            {
                swap(i,j);
                i++;
                j--;
            }
            else
            {
                if (j > first)
                {
                    j--;
                }
            }   
        }
        else
        {
            if (i < last)
            {
                i++;
            }
        }
    }

    return j;
}

template<typename T, typename Compare>
void quicksort_without_insertion_sort(T *first, T *last, Compare comp)
{
    T size = last - first;
    if (size > 1)
    {   
        // T firstElementValue = *(first);
        // T lastElementValue = *(last - 1);
        T middleElementPointer = (size - 1) / 2;
        // T middleElementValue = *(first + middleElementPointer);
        T* medianPointer = middleOfThree(first, first + middleElementPointer, last - 1);
        T medianValue = *(medianPointer);

        // cout << "First element = " << firstElementValue << endl;
        // cout << "Last element = " << lastElementValue << endl;
        // cout << "Middle element = " << middleElementValue << endl;
        // cout << "Median value = " << medianValue << endl;
        

        for (size_t i = 0; i < size; i++)
        {
            cout << *(first + i) << " ";    
        }
        cout << endl;

        // Обозначить i и j
        T* i = first;
        T* j = last - 1;

        cout << "i = " << *i << endl;
        cout << "j = " << *j << endl;

        // первая итерация сортировки

        T* pivot = partition(i, j, medianPointer, comp);
    
        cout << "After partition " << endl;
        cout << "i(index) = " << i - first << endl;
        cout << "j(index) = " << j - first<< endl;

        for (size_t i = 0; i < size; i++)
        {
            cout << *(first + i) << " ";    
        }
        cout << endl;

        quicksort_without_insertion_sort(first, pivot + 1, comp);
        quicksort_without_insertion_sort(pivot + 1, last, comp);
    }
}


int main()
{
    // int a[2] = {8,7};
    // quicksort(a, a + 2, [](int a, int b) { return a > b;});

    int a[8] = {2, 8, 4, 3, 1, 6, 9, 7};
    quicksort_without_insertion_sort(a, a + 8, [](int a, int b) { return a > b;});

    // int a[8] = {3, 7, 8, 2, 5, 6, 1, 9};
    // quicksort(a, a + 8, [](int a, int b) { return a > b;});

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