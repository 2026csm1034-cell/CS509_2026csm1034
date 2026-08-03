CXX = g++

CXXFLAGS = -std=c++17 -Wall -O2

TARGET = cs509

SRC = \
./common_wrapper/main.cpp \
./common_wrapper/menu.cpp \
./assignment_01/driver/driver.cpp \
./assignment_01/src/gemm/simple_gemm.cpp \
./assignment_01/src/gemm/blocking_gemm.cpp \
./assignment_01/src/csr/generate_CSR.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# run:
# 	./$(TARGET)

clean:
	rm -f $(TARGET)