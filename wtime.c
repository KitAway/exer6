
#ifdef _OPENMP
#include <omp.h>
#else
#include <time.h>
#endif

#include <stdlib.h>

double wtime()
{
#ifdef _OPENMP
	/* Use omp_get_wtime() if we can */
	return omp_get_wtime();
#else
	/* Use a generic timer */
	//static int sec = -1;
	time_t timer;
	time(&timer);  /* get current time; same as: timer = time(NULL)  */
	struct tm *tv = gmtime(&timer);
	return tv->tm_sec+tv->tm_min*60+tv->tm_hour*3600;
#endif
}