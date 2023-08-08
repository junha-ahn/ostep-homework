## TIL

- Memory Leaks and Debugging with Valgrind and GDB
- Pointer-related programming errors


## Task 1

```shell$ 
$ gcc -o null null.c
$ ./null
Segmentation fault (core dumped)
```

## Task 2

```shell
$ ./gdb null

(gdb) start
Temporary breakpoint 1 at 0x1155: file null.c, line 4.
Starting program: /workspaces/ostep-homework/ch14-vm-api/null 
warning: Error disabling address space randomization: Operation not permitted
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Temporary breakpoint 1, main () at null.c:4
4           int *ptr = NULL; // Initialize a pointer to an integer with NULL

(gdb) next
5           printf("result : %d\n", *ptr); // Dereference a NULL pointer

(gdb) next
Program received signal SIGSEGV, Segmentation fault.
0x0000562d72020161 in main () at null.c:5
5           printf("result : %d\n", *ptr); // Dereference a NULL pointer

(gdb) next
Program terminated with signal SIGSEGV, Segmentation fault.
The program no longer exists.

(gdb) exit


---
(gdb) print *ptr
Cannot access memory at address 0x0

(gdb) print ptr
$1 = (int *) 0x0
```

## Task 3

```shell
valgrind --leak-check=yes ./null
==3936== Memcheck, a memory error detector
==3936== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3936== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==3936== Command: ./null
==3936== 
==3936== Invalid read of size 4
==3936==    at 0x109161: main (null.c:5)
==3936==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==3936== 
==3936== 
==3936== Process terminating with default action of signal 11 (SIGSEGV): dumping core
==3936==  Access not within mapped region at address 0x0
==3936==    at 0x109161: main (null.c:5)
==3936==  If you believe this happened as a result of a stack
==3936==  overflow in your program's main thread (unlikely but
==3936==  possible), you can try to increase the size of the
==3936==  main thread stack using the --main-stacksize= flag.
==3936==  The main thread stack size used in this run was 8388608.
==3936== 
==3936== HEAP SUMMARY:
==3936==     in use at exit: 0 bytes in 0 blocks
==3936==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==3936== 
==3936== All heap blocks were freed -- no leaks are possible
==3936== 
==3936== For lists of detected and suppressed errors, rerun with: -s
==3936== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```

You can check `Invalid read of size 4` while execute `printf("result : %d\n", *ptr);`

In the case there is no heap memory in use and no memory has been allocated/deallocated upon program termination, no memory leaks occur.

## Task 4

```shell
 $ gdb nofree

(gdb) start
Temporary breakpoint 1 at 0x1175: file nofree.c, line 5.
Starting program: /workspaces/ostep-homework/ch14-vm-api/nofree 
warning: Error disabling address space randomization: Operation not permitted
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Temporary breakpoint 1, main () at nofree.c:5
5           int *ptr = (int *)malloc(sizeof(int)); // Allocate memory
(gdb) next
6           *ptr = 5; // Store a value in the allocated memory
(gdb) next
10          printf("Value: %d\n", *ptr); // Access the allocated memory
(gdb) next
Value: 5
12          return 0;
(gdb) next
13      }
(gdb) next
__libc_start_call_main (main=main@entry=0x55912b474169 <main>, argc=argc@entry=1, argv=argv@entry=0x7fff874b8e58) at ../sysdeps/nptl/libc_start_call_main.h:74
74      ../sysdeps/nptl/libc_start_call_main.h: No such file or directory.
(gdb) next
[Inferior 1 (process 10571) exited normally]
(gdb) next
The program is not being run.
(gdb) exit
```

GDB itself does not detect memory leaks or provide warning messages for memory leaks.

```shell
$ valgrind --leak-check=yes ./nofree
==11570== Memcheck, a memory error detector
==11570== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11570== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==11570== Command: ./nofree
==11570== 
Value: 5
==11570== 
==11570== HEAP SUMMARY:
==11570==     in use at exit: 4 bytes in 1 blocks
==11570==   total heap usage: 2 allocs, 1 frees, 1,028 bytes allocated
==11570== 
==11570== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==11570==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==11570==    by 0x10917E: main (nofree.c:5)
==11570== 
==11570== LEAK SUMMARY:
==11570==    definitely lost: 4 bytes in 1 blocks
==11570==    indirectly lost: 0 bytes in 0 blocks
==11570==      possibly lost: 0 bytes in 0 blocks
==11570==    still reachable: 0 bytes in 0 blocks
==11570==         suppressed: 0 bytes in 0 blocks
==11570== 
==11570== For lists of detected and suppressed errors, rerun with: -s
==11570== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

`definitely lost: 4 bytes in 1 blocks`

# Task 5

```shell
$ valgrind --leak-check=yes ./clear_array
==12950== Memcheck, a memory error detector
==12950== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12950== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==12950== Command: ./clear_array
==12950== 
==12950== 
==12950== HEAP SUMMARY:
==12950==     in use at exit: 0 bytes in 0 blocks
==12950==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12950== 
==12950== All heap blocks were freed -- no leaks are possible
==12950== 
==12950== For lists of detected and suppressed errors, rerun with: -s
==12950== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

