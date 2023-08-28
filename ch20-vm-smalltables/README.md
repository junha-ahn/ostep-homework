You can see how to run `paging-multilevel-translate` [here](https://github.com/remzi-arpacidusseau/ostep-homework/tree/master/vm-smalltables)

## Question 1

One Register enough to refer other page directory 

## Question 2

```shell
$ python paging-multilevel-translate.py -s 3 -c
ARG seed 3
ARG allocated 64
ARG num 10

page   0:0d0f06121d0c10030814031b1c031d0b17170914141808171d1410030f0a1615
...
page 127:0000000000000000000000000000000000000000000000000000000000000000

PDBR: 30  (decimal) [This means the page directory is held in this page]

Virtual Address 0x45b0:
  --> pde index:0x11 [decimal 17] pde contents:0xcd (valid 1, pfn 0x4d [decimal 77])
    --> pte index:0xd [decimal 13] pte contents:0xaf (valid 1, pfn 0x2f [decimal 47])
      --> Translates to Physical Address 0x5f0 --> Value: 0x14
Virtual Address 0x7bb9:
  --> pde index:0x1e [decimal 30] pde contents:0x7f (valid 0, pfn 0x7f [decimal 127])
      --> Fault (page directory entry not valid)
Virtual Address 0x1ebe:
  --> pde index:0x7 [decimal 7] pde contents:0xe8 (valid 1, pfn 0x68 [decimal 104])
    --> pte index:0x15 [decimal 21] pte contents:0x7f (valid 0, pfn 0x7f [decimal 127])
      --> Fault (page table entry not valid)
```

## Question 3

If TLB miss, then will two more memory access 