/***Create Two Threads  **/


#include <pthread.h>
#include <stdio.h>
/* Parameters to print_function. */
struct char_print_parms
{
/* The character to print. */
	char character;
/* The number of times to print it. */
	int count;
};
/* Prints a number of characters to stderr, as given by PARAMETERS,
which is a pointer to a struct char_print_parms. */
void* char_print (void* parameters)
{
/* Cast the cookie pointer to the right type. */
	struct char_print_parms* p = (struct char_print_parms*) parameters;
	int i;
for (i = 0; i < p->count; ++i)
	putchar (p->character);
return NULL;
}
/* The main program. */
int main ()
{
	pthread_t thread1_id;
	pthread_t thread2_id;
	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;
/* Create a new thread to print 30,000 ’x’s. */
	thread1_args.character=65;
	thread1_args.count = 3;
	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
/* Create a new thread to print 20,000 o’s. */
	thread2_args.character = 66;
	thread2_args.count = 2;
	pthread_create (&thread2_id, NULL, &char_print, &thread2_args);
	pthread_join(thread1_id, NULL);
	pthread_join(thread2_id, NULL);
return 0;
}
