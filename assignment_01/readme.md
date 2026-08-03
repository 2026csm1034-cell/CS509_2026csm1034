# CS509 Assignment 1

## Algorithms

- Simple GEMM
- Blocking GEMM
- CSR Representation

---

## Compile

make

---

## Run

make run

---

## Folder Structure

common_wrapper/

assignment_01/

tests/

outputs/

---

## Timing

Execution time measures ONLY the algorithm.

File reading

Parsing

CSR conversion

Output writing

are NOT included.

---

## GEMM Results

| Test File | Size | Simple | Blocking | Block Size |
|-----------|------|---------|-----------|------------|
| gemm_test_01 | 2x3 × 3x2 | | | |
| gemm_test_02 | 3x3 × 3x3 | | | |
| gemm_test_03 | 4x4 × 4x4 | | | |

---

## CSR Tests

| Test File | Vertices | Edges |
|------------|----------|-------|
| graph_10 | 10 | 12 |