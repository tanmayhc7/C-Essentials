/*****************************************
	1115. Print FooBar Alternately
Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads. 
Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.
Example 1:
Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). 
			"foobar" is being output 1 time.
Example 2:
Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
*****************************************/
typedef struct {
    int n;
    sem_t sem1,sem2;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    sem_init(&obj->sem1,0,1);//to post a semaphore at init
    sem_init(&obj->sem2,0,0);
    return obj;
}

void foo(FooBar* obj) {
    int i=0;//Do not use static for variables as static resources are shared between threads
    for (; i < obj->n;i++) {
        sem_wait(&obj->sem1);
        printFoo();   // printFoo() outputs "foo". Do not change or remove this line.
        sem_post(&obj->sem2);
    }
}

void bar(FooBar* obj) {
    int i = 0;
    for (; i < obj->n;i++) {
        sem_wait(&obj->sem2);
        printBar(); // printBar() outputs "bar". Do not change or remove this line.
        sem_post(&obj->sem1);   
    }
}

void fooBarFree(FooBar* obj) {
     sem_destroy(&obj->sem1); sem_destroy(&obj->sem2);
     free(obj); obj=NULL;
}
