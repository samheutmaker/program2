#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

// Filter the classes based on what 'test' returns. The class passes, feed it to execute
void filter_execute(csci *classes, size_t classes_size, int (*test)(csci, char *), char *arg, void (*execute)(FILE *, csci), FILE *fp)
{
  int i = 0;
  for (i = 0; i < classes_size; i++)
  {
    int is_truthy = (*test)(classes[i], arg);

    if (is_truthy)
    {
      (*execute)(fp, classes[i]);
    } // else do nothing
  }
}

// Test which days are available
int test_days_available(csci class, char *days)
{
  if (strcmp(class.classDay, days) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// Test what time are available
int test_time_available(csci class, char *daysAndTimeInput)
{

  strtok(daysAndTimeInput, "\n");

  char *class_time;
  char class_day[10];

  size_t class_time_length = strlen(class.classTime);
  size_t class_day_length = strlen(class.classDay);

  strncpy(class_time, class.classTime, 4);
  class_time[4] = 0;

  strcpy(class_day, class.classDay);
  class_day[(int)class_day_length] = '\0';

  int i;
  for(i = 0; i < class_day_length -1; i++) {
    class_day[i] = class_day[i+1];
  }

  class_day[(int)class_day_length - 1] = '\0';

  char daysAndTime[class_time_length + class_day_length];
  strcpy(daysAndTime, class_day);
  strcat(daysAndTime, class_time);

  if (strcmp(daysAndTime, daysAndTimeInput) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// Test which standing is required to take a class
int test_class_standing(csci class, char *standing)
{
  if (strcmp(class.classStanding, standing) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}