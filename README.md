# dfa-simulation

[//]: # (### Deterministic Finite Automaton Simulator C++)

### Requirements
* a modern C++17 compiler (`gcc-8`, `clang-6.0`, `MSVC 2017` or above)
* [`cmake`](https://cmake.org) 3.15+

### How to build from command line

```shell
  g++ run.cpp -o run
```

```shell
  ./run 
```

### How to run tests

```shell
  bash run_tester
```


### input / output syntax 

#### A word is described like: 

> The language exclusively consists of lowercase Latin letters.
>
> The first line of the input consists a string containing lowercase Latin letters.

#### A deterministic finite automaton M is described like: 

> The second line of the input consists of three space-separated numbers: 'n,' 'a,' and 't.' These numbers respectively
> represent the total number of states, the number of accepting states, and the total number of transitions in the
> finite
> automaton. It's important to note that states are numbered starting from 0, with state 0 always designated as the
> initial state.

> The third line contains 'a' numbers, which represent the indexes of the accepting states. In other words, there are '
> a' values listed on the second line, each indicating the index of an accepting state.

> Following this, each subsequent line describes the transitions within the finite automaton. Each of these lines begins
> with a number 'k<sub>i</sub>,' indicating the number of transitions originating from state 'i.' After 'k<sub>i</sub>,'
> pairs of two numbers
> are provided, each pair consisting of a symbol and the target state to which the automaton transitions from state 'i'
> using that symbol.


#### input example:

```
    abbc1acabbbbc001cabc
    3 2 6
    0 2
    1 a 1
    2 b 1 c 2
    3 0 2 1 2 a 1
```

#### output example:

```
    NNNYYNYNNNNNYYYYNNNN
```

#### More examples:
> More inputs are given in /Public tests/P2/in with correct outputs in /Public tests/P2/out

