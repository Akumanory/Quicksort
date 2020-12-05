#include "main.cpp"
#include <gtest/gtest.h>


TEST(TestMedianFinding, MiddleOfThree)
{
    int first = 10;
    int middle = 23;
    int last = 15;
    
    int* median = middleOfThree(&first, &middle, &last);

    ASSERT_EQ(*median, 15);
}


TEST(TestInsertionsort, ElementComparsionByDescending)
{
    int size = 1200;
    
    int first_array[size];
    int second_array[size];
    fill_array_with_random_values(first_array, first_array + size);
    copyArray(first_array, second_array, size);
    
    // cout << "Sort start" << endl;
    std::sort(first_array, first_array + size, [](int a, int b) { return a > b;});
    // cout << "Quicksort start" << endl;
    insertion_sort(second_array, second_array + size, [](int a, int b) { return a > b;});

    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(first_array[i], second_array[i]);    
    }
}

TEST(TestInsertionsort, ElementComparsionByAscending)
{
    int size = 1200;
    
    int first_array[size];
    int second_array[size];
    fill_array_with_random_values(first_array, first_array + size);
    copyArray(first_array, second_array, size);
    
    std::sort(first_array, first_array + size, [](int a, int b) { return a < b;});
    insertion_sort(second_array, second_array + size, [](int a, int b) { return a < b;});

    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(first_array[i], second_array[i]);    
    }
}

TEST(TestQuicksort, ElementComparsionByDescending)
{
    int size = 1200;
    
    int first_array[size];
    int second_array[size];
    fill_array_with_random_values(first_array, first_array + size);
    copyArray(first_array, second_array, size);
    
    // cout << "Sort start" << endl;
    std::sort(first_array, first_array + size, [](int a, int b) { return a > b;});
    // cout << "Quicksort start" << endl;
    quicksort_with_insertion_sort(second_array, second_array + size, [](int a, int b) { return a > b;});

    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(first_array[i], second_array[i]);    
    }
}


TEST(TestQuicksort, ElementComparsionByAscending)
{
    int size = 1200;
    
    int first_array[size];
    int second_array[size];
    fill_array_with_random_values(first_array, first_array + size);
    copyArray(first_array, second_array, size);
    
    std::sort(first_array, first_array + size, [](int a, int b) { return a < b;});
    quicksort_with_insertion_sort(second_array, second_array + size, [](int a, int b) { return a < b;});

    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(first_array[i], second_array[i]);    
    }
}

TEST(TestQuicksortWithoutInsertionsortUpgrade, ElementComparsionByAscending)
{
    int size = 121;
    
    int first_array[size];
    int second_array[size];
    fill_array_with_random_values(first_array, first_array + size);
    copyArray(first_array, second_array, size);
    
    std::sort(first_array, first_array + size, [](int a, int b) { return a < b;});
    quicksort_without_insertion_sort(second_array, second_array + size, [](int a, int b) { return a < b;});

    for (int i = 0; i < size; i++)
    {
        cout << *(first_array + i) << " ";
    }
    cout << endl;


    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(first_array[i], second_array[i]);    
    }
}

TEST(TestQuicksortWithoutInsertionsortUpgrade, ElementComparsionByDescending)
{
    int size = 2355;
    
    int first_array[size];
    int second_array[size];
    fill_array_with_random_values(first_array, first_array + size);
    copyArray(first_array, second_array, size);
    
    std::sort(first_array, first_array + size, [](int a, int b) { return a > b;});
    quicksort_without_insertion_sort(second_array, second_array + size, [](int a, int b) { return a > b;});

    for (int i = 0; i < size; i++)
    {
        cout << *(first_array + i) << " ";
    }
    cout << endl;


    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(first_array[i], second_array[i]);    
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}