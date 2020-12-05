#include <iostream>
#include <cassert>
#include <vector>

#include "time.h"


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
            if (j == last)
            {
                j--;
            }
            
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
            cout << "there" << endl;
            if (i < last)
            {
                cout << "there 2" << endl;
                cout << "I: = " << *i << endl;
                cout << "I_index: = " << i - first << endl;
                i++;
            }
        }
    }

    return j;
}

template<typename T, typename Compare>
void insertion_sort(T *first, T *last, Compare comp)
{
    int size = last - first;

    for (int i = 1; i < size; i++)
    {
        T key = *(first + i);
        T* j = (first + (i - 1));

        while(comp(key, *j) && j - first >= 0)
        {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;

    }
}

template<typename T, typename Compare>
void quicksort_without_insertion_sort(T *first, T *last, Compare comp)
{
    while (first < last - 1)
    {
        int size = last - first;
        int middleElementPointer = (size - 1) / 2;
        T* medianPointer = middleOfThree(first, first + middleElementPointer, last - 1);
        T medianValue = *(medianPointer);

        T* i = first;
        T* j = last - 1;

        // cout << "i = " << *i << endl;
        // cout << "j = " << *j << endl;

        T* pivot = partition(i, j, medianPointer, comp);

        // cout << "After partition " << endl;
        // cout << "i(index) = " << i - first << endl;
        // cout << "j(index) = " << j - first<< endl;

        for (size_t i = 0; i < size; i++)
        {
            cout << *(first + i) << " ";    
        }
        cout << endl;

        if (pivot - first < last - 1 - pivot)
        {
            quicksort_without_insertion_sort(first, pivot + 1, comp);
            first = pivot + 1;
        }
        else
        {
            quicksort_without_insertion_sort(pivot + 1, last, comp);
            last = pivot + 1;
        }
    }
    

    // T size = last - first;
    // if (size > 1)
    // {   
    //     // T firstElementValue = *(first);
    //     // T lastElementValue = *(last - 1);
    //     // T middleElementValue = *(first + middleElementPointer);
        
    //     T middleElementPointer = (size - 1) / 2;
    //     T* medianPointer = middleOfThree(first, first + middleElementPointer, last - 1);
    //     T medianValue = *(medianPointer);

    //     // cout << "First element = " << firstElementValue << endl;
    //     // cout << "Last element = " << lastElementValue << endl;
    //     // cout << "Middle element = " << middleElementValue << endl;
    //     // cout << "Median value = " << medianValue << endl;
        
    //     for (size_t i = 0; i < size; i++)
    //     {
    //         cout << *(first + i) << " ";    
    //     }
    //     cout << endl;

    //     // Обозначить i и j
    //     T* i = first;
    //     T* j = last - 1;

    //     cout << "i = " << *i << endl;
    //     cout << "j = " << *j << endl;

    //     // первая итерация сортировки
    //     T* pivot = partition(i, j, medianPointer, comp);
    
    //     cout << "After partition " << endl;
    //     cout << "i(index) = " << i - first << endl;
    //     cout << "j(index) = " << j - first<< endl;

    //     for (size_t i = 0; i < size; i++)
    //     {
    //         cout << *(first + i) << " ";    
    //     }
    //     cout << endl;

    //     quicksort_without_insertion_sort(first, pivot + 1, comp);
    //     quicksort_without_insertion_sort(pivot + 1, last, comp);
    // }
}

template<typename T, typename Compare>
void quicksort_with_insertion_sort(T *first, T *last, Compare comp)
{
    while (first < last - 1)
    {
        int size = last - first;
        if (size < 56)
        {
            insertion_sort(first, last, comp);
            break;
        }else
        {
            int middleElementPointer = (size - 1) / 2;
            T* medianPointer = middleOfThree(first, first + middleElementPointer, last - 1);
            T medianValue = *(medianPointer);

            T* i = first;
            T* j = last - 1;

            cout << "i = " << *i << endl;
            cout << "j = " << *j << endl;
            cout << "median = " << *medianPointer << endl;
            cout << "median_index = " << medianPointer - first << endl;

            T* pivot = partition(i, j, medianPointer, comp);
    
            cout << "After partition " << endl;
            cout << "i(index) = " << i - first << endl;
            cout << "j(index) = " << j - first<< endl;
    
            for (size_t i = 0; i < size; i++)
            {
                cout << *(first + i) << " ";    
            }
            cout << endl;
    
            if (pivot - first < last - 1 - pivot)
            {
                quicksort_with_insertion_sort(first, pivot + 1, comp);
                first = pivot + 1;
            }
            else
            {
                quicksort_with_insertion_sort(pivot + 1, last, comp);
                last = pivot + 1;
            }
        }
    }
}


double time_check()
{
    struct timespec now;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID , &now);
    return now.tv_sec + now.tv_nsec / 1000000000.0;
}

