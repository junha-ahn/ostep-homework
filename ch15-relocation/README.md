You can see how to run `relocation.py` [here](https://github.com/remzi-arpacidusseau/ostep-homework/tree/master/vm-mechanism)

## TIL

- The roles of address base and limit are to control memory protection and the available address space

## Task 1

```shell
$ python ./relocation.py  -s 1

ARG seed 1
ARG address space size 1k
ARG phys mem size 16k

Base-and-Bounds register information:

  Base   : 0x0000363c (decimal 13884)
  Limit  : 290

Virtual Address Trace
  VA  0: 0x0000030e (decimal:  782) --> PA or segmentation violation? # SEGMENTATION VIOLATION
  VA  1: 0x00000105 (decimal:  261) --> PA or segmentation violation? # VALID
  VA  2: 0x000001fb (decimal:  507) --> PA or segmentation violation? # SEGMENTATION VIOLATION
  VA  3: 0x000001cc (decimal:  460) --> PA or segmentation violation? # SEGMENTATION VIOLATION
  VA  4: 0x0000029b (decimal:  667) --> PA or segmentation violation? # SEGMENTATION VIOLATION
```

## Task 2

```shell
$ python ./relocation.py  -s 1 -n 10

ARG seed 1
ARG address space size 1k
ARG phys mem size 16k

Base-and-Bounds register information:

  Base   : 0x0000363c (decimal 13884)
  Limit  : 290

Virtual Address Trace
  VA  0: 0x0000030e (decimal:  782) --> PA or segmentation violation?
  VA  1: 0x00000105 (decimal:  261) --> PA or segmentation violation?
  VA  2: 0x000001fb (decimal:  507) --> PA or segmentation violation?
  VA  3: 0x000001cc (decimal:  460) --> PA or segmentation violation?
  VA  4: 0x0000029b (decimal:  667) --> PA or segmentation violation?
  VA  5: 0x00000327 (decimal:  807) --> PA or segmentation violation?
  VA  6: 0x00000060 (decimal:   96) --> PA or segmentation violation?
  VA  7: 0x0000001d (decimal:   29) --> PA or segmentation violation?
  VA  8: 0x00000357 (decimal:  855) --> PA or segmentation violation?
  VA  9: 0x000001bb (decimal:  443) --> PA or segmentation violation?
```

When using the option `-l 868`, all virtual addresses are valid

## Task 3

```shell
$ python ./relocation.py  -s 1 -n 10 -l 100 -c

ARG seed 1
ARG address space size 1k
ARG phys mem size 16k

Base-and-Bounds register information:

  Base   : 0x00000899 (decimal 2201)
  Limit  : 100

Virtual Address Trace
  VA  0: 0x00000363 (decimal:  867) --> SEGMENTATION VIOLATION
  VA  1: 0x0000030e (decimal:  782) --> SEGMENTATION VIOLATION
  VA  2: 0x00000105 (decimal:  261) --> SEGMENTATION VIOLATION
  VA  3: 0x000001fb (decimal:  507) --> SEGMENTATION VIOLATION
  VA  4: 0x000001cc (decimal:  460) --> SEGMENTATION VIOLATION
  VA  5: 0x0000029b (decimal:  667) --> SEGMENTATION VIOLATION
  VA  6: 0x00000327 (decimal:  807) --> SEGMENTATION VIOLATION
  VA  7: 0x00000060 (decimal:   96) --> VALID: 0x000008f9 (decimal: 2297)
  VA  8: 0x0000001d (decimal:   29) --> VALID: 0x000008b6 (decimal: 2230)
  VA  9: 0x00000357 (decimal:  855) --> SEGMENTATION VIOLATION
```

There is no difference when changing the start of the base address.


## Task 4

There is no difference when changing the size of address space or physical memory