`int data[100]` is allocated on the stack, and the stack is deallocated upon the end of function execution, so there is no memory leakage.

## Task 7

```shell
$ gcc -o invalid_free invalid_free.c
invalid_free.c: In function ‘main’:
invalid_free.c:9:5: warning: ‘free’ called on unallocated object ‘data’ [-Wfree-nonheap-object]
    9 |     free(ptr);
      |     ^~~~~~~~~
invalid_free.c:5:9: note: declared here
    5 |     int data[100];
      |         ^~~~
```

```shell
 $ ./invalid_free
free(): invalid pointer
Aborted (core dumped)
```

```shell
$ valgrind --leak-check=yes ./invalid_free
==15566== Memcheck, a memory error detector
==15566== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==15566== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==15566== Command: ./invalid_free
==15566== 
==15566== Invalid free() / delete / delete[] / realloc()
==15566==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15566==    by 0x1091C9: main (in /workspaces/ostep-homework/ch14-vm-api/invalid_free)
==15566==  Address 0x1ffefffcc8 is on thread 1's stack
==15566==  in frame #1, created by main (???:)
==15566== 
==15566== Conditional jump or move depends on uninitialised value(s)
==15566==    at 0x48D6B56: __vfprintf_internal (vfprintf-internal.c:1516)
==15566==    by 0x48C081E: printf (printf.c:33)
==15566==    by 0x1091E8: main (in /workspaces/ostep-homework/ch14-vm-api/invalid_free)
==15566== 
==15566== Use of uninitialised value of size 8
==15566==    at 0x48BA33B: _itoa_word (_itoa.c:177)
==15566==    by 0x48D5B3D: __vfprintf_internal (vfprintf-internal.c:1516)
==15566==    by 0x48C081E: printf (printf.c:33)
==15566==    by 0x1091E8: main (in /workspaces/ostep-homework/ch14-vm-api/invalid_free)
==15566== 
==15566== Conditional jump or move depends on uninitialised value(s)
==15566==    at 0x48BA34C: _itoa_word (_itoa.c:177)
==15566==    by 0x48D5B3D: __vfprintf_internal (vfprintf-internal.c:1516)
==15566==    by 0x48C081E: printf (printf.c:33)
==15566==    by 0x1091E8: main (in /workspaces/ostep-homework/ch14-vm-api/invalid_free)
==15566== 
==15566== Conditional jump or move depends on uninitialised value(s)
==15566==    at 0x48D6643: __vfprintf_internal (vfprintf-internal.c:1516)
==15566==    by 0x48C081E: printf (printf.c:33)
==15566==    by 0x1091E8: main (in /workspaces/ostep-homework/ch14-vm-api/invalid_free)
==15566== 
==15566== Conditional jump or move depends on uninitialised value(s)
==15566==    at 0x48D5C85: __vfprintf_internal (vfprintf-internal.c:1516)
==15566==    by 0x48C081E: printf (printf.c:33)
==15566==    by 0x1091E8: main (in /workspaces/ostep-homework/ch14-vm-api/invalid_free)
==15566== 
Value at invalid pointer: 0
==15566== 
==15566== HEAP SUMMARY:
==15566==     in use at exit: 0 bytes in 0 blocks
==15566==   total heap usage: 1 allocs, 2 frees, 1,024 bytes allocated
==15566== 
==15566== All heap blocks were freed -- no leaks are possible
==15566== 
==15566== Use --track-origins=yes to see where uninitialised values come from
==15566== For lists of detected and suppressed errors, rerun with: -s
==15566== ERROR SUMMARY: 6 errors from 6 contexts (suppressed: 0 from 0)
```

Errors
- `Invalid free()`
- `Conditional jump or move depends on uninitialised value(s)`, `Value at invalid pointer: 0:` both occurring at the `printf("Value at invalid pointer: %d\n", *ptr);`


