You can see how to run `paging-linear-translate.py` [here](https://github.com/remzi-arpacidusseau/ostep-homework/tree/master/vm-paging)

## TIL

- The concepts of virtual memory and page tables.
- examples of virtual address translation.

## Question 1

### Change of Address space size
| Example Number | Address Space Size | Page Table Entry Count |
|----------------|--------------------|------------------------|
| 1              | 1MB                | 1024                   |
| 2              | 2MB                | 2048                   |
| 3              | 4MB                | 4096                   |
> Example 1. 1MB (address size) / 1KB (page size) = 1024 

## Chnage of Page size
| Example Number | Address Space Size | Page Size | Page Table Entry Count | 
|----------------|---------------------|-----------|-------------------------|
| 1              | 1M                  | 1K        | 1024     |
| 2              | 1M                  | 2K        | 512      | 
| 3              | 1M                  | 4K        | 256      |
| 4              | 1M                  | 8K        | 128      |

## Question 2

| Experiment Number | Valid Address Ratio | Successful Address Translation Ratio |
|-------------------|---------------------|-------------------------------------|
| 1                 | 0%                  | 0%                                  |
| 2                 | 25%                 | 20%                                 |
| 3                 | 50%                 | 40%                                 |
| 4                 | 75%                 | 60%                                 |
| 5                 | 100%                | 80%                                 |

