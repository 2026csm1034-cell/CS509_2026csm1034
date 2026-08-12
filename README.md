# CS509_2026csm1034 Laboratory Repository 
Lab assignment for CS509 at IIT Ropar

# Assignment 01

This assignment consists of two major tasks:

- General Matrix Multiplication (GEMM)
- Graph representation using Compressed Sparse Row (CSR)

Both weighted and unweighted graphs are supported for CSR conversion.

## Student Details

- Name: Md Sadruzzama
- Entry No.: 2026CSM1034
- Mode for this repository: Individual


## Language and Environment

- Language: C++
- Compiler: g++  (Rev3, Built by MSYS2 project) 13.2.0
- OS: Apple clang version 21.0.0 (clang-2100.1.1.101)
- Compile flags used: `-std=c++17`
- Timing method: `chrono::high_resolution_clock`, wall-clock duration in
  milliseconds

## Directory Structure

```text
common_wrapper/
    main.cpp
    menu.cpp
    menu.h
    utilities.h

assignment_01/
    driver/
        driver.h
        driver.cpp
    outputs/
    src/
        csr/
            csr.h
            generate_CSR.cpp
        gemm/
            blocking_gemm.cpp
            gemm.h
            simple_gemm.cpp
    tests/
        csr/
            csr_test_10.txt
            ....
            ...
        gemm/
            gemm_test_01.txt
            gemm_test_02.txt
            ...
            ...
    readme.md

    Makefile        
```

## Timing Conventions
- The timer starts immediately before the algorithm call and stops immediately after it returns.
- File reading, input parsing, memory allocation for inputs, and result printing are excluded from the reported time.
- All times below are in milliseconds (ms).

# Input Formate

## GEMM

```text
M K N
<Matrix A (M × K)>
<Matrix B (K × N)>
```
## Graph

```text
V E
u1 d v1 W1--> d stand for degree
u2 d v2 W2
...
```

## File Structure
- `assignment_01/src/gemm.h`, `simple_gemm.cpp` — GEMM implementations
- `assignment_01/src/gemm.h`, `blocking_gemm.cpp` - Blocked GEMM implementations
- `assignment_01/src/csr.h`, `generate_CSR.cpp` — adjacency-list reader + CSR conversion
- `assignment_01/driver/driver.cpp` — drivers
- `assignment_01/tests/gemm/`, `tests/csr/` — test files
## Compilation
```zsh
cd ./CS509_2026csm1034
make
```
## Execution
```zsh
./cs509
```
##  GEMM Results Table

| Test File | Input Size (M K N) | Simple Time (ms) | Blocking Time (ms) | Block Size | Status |
|------------------|-----------|-----------|-----------|----|-------------|
| gemm_test_01.txt | [2 3 2]   | 0.0006 | 0.0003 | 32 | ✅ Pass |
| gemm_test_03.txt | [250 250 250] | 13.557 | 20.9001| 32 | ✅ Pass |

##  CSR Conversion Results Table


| Test File | Vertices (V) | Edges (E) | Weighted | Conversion Time (ms) | Status |
|-----------|--------------|-----------|----------|-----------------|--------|
| csr_10.txt | 10 | 20 | No | 0.002459  |✅ Pass |
| csr_100.txt | 100 | 150 | No | 0.005334 | ✅ Pass |
| csr_10000.txt | 10000 | 15000 | No | 0.1905| ✅ Pass |
| csr_50000.txt | 50000 | 75000 | No | 0.372958| ✅ Pass |
| csr_100000.txt | 1000000 | 150000 | No | 0.978334  | ✅ Pass |

### Complexity

| Algorithm | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| GEMM (Simple) | O(M × K × N) | O(M × N) |
| GEMM (Blocking) | O(M × K × N) | O(M × N) |
| CSR Conversion | O(V + E) | O(V + E) |

