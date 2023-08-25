## TIL
- TLB Miss: When a TLB miss occurs, it means that the desired page table entry is not present in the TLB, and as a result, data needs to be fetched from memory. This significantly increases the access time.

## Question 1

`gettimeofday` function can measure time in microseconds (one millionth of a second)

but modern CPUs typically operate at GHz (gigahertz), meaning they execute tens of billions of instructions per second. Therefore, we should use the `clock_gettime` function, which provides higher time resolution. 

However, in this specific example, we only invoke `gettimeofday` at the beginning and end, so the inaccuracy is negligible. Hence, we will use `gettimeofday`


## Question 

- As the number of pages increases, the access time becomes longer. This is because when the number of pages exceeds the size of the TLB, it leads to TLB misses, resulting in additional time to fetch data from memory.
- There is a point where the access time sharply increases as the number of pages increases. At this point, TLB misses occur, and it takes more time to read data from memory.

```shell
$ ./tlb-excute.sh 

Running ./tlb 1 100000
Average access time: 738.00 microseconds

Running ./tlb 2 100000
Average access time: 451.00 microseconds

Running ./tlb 4 100000
Average access time: 448.75 microseconds

Running ./tlb 8 100000
Average access time: 493.62 microseconds

Running ./tlb 16 100000
Average access time: 620.19 microseconds

Running ./tlb 32 100000
Average access time: 872.88 microseconds

Running ./tlb 64 100000
Average access time: 883.22 microseconds

Running ./tlb 128 100000
Average access time: 861.53 microseconds

Running ./tlb 256 100000
Average access time: 776.77 microseconds

Running ./tlb 512 100000
Average access time: 876.71 microseconds

Running ./tlb 1024 100000
Average access time: 886.58 microseconds

Running ./tlb 2048 100000
Average access time: 1053.12 microseconds

Running ./tlb 4096 100000
Average access time: 963.65 microseconds

Running ./tlb 8192 100000
Average access time: 961.21 microseconds

Running ./tlb 16384 100000
Average access time: 1609.30 microseconds
```