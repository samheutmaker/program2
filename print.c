#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

char *char_to_standing(char *standing_char)
{
  if (strcmp(standing_char, "1") == 0)
  {
    return "freshmen";
  }
  else if (strcmp(standing_char, "2") == 0)
  {
    return "sophmores";
  }
  else if (strcmp(standing_char, "3") == 0)
  {
    return "juniors";
  }
  else if (strcmp(standing_char, "4") == 0)
  {
    return "seniors";
  }
  else
  {
    // Bad info in class list file
    printf("Invalid value for class standing in class list, quitting..");
    exit(EXIT_FAILURE);
  }
}

void print_class_info(FILE *fp, csci class)
{
  printf("%s %s available for %s %s %s\n", class.className, class.classNumber, char_to_standing(class.classStanding), class.classDay, class.classTime);
  fprintf(fp, "%s %s available for %s %s %s\n", class.className, class.classNumber, char_to_standing(class.classStanding), class.classDay, class.classTime);
}

