//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <pthread.h>
//
//
//void *print_message_function( void *ptr );
//
//int main(void)
//{
//     pthread_t thread1, thread2;
//     char *message1 = "Thread 1";
//     char *message2 = "Thread 2";
//     int  iret1, iret2;
///*
//     Function call: pthread_create
//    int pthread_create(pthread_t * thread,
//                       const pthread_attr_t * attr,
//                       void * (*start_routine)(void *),
//                       void *arg);
//
//Arguments:
//thread - returns the thread id. (unsigned long int defined in bits/pthreadtypes.h)
//attr - Set to NULL if default thread attributes are used. (else define members of the struct pthread_attr_t defined in bits/pthreadtypes.h) Attributes include:
//	-detached state (joinable? Default: PTHREAD_CREATE_JOINABLE. Other option: PTHREAD_CREATE_DETACHED)
//	-scheduling policy (real-time? PTHREAD_INHERIT_SCHED,PTHREAD_EXPLICIT_SCHED,SCHED_OTHER)
//	-scheduling parameter
//	-inherit sched attribute (Default: PTHREAD_EXPLICIT_SCHED Inherit from parent thread: PTHREAD_INHERIT_SCHED)
//	-scope (Kernel threads: PTHREAD_SCOPE_SYSTEM User threads: PTHREAD_SCOPE_PROCESS Pick one or the other not both.)
//	-guard size
//	-stack address (See unistd.h and bits/posix_opt.h _POSIX_THREAD_ATTR_STACKADDR)
//	-stack size (default minimum PTHREAD_STACK_SIZE set in pthread.h),
//void * (*start_routine) - pointer to the function to be threaded. Function has a single argument: pointer to void.
//*arg - pointer to argument of function. To pass multiple arguments, send a pointer to a structure.
//*/
//
//
//
//     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
//     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
///*
//     NAME
//            pthread_join - join with a terminated thread
//     SYNOPSIS
//            #include <pthread.h>
//
//            int pthread_join(pthread_t thread, void **retval);
//
//            Compile and link with -pthread.
//     DESCRIPTION
//            The pthread_join() function waits for the thread specified by thread
//            to terminate.  If that thread has already terminated, then
//            pthread_join() returns immediately.  The thread specified by thread
//            must be joinable.
//
//            If retval is not NULL, then pthread_join() copies the exit status of
//            the target thread (i.e., the value that the target thread supplied to
//            pthread_exit(3)) into the location pointed to by retval.  If the
//            target thread was canceled, then PTHREAD_CANCELED is placed in the
//            location pointed to by retval.
//
//            If multiple threads simultaneously try to join with the same thread,
//            the results are undefined.  If the thread calling pthread_join() is
//            canceled, then the target thread will remain joinable (i.e., it will
//            not be detached).
//     RETURN VALUE
//            On success, pthread_join() returns 0; on error, it returns an error
//            number.
//     ERRORS
//            EDEADLK
//                   A deadlock was detected (e.g., two threads tried to join with
//                   each other); or thread specifies the calling thread.
//
//            EINVAL thread is not a joinable thread.
//
//            EINVAL Another thread is already waiting to join with this thread.
//
//            ESRCH  No thread with the ID thread could be found.
//     ATTRIBUTES         top
//            For an explanation of the terms used in this section, see
//            attributes(7).
//
//     NOTES
//            After a successful call to pthread_join(), the caller is guaranteed
//            that the target thread has terminated.  The caller may then choose to
//            do any clean-up that is required after termination of the thread
//            (e.g., freeing memory or other resources that were allocated to the
//            target thread).
//
//            Joining with a thread that has previously been joined results in
//            undefined behavior.
//
//            Failure to join with a thread that is joinable (i.e., one that is not
//            detached), produces a "zombie thread".  Avoid doing this, since each
//            zombie thread consumes some system resources, and when enough zombie
//            threads have accumulated, it will no longer be possible to create new
//            threads (or processes).
//
//            There is no pthreads analog of waitpid(-1, &status, 0), that is,
//            "join with any terminated thread".  If you believe you need this
//            functionality, you probably need to rethink your application design.
//
//            All of the threads in a process are peers: any thread can join with
//            any other thread in the process.
//
//*/
//     /* Wait till threads are complete before main continues. Unless we  */
//     /* wait we run the risk of executing an exit which will terminate   */
//     /* the process and all threads before the threads have completed.   */
//     pthread_join( thread1, NULL);
//     pthread_join( thread2, NULL);
//
//     printf("Thread 1 returns: %d\n",iret1);
//     printf("Thread 2 returns: %d\n",iret2);
//     exit(0);
//}
//
//void *print_message_function( void *ptr )
//{
//     char *message;
//     message = (char *) ptr;
//     printf("%s \n", message);
//}
