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
  