struct TimeStruct
{
    double quick_sort_time;
    double insertion_sort_time;
    int size;
};

template<typename T, typename Compare>
TimeStruct test_time(T *first, T *last, Compare comp)
{
    int count = 100000;
    TimeStruct time;
    int size = last - first;
    for (size_t i = 0; i < count; i++)
    {
        
        T temp_array_quick_sort[size];
        for (size_t i = 0; i < size; i++)
        {
            temp_array_quick_sort[i] = *(first + i);
        }

        T temp_array_insertion_sort[size];
        for (size_t i = 0; i < size; i++)
        {
            temp_array_insertion_sort[i] = *(first + i);
        }

        double time1 = time_check();
        quicksort_without_insertion_sort(temp_array_quick_sort, temp_array_quick_sort + size, comp);
        double time2 = time_check();

        double time3 = time_check();
        insertion_sort(temp_array_insertion_sort, temp_array_insertion_sort + size, comp);
        double time4 = time_check();

        time.quick_sort_time += time2 - time1;
        time.insertion_sort_time += time4 - time3;
        
        // cout << "Quicksort" << endl;
        // for (auto &&i : temp_array_quick_sort)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        // cout << "Insertionsort" << endl;
        // for (auto &&i : temp_array_insertion_sort)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
    }
    // time.quick_sort_time = time.quick_sort_time / count;
    // time.insertion_sort_time = time.insertion_sort_time / count;

    return time;
}


void fill_array_with_random_values(int *first, int *last)
{
    for (int i = 0; i < last-first; i++)
    {
        *(first + i) = rand() % 1000;
    }
}

template<typename T>
void copyArray(T* copy_from_first_element, T* copy_to_first_element, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(copy_to_first_element + i) = *(copy_from_first_element + i);
    }
}

template<typename T, typename Compare>
std::vector<TimeStruct> test_time_with_random_array(int initial_size, int size_step, int iterations, Compare comp)
{
    for (int i = 0; i < 10; i++)
    {
        time_check();
    }
    
    std::vector<TimeStruct> time_structs;
    for (int i = 0; i < iterations; i++)
    {
        int size = initial_size + size_step * i;
        T array[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % 1000;
        }

        TimeStruct time = test_time(array, array + size, comp);
        time.size = size;
        time_structs.push_back(time);
    }
    
    return time_structs;
}

// int main()
// {
    // testing::InitGoogleTest()
    // int a[2] = {8,7};
    // quicksort_with_insertion_sort(a, a + 2, [](int a, int b) { return a > b;});
    // int size = 120;
    // int array[size];
    // fill_array_with_random_values(array, array + size);
    
    // for (auto &&i : array)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;


    // quicksort_with_insertion_sort(array, array + size, [](int a, int b) { return a > b;});

    // for (auto &&i : array)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < 55; i++)
    // {
        // cout << *(array + i) << " ";
    // }
    

    // for (auto &&i : a)
    // {
    //     cout << i << " ";
    // }

    // int a[8] = {2, 8, 4, 3, 1, 6, 9, 7};
    // quicksort_without_insertion_sort(a, a + 8, [](int a, int b) { return a < b;});
    // insertion_sort(a, a + 8, [](int a, int b) { return a < b;});

    // std::vector<TimeStruct> time = test_time_with_random_array<int>(104, 1, 15, [](int a, int b) { return a < b;});

    // for (auto &&i : time)
    // {
    //     cout << "Size of array: " << i.size << endl; 
    //     cout << "Quicksort time: " << i.quick_sort_time << endl;
    //     cout << "Insertionsort time: " << i.insertion_sort_time << endl;
    // }

    // for (size_t i = 0; i < 100; i++)
    // {
    //     for (int i = 0; i < 10; i++)
    //     {
    //         time_check();
    //     }

    //     double time1 = time_check();
        
    //     double time2 = time1;

    //     while (time1 == time2)
    //     {
    //         time2 = time_check();
    //     }
    //     cout << "Time: " << (time2 - time1) * 1000*1000 << endl;
    // }
    

    // int a[8] = {3, 7, 8, 2, 5, 6, 1, 9};
    // quicksort_without_insertion_sort(a, a + 8, [](int a, int b) { return a < b;});
    // insertion_sort(a, a + 8, [](int a, int b) { return a > b;});

    // int a[5] = {4,8,6,9,7};
    // quicksort(a, a + 5, [](int a, int b) { return a < b; });  
// }