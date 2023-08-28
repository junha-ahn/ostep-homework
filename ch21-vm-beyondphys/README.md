## TIL

## Question 1

As you can see, User time increase 

If we run multiple processes, it will continue to increase even more

```shell
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 1  0      0 170948 400908 1583080    0    0   139   476  159 1042  3  1 95  1  0
 1  0      0 170716 400908 1583252    0    0     0     8  776 3698  4  5 91  0  0 # RUN mem.c 1
 1  0      0 169456 400908 1583268    0    0     0    24  272 2525 23  3 74  0  0
 1  0      0 158128 400956 1583284    0    0     0   172   81 3994 55  7 38  0  0
 1  0      0 161948 400980 1583432    0    0   108  1772  240 8465 62  8 29  1  0
 0  0      0 152360 401048 1583560    0    0     0    96 1002 2897  2  7 91  0  0 # EXIT
 0  0      0 152360 401048 1583548    0    0     0     0  304 1142  1  3 96  0  0 
 0  0      0 159928 401056 1583544    0    0     0    20  826 2887  4  7 89  0  0
 0  0      0 159964 401064 1583572    0    0     0    24  481 4474  7  6 87  1  0
```

## Question 2

`Free` decreases, and the swap usage (`swpd`) remains unchanged because I have enough RAM to handle it.

## Question 6

process killed (Terminated)

## Question 7

HDD spend more time on swapping than SDD (approximately twice as much)




