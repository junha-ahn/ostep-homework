## TIL

- Changes `used` Memory upon program execution
- `Dirty` Memory refers to altered data, where memory regions change when processes modify data.
- `Resident Set Size (RSS)` indicates the actual physical memory used by a process. 


## Free

`used` memory increases upon program execution (1832M => 1929M)

```shell
$ free -m
               total        used        free      shared  buff/cache   available
Mem:            3913        1832         217           4        1863        1778
Swap:              0           0           0

$ ./memory-user 100
$ free -m
               total        used        free      shared  buff/cache   available
Mem:            3913        1929         120           4        1864        1681
Swap:              0           0           0

# exit
$ free -m
               total        used        free      shared  buff/cache   available
Mem:            3913        1839         210           4        1864        1771
Swap:              0           0           0
```

## pmap

RSS(Resident Set Size): the actual amount of physical memory currently used by a process.

```shell
$ ./memory-user 100
$ pgrep memory-user
6881
$ pmap 6881 -x
6881:   ./memory-user 100
Address           Kbytes     RSS   Dirty Mode  Mapping
0000558d005e7000       4       4       0 r---- memory-user
0000558d005e8000       4       4       0 r-x-- memory-user
0000558d005e9000       4       4       0 r---- memory-user
0000558d005ea000       4       4       4 r---- memory-user
0000558d005eb000       4       4       4 rw--- memory-user
0000558d00b91000     132       4       4 rw---   [ anon ]

00007f0e4d450000  102416  102412  102412 rw---   [ anon ] 
# 102MB has been allocated at the memory address 00007f0e4d450000 
# The term "[ anon ]" indicates an anonymous memory mapping.

00007f0e53854000     160     160       0 r---- libc.so.6
00007f0e5387c000    1620     908       0 r-x-- libc.so.6
00007f0e53a11000     352     184       0 r---- libc.so.6
00007f0e53a69000      16      16      16 r---- libc.so.6
00007f0e53a6d000       8       8       8 rw--- libc.so.6
00007f0e53a6f000      52      20      20 rw---   [ anon ]
00007f0e53a81000       8       4       4 rw---   [ anon ]
00007f0e53a83000       8       8       0 r---- ld-linux-x86-64.so.2
00007f0e53a85000     168     168       0 r-x-- ld-linux-x86-64.so.2
00007f0e53aaf000      44      40       0 r---- ld-linux-x86-64.so.2
00007f0e53abb000       8       8       8 r---- ld-linux-x86-64.so.2
00007f0e53abd000       8       8       8 rw--- ld-linux-x86-64.so.2
00007fffbb7fe000     132      16      16 rw---   [ stack ]
00007fffbb8a3000      16       0       0 r----   [ anon ]
00007fffbb8a7000       8       4       0 r-x--   [ anon ]
ffffffffff600000       4       0       0 --x--   [ anon ]
---------------- ------- ------- ------- 
total kB          105180  103988  102504
```


```shell
$ ./memory-user 1
$ pgrep memory-user
9725
$ pmap 9725
9725:   ./memory-user 1
0000556195ba3000      4K r---- memory-user
0000556195ba4000      4K r-x-- memory-user
0000556195ba5000      4K r---- memory-user
0000556195ba6000      4K r---- memory-user
0000556195ba7000      4K rw--- memory-user
0000556197370000    132K rw---   [ anon ]
00007f143deb8000   1040K rw---   [ anon ]
00007f143dfbc000    160K r---- libc.so.6
00007f143dfe4000   1620K r-x-- libc.so.6
00007f143e179000    352K r---- libc.so.6
00007f143e1d1000     16K r---- libc.so.6
00007f143e1d5000      8K rw--- libc.so.6
00007f143e1d7000     52K rw---   [ anon ]
00007f143e1e9000      8K rw---   [ anon ]
00007f143e1eb000      8K r---- ld-linux-x86-64.so.2
00007f143e1ed000    168K r-x-- ld-linux-x86-64.so.2
00007f143e217000     44K r---- ld-linux-x86-64.so.2
00007f143e223000      8K r---- ld-linux-x86-64.so.2
00007f143e225000      8K rw--- ld-linux-x86-64.so.2
00007ffc05a77000    132K rw---   [ stack ]
00007ffc05b6d000     16K r----   [ anon ]
00007ffc05b71000      8K r-x--   [ anon ]
ffffffffff600000      4K --x--   [ anon ]
 total             3804K
```