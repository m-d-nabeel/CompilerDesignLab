# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++20 -Wall -Wextra -O3

# Targets
.PHONY: all clean

# Default target: build all programs
all: lab1 lab2 lab3 lab4

# Target for compiling and running lab1
lab1: src/lab1_dfa.cpp
	$(CC) $(CFLAGS) $^ -o $@
	./$@

# Target for compiling and running lab2
lab2: src/lab2_moore.cpp
	$(CC) $(CFLAGS) $^ -o $@
	./$@

# Target for compiling and running lab3
lab3: src/lab3_mealy.cpp
	$(CC) $(CFLAGS) $^ -o $@
	./$@

# Target for compiling and running lab4
lab4: src/lab4_nfa_to_dfa.cpp
	$(CC) $(CFLAGS) $^ -o $@
	./$@

# Target for cleaning up built files
clean:
	rm -f lab1 lab2 lab3 lab4
