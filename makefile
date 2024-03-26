# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++20 -Wall -Wextra -O3

# Target executables
TARGETS = lab1 lab2 lab3 lab4 lab5

# Default target: show instructions
all:
	@echo "Use 'make <target>' to build and run a specific lab."
	@echo "Available targets: $(TARGETS)"

# Rule to build and run lab1
lab1: src/lab1_dfa.cpp
	$(CC) $(CFLAGS) $< -o $@
	./$@
	rm -f $@

# Rule to build and run lab2
lab2: src/lab2_moore.cpp
	$(CC) $(CFLAGS) $< -o $@
	./$@
	rm -f $@

# Rule to build and run lab3
lab3: src/lab3_mealy.cpp
	$(CC) $(CFLAGS) $< -o $@
	./$@
	rm -f $@

# Rule to build and run lab4
lab4: src/lab4_nfa_to_dfa.cpp
	$(CC) $(CFLAGS) $< -o $@
	./$@
	rm -f $@

# Rule to build and run lab5
lab5: src/lab5_first_follow.cpp
	$(CC) $(CFLAGS) $< -o $@ -lfmt
	./$@
	rm -f $@

# Clean target
clean:
	rm -f $(TARGETS)

.PHONY: all clean $(TARGETS)