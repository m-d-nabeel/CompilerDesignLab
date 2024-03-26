# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++20 -Wall -Wextra -O3

# Targets
.PHONY: all clean

# Default target: build all programs
all: run_lab1 run_lab2 run_lab3 run_lab4 run_lab5

# Target for compiling and running lab1
lab1: src/lab1_dfa.cpp
	$(CC) $(CFLAGS) $^ -o $@

# Target for compiling and running lab2
lab2: src/lab2_moore.cpp
	$(CC) $(CFLAGS) $^ -o $@

# Target for compiling and running lab3
lab3: src/lab3_mealy.cpp
	$(CC) $(CFLAGS) $^ -o $@

# Target for compiling and running lab4
lab4: src/lab4_nfa_to_dfa.cpp
	$(CC) $(CFLAGS) $^ -o $@

# Target for compiling and running lab5
lab5: src/lab5_first_follow.cpp
	$(CC) $(CFLAGS) $^ -o $@ -lfmt

# Target for cleaning up built files
clean:
	rm -f lab1 lab2 lab3 lab4 lab5


# Define a rule to run each lab if it has been modified
run_lab%: lab%
	./$<

# Run the lab if the source file is newer than the executable
lab%: src/lab%_dfa.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab%: src/lab%_moore.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab%: src/lab%_mealy.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab%: src/lab%_nfa_to_dfa.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab%: src/lab%_first_follow.cpp
	$(CC) $(CFLAGS) $^ -o $@ -lfmt