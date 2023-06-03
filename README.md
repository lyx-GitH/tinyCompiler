# Tiny Compiler
## Requiments
- cmake
- flex
- llvm

## How to run
- run ```run.sh``` and it would do the rest of the work.

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

This compiler supports ***almost*** all common C89 features, ***except***
- ***define*** statements, as well as ```#ifdef``` ```#endif``` etc.
- Bit field in struct
- complex initializer list, like: ```{.x =100, .y=200}```
- mem-related qualifiers, like ```static```, ```extern```, ```register``` etc.

This compiler ***especially supports***
- include statement
- initializer list, like ```int a[] = {1, 2, 3}```
- function pointers as arguments
- constant-type assignment checks