#include <stdio.h>

typedef struct ReadingRange {
    int rangeStart;
    int rangeEnd;
    int numberOfReadings;
} ReadingRange;

typedef struct ReadingRangeList {
    ReadingRange *readingRanges;
    int totalReadingRanges;
} ReadingRangeList;

ReadingRangeList getReadingRangeList(int *readingsArray, int size);

void printReadingRangeList(ReadingRangeList readingRangeList);