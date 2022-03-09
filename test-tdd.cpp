#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sort.h"

SCENARIO("sort an unsorted array")
{
    GIVEN("an unsorted array")
    {
        int arr[10] = {15, 20, 1, 3, 80, 5, 5, 14, 9, 2};
        int expectedArr[10] = {1, 2, 3, 5, 5, 9, 14, 15, 20, 80};

        WHEN("sort() is called with given array and size")
        {
            int(*actualArrPtr) = sort(arr, 10);
            THEN("a sorted array of the same is returned")
            {
                for (int i = 0; i < 10; i++)
                {
                    REQUIRE(actualArrPtr[i] == expectedArr[i]);
                }
            }
        }
    }
}
