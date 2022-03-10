#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sort.h"
#include "ranges.h"

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

SCENARIO("get reading ranges and count form input array")
{
    GIVEN("an array with set of periodic current samples from a charging session is provided")
    {
        int arr[7] = {3, 3, 5, 4, 10, 11, 12};
        ReadingRange expectedReadingRange[2] = {{3, 5, 4}, {10, 12, 3}};
        ReadingRangeList expectedReadingRangeList = {expectedReadingRange, 2};

        WHEN("getReadingRangeList() is called with input array and size")
        {
            ReadingRangeList actualReadingRangeList = getReadingRangeList(arr, 7);
            THEN("list with reading ranges and number of readings in each range is returned")
            {
                REQUIRE(actualReadingRangeList.totalReadingRanges == expectedReadingRangeList.totalReadingRanges);

                int isEqual = 1;
                ReadingRange *actualReadingRange = actualReadingRangeList.readingRanges;
                for (int i = 0; i < expectedReadingRangeList.totalReadingRanges; i++)
                {
                    REQUIRE(actualReadingRange[i].rangeStart == expectedReadingRange[i].rangeStart);
                    REQUIRE(actualReadingRange[i].rangeEnd == expectedReadingRange[i].rangeEnd);
                    REQUIRE(actualReadingRange[i].numberOfReadings == expectedReadingRange[i].numberOfReadings);
                }
            }
        }
    }
}

TEST_CASE("test printReadingRangeList() does not throw error")
{
    int arr[7] = {3, 3, 5, 4, 10, 11, 12};
    ReadingRange readingRange[2] = {{3, 5, 4}, {10, 12, 3}};
    ReadingRangeList readingRangeList = {readingRange, 2};
    REQUIRE_NOTHROW(printReadingRangeList(readingRangeList));
}