## LINK
[github](https://github.com/2026csm1034-cell/CS509_2026csm1034)


# Assignment_02

This Assignment Consist of implimenting bellman Ford and floyd Warshall Algorithm

## Language and Environment

- Language: C++
- Compiler: g++  (Rev3, Built by MSYS2 project) 13.2.0
- OS: Apple clang version 21.0.0 (clang-2100.1.1.101)
- Compile flags used: `-std=c++17`
- Timing method: `chrono::high_resolution_clock`, wall-clock duration in
  milliseconds


## Directory Structure

```text
Assignment_02
    driver/
        driver.cpp
        driver.h
    src/
        bellman_ford/
            bellman_ford.cpp
            bellman_ford.h
        floyd_warshall/
            floyd_warshall.cpp
            floyd_warshall.h
    tests/
        bellman_ford/
            bf_10.txt
            bf_100.txt
            ...
        floyd_warshal/
            fw_10.txt
            fw_100.txt
    outputs/
        bellman_ford
        floyd_warshall
common_wrapper/
    similar to previous structure
tools/
    bellmanFord_generator.cpp
    floydWarshall_generator.cpp
Makefile
```

## Formate of input output

### Bellman Ford input file 
    The graph is directed. Each neighbour is followed by its edge weight, which may be negative.
    V E
    u0 degree neighbor1 weight1 neighbor2 weight2 ...
    u1 degree neighbor1 weight1 neighbor2 weight2 ...
    ...
    u(V-1) degree neighbor1 weight1 neighbor2 weight2 ...
    SOURCE s
    V: number of vertices. E: number of directed edges.
    For a vertex with no outgoing edges, write: u 0.
    s: source vertex for Bellman-Ford.
### output formate 
    Algorithm: Bellman-Ford
    Source: 0
    Vertex Distance
    0      0
    1      2
    2      4
    3      7
    4      -2
    Negative cycle: none
    Execution time: <value> ms

### Floyd Warshall Input File
    Floyd-Warshall reads a dense V x V matrix instead of an adjacency list. Use INF to mark a pair with no direct edge, and 0 on the diagonal.
    V
    row 0 values
    row 1 values
    ...
    row (V-1) values
    Each row has exactly V space-separated entries: an integer weight, or the literal token INF.
    Entry (i, j) is the weight of the direct edge from i to j, or INF if no such edge exists. Entry (i, i) must be 0.

### output Formate
    Algorithm: Floyd-Warshall
    Distance matrix:
    0  1  -3  2  -4
    3  0  -4  1  -1
    7  4  0   5  3
    2  -1 -5  0  -2
    8  5  1   6  0
    Negative cycle: none
    Execution time: <value> ms

## Compilation
    '''zsh
        make
    '''

## Execution 
    ./cs509


## Bellman-Ford / Floyd-Warshall Results Table
| Algorithm | Test File | Vertices | Edges | Source | Negative Cycle | Expected Output | Actual Output | Time(ms) | Status |
|----------|---------|---------|--------|----------|------------|----------------|--------------|------------|------------|
|Bellman Ford | bf_10.txt | 10 | 30 | 5 | No | Distances | Distances | 0.002208 ms | passed |
|Bellman Ford | bf_100.txt | 100 | 300 | 5 | No | Distances | Distances | 0.012041 ms | passed |
|Bellman Ford | bf_10000.txt | 10000 | 30000 | 0 | Yes | Distances | Distances | 504.726 ms | passed |
|Bellman Ford | bf_50000.txt | 50000 | 150000 | 0 | Yes | Distances | Distances | 16913 ms | passed |
|Bellman Ford | bf_100000.txt | 100000 | 150000 | 0 | Yes | Distances | Distances | 75932.7 ms | passed |

|Floyd Warshall | fw_10.txt | 10 | 30 | 5 | No | Distances | Distances | 0.017542 ms | passed |
|Floyd Warshall | fw_100.txt | 100 | 300 | 5 | No | Distances | Distances | 1.56771 ms | passed |
|Floyd Warshall | fw_10000.txt | 1000 | - | 0 | True | Distances | Distances | 380.423 ms | passed |
|Floyd Warshall | fw_50000.txt | 500 | - | 0 | True | Distances | Distances | 48.708 ms | passed |
|Floyd Warshall | fw_100000.txt | 2000 |  | 0 | True | Distances | Distances | 2999.98 ms | passed |

## check the integrity of the algorithm on test case 10 and 100.
Run the belman ford on source 5 on graph the output is 0 -3
1 14
2 12
3 5
4 12
5 0
6 17
7 3
8 2
9 17
on the same node i saw the value on ouput generated by floyd warshall it shows the same distance matrix. so we can say that it running correctly.

similiar for 100 size input with source 4 and ouput correspoding to 4 in floyd warshall matrix is same


