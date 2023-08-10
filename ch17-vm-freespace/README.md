You can see how to run `malloc.py` [here](https://github.com/remzi-arpacidusseau/ostep-homework/tree/master/vm-freespace)

## TIL

- There are memory allocation policies such as BEST, WORST, and FIRST, which lead to different sequences and outcomes of allocating empty spaces based on their order.
- Coalescing involves merging empty spaces to maintain larger contiguous blocks, enhancing the efficiency of memory management.

## Task 1

```shell
$ python malloc.py -n 10 -H 0 -p BEST -s 0 -c
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy BEST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1008 sz:92 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1008 (searched 4 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[3])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[4] = Alloc(2) returned 1000 (searched 4 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[5] = Alloc(7) returned 1008 (searched 4 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1015 sz:1 ][ addr:1016 sz:84 ]
```

## Task 2

```shell
$ python malloc.py -n 10 -H 0 -p WORST  -s 0 -c
```

BEST allocation retrieves existing free memory of size 8, but WORST allocates memory from the currently largest available space.


## Task 3

```shell
$ python malloc.py -n 10 -H 0 -p FIRST -s 0
```

Due to the use of ADDRSORT, there is no significant difference between FIRST allocation and BEST allocation

## Task 4

```shell
$ python malloc.py -n 10 -H 0 -p FIRST -s 0 -l
$ python malloc.py -n 10 -H 0 -p FIRST -s 0 -l SIZESORT+
$ python malloc.py -n 10 -H 0 -p FIRST -s 0 -l SIZESORT-

$ python malloc.py -n 10 -H 0 -p BEST -s 0 -l SIZESORT+
$ python malloc.py -n 10 -H 0 -p BEST -s 0 -l SIZESORT-
```

"SIZESORT-" is a method that attempts allocation by sorting empty spaces in descending order based on their sizes.

The "FIRST" method allocates memory in the order it finds suitable spaces, so the order of allocation changes based on how the spaces are sorted. This leads to different results.


## TASK 5


```shell
$ python malloc.py -n 1000 -c

...

Free List [ Size 31 ]


$ python malloc.py -n 1000 -C -c

...

Free List [ Size 1 ]: 
```

In the case of coalescing, empty spaces are continuously merged, resulting in the maintenance of a single large FREE block

When coalescing is enabled, ADDRSORT provides the best results

Worst fit does not perform well with any sorting method. This is because smaller empty spaces are not utilized until all the larger empty spaces are consumed. Over time, due to sorting, these empty spaces become detached from their contiguous regions and thus cannot be coalesced.