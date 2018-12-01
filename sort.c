#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

void sort_by_class_number(csci *classes, size_t classes_size)
{

  for (int i = 0; i < classes_size; i++)
  {
    for (int j = 0; j < classes_size; j++)
    {
      if (strcmp(classes[j].classNumber, classes[i].classNumber) > 0)
      {
        csci temporary = classes[i];
        classes[i] = classes[j];
        classes[j] = temporary;
      }
    }
  }
}

void sort_by_class_time(csci *classes, size_t classes_size)
{

  for (int i = 0; i < classes_size; i++)
  {
    for (int j = 0; j < classes_size; j++)
    {
      if (strcmp(classes[j].classTime, classes[i].classTime) > 0)
      {
        csci temporary = classes[i];
        classes[i] = classes[j];
        classes[j] = temporary;
      }
    }
  }
}