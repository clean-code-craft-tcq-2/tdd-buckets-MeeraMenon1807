#include "ranges.h"
#include "sort.h"

// function to get reading range list
// avoided printing directly in function to decouple functionality so in case if printing format or destination is changed in future this function won't have to change
ReadingRangeList getReadingRangeList(int *readingsArray, int size)
{
    int(*sortedArray) = sort(readingsArray, size);
    ReadingRange *readingRanges = (ReadingRange *)malloc(size * sizeof(ReadingRange));
    int start = sortedArray[0], end = sortedArray[0], count = 0, rangeIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (sortedArray[i] == start || sortedArray[i] == end + 1)
        {
            count++;
            end = sortedArray[i];
        }
        else
        {
            readingRanges[rangeIndex] = {start, end, count};
            rangeIndex++;
            count = 1;
            start = sortedArray[i];
            end = start;
        }
    }
    readingRanges[rangeIndex] = {start, end, count};
    ReadingRangeList readingRangeList = {readingRanges, rangeIndex + 1};
    return readingRangeList;
}

// function to prints reading range list to console
void printReadingRangeList(ReadingRangeList readingRangeList)
{
    printf("Range, Readings\n");
    ReadingRange *readingRanges = readingRangeList.readingRanges;
    for (int i = 0; i < readingRangeList.totalReadingRanges; i++)
    {
        printf("%d-%d, %d\n", readingRanges[i].rangeStart, readingRanges[i].rangeEnd, readingRanges[i].numberOfReadings);
    }
}