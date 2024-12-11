# generate parser
`antlr4 -Dlanguage=Cpp -o parser Expr.g4`

# set include and lib directory
`g++ -std=c++17 main.cpp parser/Expr*.cpp -I/opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/include/antlr4-runtime -L/opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/lib -lantlr4-runtime -o main`

`/opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/include/antlr4-runtime` and `/opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/lib` should be replaced by antlr4 include and lib directory in your own environment
