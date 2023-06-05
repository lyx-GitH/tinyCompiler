# Tiny Compiler
## Requiments
- cmake
- flex
- llvm

## How to run
- run ```run.sh``` and it would do the rest of the work.

## NOTICE
**Those bizzare template functions in ./types/typefactory.h have meen mostly abandoned, since they cause countless bugs**
(They are previously desiged to do const-type checks)

## Features
### What do TinyCompiler ***NOT*** support?
This compiler supports ***almost*** all common C89 features, ***except***
- ***define*** statements, as well as ```#ifdef``` ```#endif``` etc.
- Bit field in struct
- complex initializer list, like: ```{.x =100, .y=200}```
- mem-related qualifiers, like ```static```, ```extern```, ```register``` etc.
- type names longer than two tokens, like ```long long``` or ```unsigned char```

Also, please be aware that up to now, the initilazation of constants are still limited,both inline and in init-list.  such as:
```C
const int a = 5;
const int b = a;
```
An error would occur in ***tinyCompiler***, reporting that ```a``` is not a constant.
Please be aware again that this compiler only supports declaring variables at the front of the scope. This code would cause syntax error:
```C
int main() {
    printf("hello");
    int a = 5; // cause syntax error
}
```

### What do TinyCompiler support?
1. type names: ```void``` ```char``` ```short``` ```int``` ```long``` ```float``` ```double```, planning to add simple C++ style `auto` support
2. complex type parsing, arrays, pointers or even  ```const char* (*f[10])(int, double)```
3. control statements: ```if-else``` ```switch```(this implementation is really a mess!) ```continue``` ```break``` ```goto```(unmature)
4. iteration statements: ```while``` ```do-while``` ```for```
---
## About the project
This project is under-construction. It contains (at least) these parts:
- lexer
- AST generator
- RV64(or arm) assembly generator
- AST visulizer
### About: *lexer*
- The lexer converts a file into token streams
- The basic frameworks are completed. Yet the grammar rools in ```lexer.l``` is not completed
- To add a rule, you need to
    - define a rule in ```lexer.l```
    - if a new token is needed, go to ```tokens.h``` to add one
    - remember to follow the coding styles!

### About: *parser*
The parser converts the program into a ast
The parser can now do:
- expressions
- types(including compilcated ones)
  

### About *AST*
The syntax tree. inherited from the well-known ZJU project called *miniSQL*

### About *visualizer*
This part can Visualize a ast in Type of ```dot``` language. Also inherited from *miniSQL*

## What can TinyCompiler Do?

as I mentioned before, This compiler supports ***almost*** all common C89 features, ***except***
- ***define*** statements, as well as ```#ifdef``` ```#endif``` etc.
- Bit field in struct
- complex initializer list, like: ```{.x =100, .y=200}```
- mem-related qualifiers, like ```static```, ```extern```, ```register``` etc.

This compiler ***especially supports***
- include statement
- initializer list, like ```int a[] = {1, 2, 3}```
- function pointers as arguments
- constant-type assignment checks
