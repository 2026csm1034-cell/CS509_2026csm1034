#ifndef GEMM_H
#define GEMM_H

#include <fstream>
#include "../../../common_wrapper/utilities.h"
using namespace std;
void simple_gemm(const string &filename);
void blocking_gemm(const string&filename, int block_size);

#endif // GEMM_H