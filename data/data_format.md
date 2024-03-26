# DFA Lab 1

This lab covers various concepts related to finite automata, including deterministic finite automata (DFA), Mealy machines, Moore machines, conversion from non-deterministic finite automata (NFA) to DFA, and first & follow in context-free grammars.

## Initial State, Final States, Transition Table

The transition table represents the behavior of a DFA, where each row corresponds to a state, and each column corresponds to an input symbol. The entries in the table indicate the next state to transition to for a given current state and input symbol.

### Example 1:

```

0
1
0 1 -1
-1 2 3
-1 -1 -1

```

### Example 2:

```

0
1 2 3
1 0 -1
-1 2 -1
-1 -1 3
-1 -1 -1

```

### Example 3:

```

0
1 2
1 -1
1 2
2 -1

```

## Mealy Machine

A Mealy machine is a type of finite state machine where the output depends on both the current state and the input symbol. The output is produced as the machine transitions from one state to another.

### Example 1:

```

0
1 2 3
1,s 0,w -1
-1 2, f -1
-1 -1 3,x
-1 -1 -1

```

### Example 2:

```

0
1
0,a 1,b -1
-1 2,c 2,d
-1 -1 -1

```

### Example 3:

```

0
1 2 3
1,x 2,x
1,y 3,z
3,z 2,x
3,z 3,y

```

## Moore Machine

In a Moore machine, the output depends only on the current state, regardless of the input symbol. The output is produced while the machine is in a particular state.

### Example 1:

```

0
1 2 3
1 2 w
1 3 x
3 2 y
3 3 z

```

### Example 2:

```

0
1 2 3
1 0 -1 s
-1 2 -1 f
-1 -1 3 x
-1 -1 -1

```

### Example 3:

```

0
1
0 1 -1 a
-1 2 2 b
-1 -1 -1

```

## NFA to DFA

This section demonstrates examples of converting a non-deterministic finite automaton (NFA) to an equivalent deterministic finite automaton (DFA).

### Example 1:

```

0
2
0,1 0
-1 2
-1 -1

```

### Example 2:

```

0
2
0 1,2
1,2 2
0,1 1

```

### Example 3:

```

0
1
1,2 -1
-1 -1
1,2 2

```

### Example 4:

```

0
2
0 0,1
1,2 1
-1 0

```

### Example 5:

```

0
2
0 0,1
2 2

```

### Example 6:

```

0
2
0,1 2
0 1
-1 0,1

```

## First & Follow

This section illustrates an example of finding the first and follow sets for a given context-free grammar.

### Example 1:

```

E -> TX
X -> +TX | E
T -> FY
Y -> FY | ε
F -> (E) | id

```

### Example 1:

```

A -> BC
C -> +BC | A
B -> DE
E -> DE | ε
D -> (A) | id
D -> + | A

```

In this example, the grammar rules are provided, and the task is to determine the first and follow sets for each non-terminal symbol.
