cmake_minimum_required(VERSION 3.19)
project(DataStructure)

set(CMAKE_CXX_STANDARD 11)

#add_executable(DataStructure main.cpp Graph/main.cpp Graph/graph.h)


add_executable(sum Stack/sum.cpp)
add_executable(ReversePolishNotaion Stack/ReversePolishNotaion.cpp)
add_executable(Tree Tree/Tree.cpp)
add_executable(List matri.cpp)
add_executable(InorderThread Tree/InorderThread.cpp)
add_executable(Hafuman Tree/huffTree.cpp)
add_executable(huffTree Tree/huffTree.cpp)
add_executable(Sort Sort/Sort.cpp Sort/Sort.h)
add_executable(Graph Graph/Graph.cpp)
add_executable(main Search/main.cpp Search/Search.h)
add_executable(Main Test/Test.cpp)
add_executable(a Test/a.cpp)
add_executable(Test Test.cpp)
add_executable(test1 test1.cpp)