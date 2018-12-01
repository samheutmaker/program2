#ifndef SOME_HEADER_GUARD_WITH_UNIQUE_NAME
#define SOME_HEADER_GUARD_WITH_UNIQUE_NAME

#define EMAX 250

typedef struct csci
{
  char classNumber[EMAX + 1];
  char className[EMAX + 1];
  char classDay[EMAX + 1];
  char classTime[EMAX + 1];
  char classStanding[EMAX + 1];
} csci;

#endif