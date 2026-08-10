CXX = g++

CXXFLAGS = -std=c++17 -Wall -O2

TARGET = cs509

SRC = \
./common_wrapper/main.cpp \
./common_wrapper/menu.cpp \
./assignment_01/driver/driver.cpp \
./assignment_01/src/gemm/simple_gemm.cpp \
./assignment_01/src/gemm/blocking_gemm.cpp \
./assignment_01/src/csr/csr.cpp \
./assignment_01/src/graph_io/graph_io.cpp \
./assignment_02/driver/driver.cpp \
./assignment_02/src/bellman_ford/bellman_ford.cpp \
./assignment_02/src/floyd_warshall/floyd_warshall.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# run:
# 	./$(TARGET)

clean:
	rm -f $(TARGET)