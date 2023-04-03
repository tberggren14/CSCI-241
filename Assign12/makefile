#
# PROGRAM:    Assignment 12
# PROGRAMMER: Trevor Berggren
# LOGON ID:   z1906236
# DATE DUE:   04/22/2021
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
all: assign12

assign12: assign12.o shape.o rectangle.o circle.o triangle.o
	$(CXX)  $(CXXFLAGS) -o  assign12    $^

# Rules to compile source code files to object code
assign12.o: assign12.cpp
shape.o: shape.h shape.cpp
rectangle.o: rectangle.h rectangle.cpp
circle.o: circle.h circle.cpp
triangle.o: triangle.h triangle.cpp

# Pseudo-target to remove object code and executable files
clean:
	rm -f *.o assign12
