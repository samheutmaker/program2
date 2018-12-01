/* 
Authored by Sam Heutmaker and Jesse Dahl
11/30/2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "filter.h"
#include "print.h"
#include "sort.h"

#define STRING(X) #X
#define STRINGIFY(X) STRING(X)

void menu(csci *classes, size_t classes_size);
void all_classes(csci *classes, size_t classes_size, FILE *fp);
void classes_by_day(csci *classes, size_t classes_size, FILE *fp);
void classes_by_time(csci *classes, size_t classes_size, FILE *fp);
void classes_by_standing(csci *classes, size_t classes_size, FILE *fp);

  int main(void)
  {
    FILE *file;
    csci info;
    csci *classes = NULL;
    size_t classes_size = 0;

    file = fopen("classes.txt", "r");

    // Create classes from file input
    while (fscanf(file, "%" STRINGIFY(EMAX) "s %" STRINGIFY(EMAX) "[^:] %" STRINGIFY(EMAX) "s "
                                                                                           "%" STRINGIFY(EMAX) "s %" STRINGIFY(EMAX) "s",
                  info.classNumber, info.className, info.classDay, info.classTime, info.classStanding) == 5)
    {
      csci *tmp = realloc(classes, ++classes_size * sizeof(*classes));
      classes = tmp;
      classes[classes_size - 1] = info;
    }
    fclose(file);

    menu(classes, classes_size);

    return 0;
  }

  // Print menu
  void menu(csci * classes, size_t classes_size)
  {
    char user_input[50];
    FILE *fp;
    fp = fopen("userQueries.txt", "w");
    fprintf(fp, "\nUser Queries: \n");
    fclose(fp);

    do
    {
      printf("\nSelect one of the following options:\n");
      printf("1) Print all information about all CSCI classes.\n");
      printf("2) Print all classes available on MWF or on TR.\n");
      printf("3) Print the class(es) at a specific time.\n");
      printf("4) Print classes available to freshman, sophomores, juniors, and seniors.\n");
      printf("5) Quit\n");
      fgets(user_input, 50, stdin);
      strtok(user_input, "\n");


      if (strcmp(&user_input[0], "1") == 0)
      {
        all_classes(classes, classes_size, fp);
      }
      else if (strcmp(&user_input[0], "2") == 0)
      {
        classes_by_day(classes, classes_size, fp);
      }
      else if (strcmp(&user_input[0], "3") == 0)
      {
        classes_by_time(classes, classes_size, fp);
      }
      else if (strcmp(&user_input[0], "4") == 0)
      {
        classes_by_standing(classes, classes_size, fp);
      }

      else if(strcmp(&user_input[0], "5") != 0) {
        printf("Invalid input. Quitting.\n\n");
        exit(EXIT_FAILURE);
      }

    } while (strcmp(&user_input[0], "5") != 0);

    // Quit
    if (strcmp(&user_input[0], "5") == 0)
    {
      printf("Goodbye!\n");
    } 
  }

  // Print all classes
  void all_classes(csci * classes, size_t classes_size, FILE * fp)
  {
    // Sort classes before filtering before printing info
    sort_by_class_number(classes, classes_size);
    int i;
    fp = fopen("userQueries.txt", "a");
    fprintf(fp, "\nUser query for all class information: \n");
    for (i = 0; i < classes_size; i++)
    {
      print_class_info(fp, classes[i]);
      
    }
    fclose(fp);
  }

  // Print classes by day
  void classes_by_day(csci * classes, size_t classes_size, FILE * fp)
  {
    // Sort classes before filtering and executing
    sort_by_class_time(classes, classes_size);
    int i;
    fp = fopen("userQueries.txt", "a");
    fprintf(fp, "\nUser query for day availabilities: \n");

    printf("\nClasses available on MWF: \n");
    fprintf(fp, "\nClasses available on MWF: \n");
    filter_execute(classes, classes_size, test_days_available, ":MWF", print_class_info, fp);


    printf("\nClasses available on TR: \n");
    fprintf(fp, "\nClasses available on TR: \n");
    filter_execute(classes, classes_size, test_days_available, ":TR", print_class_info, fp);

    fclose(fp);
  }
  // Print classes by time
  void classes_by_time(csci * classes, size_t classes_size, FILE * fp)
  {
    fp = fopen("userQueries.txt", "a");
    char line[50];
    int i = 0;
    char *args[2];
    
    printf("\nEnter a set of days along with a time: \n");
    fgets(line, 50, stdin);

    char *p = strtok(line, " ");

    while (p != NULL)
    {
      args[i++] = p;
      p = strtok(NULL, " ");
    }

    char *days = args[0];
    char *hours = args[1];

    char daysAndTime[50];
    strcat(daysAndTime, days);
    strcat(daysAndTime, hours);
    

    fprintf(fp, "\nClasses Available:");
    filter_execute(classes, classes_size, test_time_available, daysAndTime, print_class_info, fp);
    fclose(fp);
  }

  // Print classes by standing
  void classes_by_standing(csci * classes, size_t classes_size, FILE * fp)
  { 
    // Sort classes before filtering and executing
    sort_by_class_number(classes, classes_size);

    fp = fopen("userQueries.txt", "a");
    fprintf(fp, "\nUser queries for class availability: \n");

    fprintf(fp, "\nClasses available to freshman: \n");
    filter_execute(classes, classes_size, test_class_standing, "1", print_class_info, fp);

    fprintf(fp, "\nClasses available to sophomores: \n");
    filter_execute(classes, classes_size, test_class_standing, "2", print_class_info, fp);

    fprintf(fp, "\nClasses available to juniors: \n");
    filter_execute(classes, classes_size, test_class_standing, "3", print_class_info, fp);

    fprintf(fp, "\nClasses available to seniors: \n");
    filter_execute(classes, classes_size, test_class_standing, "4", print_class_info, fp);

    fclose(fp);
}


