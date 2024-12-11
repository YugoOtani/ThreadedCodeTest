CC = g++
CFLAGS = -std=c++17 -I/opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/include/antlr4-runtime -L/opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/lib -lantlr4-runtime
SRCS = parser/*.cpp ast.cpp

.PHONY: all clean

main: $(SRCS) main.cpp 
	mkdir -p ../bytecode
	$(CC) $(CFLAGS) $(SRCS) -o main main.cpp
run : main
	./main ../bytecode/input2.txt

clean:
	rm -rf $(OBJ_DIR) main
