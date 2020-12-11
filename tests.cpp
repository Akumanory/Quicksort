#include "main.cpp"
#include <gtest/gtest.h>

#include "test_classes.h"


TEST(TestMedianFinding, MiddleOfThree)
{
    int first = 10;
    int middle = 23;
    int last = 15;
    
    int* median = middleOfThree(&first, &middle, &last, [](int a, int b) { return a > b;});

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
    int size = 8;
    
    int first_array[size] = {2, 8, 4, 3, 1, 6, 9, 7};;
    int second_array[size]= {2, 8, 4, 3, 1, 6, 9, 7};;
    // fill_array_with_random_values(first_array, first_array + size);
    // copyArray(first_array, second_array, size);
    
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
    int size = 8;
    
    int first_array[size] = {2, 8, 4, 3, 1, 6, 9, 7};
    int second_array[size] = {2, 8, 4, 3, 1, 6, 9, 7};
    // fill_array_with_random_values(first_array, first_array + size);
    // copyArray(first_array, second_array, size);
    
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

TEST(TestQuicksortWithoutInsertionsortUpgradeWithClasses, ElementComparsionByDescending)
{
    int size = 6;

    Test_Class first_array[size] {{1, 12}, {1, 18}, {32, 8}, {45, 45}, {11, 37}, {8, 8}};
    
    Test_Class second_array[size] {{1, 12}, {1, 18}, {32, 8}, {45, 45}, {11, 37}, {8, 8}};
    // fill_array_with_random_values(first_array, first_array + size);
    // copyArray(first_array, second_array, size);
    
    std::sort(first_array, first_array + size, 
            [](Test_Class a, Test_Class b) { return a.test_int2 > b.test_int2;});

    quicksort_without_insertion_sort(second_array, second_array + size, 
                                    [](Test_Class a, Test_Class b) { return a.test_int2 > b.test_int2;});

    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(first_array[i].test_int2, second_array[i].test_int2);    
    }
}

TEST(TestQuicksortWithoutInsertionsortUpgradeWithClasses, ElementComparsionByAscendign)
{
    int size = 6;

    Test_Class first_array[size] {{1, 12}, {1, 18}, {32, 8}, {45, 45}, {11, 37}, {8, 8}};
    
    Test_Class second_array[size] {{1, 12}, {1, 18}, {32, 8}, {45, 45}, {11, 37}, {8, 8}};
    // fill_array_with_random_values(first_array, first_array + size);
    // copyArray(first_array, second_array, size);
    
    std::sort(first_array, first_array + size, 
            [](Test_Class a, Test_Class b) { return a.test_int2 < b.test_int2;});

    quicksort_without_insertion_sort(second_array, second_array + size, 
                                    [](Test_Class a, Test_Class b) { return a.test_int2 < b.test_int2;});

    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(first_array[i].test_int2, second_array[i].test_int2);    
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}