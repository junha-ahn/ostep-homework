You can see how to run `malloc.py` [here](https://github.com/remzi-arpacidusseau/ostep-homework/tree/master/vm-freespace)

## TIL

## Task 1

```shell
$ python malloc.py -n 10 -H 0 -p BEST -s 0
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
compute False

ptr[0] = Alloc(3) returned ?
List? 

Free(ptr[0])
returned ?
List? 

ptr[1] = Alloc(5) returned ?
List? 

Free(ptr[1])
returned ?
List? 

ptr[2] = Alloc(8) returned ?
List? 

Free(ptr[2])
returned ?
List? 

ptr[3] = Alloc(8) returned ?
List? 

Free(ptr[3])
returned ?
List? 

ptr[4] = Alloc(2) returned ?
List? 

ptr[5] = Alloc(7) returned ?
List? 
```

## Task 2

```shell
$ python malloc.py -n 10 -H 0 -p WORST  -s 0
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy WORST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute False

ptr[0] = Alloc(3) returned ?
List? 

Free(ptr[0])
returned ?
List? 

ptr[1] = Alloc(5) returned ?
List? 

Free(ptr[1])
returned ?
List? 

ptr[2] = Alloc(8) returned ?
List? 

Free(ptr[2])
returned ?
List? 

ptr[3] = Alloc(8) returned ?
List? 

Free(ptr[3])
returned ?
List? 

ptr[4] = Alloc(2) returned ?
List? 

ptr[5] = Alloc(7) returned ?
List? 
```

## Task 3

```shell
$ python malloc.py -n 10 -H 0 -p FIRST -s 0
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy FIRST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute False

ptr[0] = Alloc(3) returned ?
List? 

Free(ptr[0])
returned ?
List? 

ptr[1] = Alloc(5) returned ?
List? 

Free(ptr[1])
returned ?
List? 

ptr[2] = Alloc(8) returned ?
List? 

Free(ptr[2])
returned ?
List? 

ptr[3] = Alloc(8) returned ?
List? 

Free(ptr[3])
returned ?
List? 

ptr[4] = Alloc(2) returned ?
List? 

ptr[5] = Alloc(7) returned ?
List? 
```


## Task 4

```shell
$ python malloc.py -n 10 -H 0 -p FIRST -s 0 -l SIZESORT+
$ python malloc.py -n 10 -H 0 -p FIRST -s 0 -l SIZESORT-

$ python malloc.py -n 10 -H 0 -p BEST -s 0 -l SIZESORT+
$ python malloc.py -n 10 -H 0 -p BEST -s 0 -l SIZESORT-
```
## TASK 5
