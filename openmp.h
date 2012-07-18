#if _OPENMP
#include <omp.h>
#else
#warning OpenMP emulation enabled
#include <sys/time.h>
#define omp_get_thread_num()  0
#define omp_get_max_threads() 1
double omp_get_wtime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	static time_t start_sec = 0;
	if (!start_sec) start_sec = tv.tv_sec;

	return (double)(tv.tv_sec - start_sec) + ((double)tv.tv_usec)/1000000.0;
}
#endif
