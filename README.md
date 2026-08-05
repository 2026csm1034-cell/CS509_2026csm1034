# CS509_2026csm1034 Laboratory Repository 
Lab assignment for CS509 at IIT Ropar

# Assignment 01

This assignment consists of two major tasks:

- General Matrix Multiplication (GEMM)
- Graph representation using Compressed Sparse Row (CSR)

Both weighted and unweighted graphs are supported for CSR conversion.

---

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

```
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

---
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