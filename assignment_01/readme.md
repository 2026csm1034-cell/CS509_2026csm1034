# CS509 Assignment 1

## Algorithms

- Simple GEMM
- Blocking GEMM
- weighted CSR
- unweighted CSR

--> All the element is integer if there is over flow then it is a modulo of 1e^7 + 9;
---

## Compile

make

---

## Run

./cs509

---

## Folder Structure

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

---

## Timing

Execution time measures ONLY the algorithm.

File reading

Parsing

CSR conversion

Output writing


---

## GEMM Results

Output : path_of_output_files.txt

Expected Time:   abc ms

---

## CSR Tests

| Test File | Vertices | Edges |
|------------|----------|-------|
| graph_10 | 10 | 12 |