extern void filter_execute(csci *classes, size_t classes_size, int (*test)(csci, char *), char *arg, void (*execute)(FILE *, csci), FILE *fp);
extern int test_days_available(csci class, char *days);
extern int test_time_available(csci class, char *daysAndTimeInput);
extern int test_class_standing(csci class, char *standing);
