baseline: baseline.cpp
	g++ -g -O0 -std=c++17 -o baseline baseline.cpp

threaded: threaded.cpp
	g++ -g -O0 -std=c++17 -o threaded threaded.cpp

call: call.s call_exec.s
	g++ -g -O0 -std=c++17 -o call call.s call_exec.s

call.s: call.cpp
	g++ -g -O0 -std=c++17 -S call.cpp

call_exec.s: call.s gen_call_asm
	./gen_call_asm 

gen_call_asm: gen_call_asm.cpp
	g++ -O0 -std=c++17 -o gen_call_asm gen_call_asm.cpp

execution: execution_time.cpp
	g++ -g -std=c++17 -o execution execution_time.cpp -I/opt/homebrew/opt/llvm/include -L/opt/homebrew/opt/llvm/lib -mmacosx-version-min=13.6 /opt/homebrew/opt/llvm/lib/liblldb.dylib

stepi: execution
	./execution

run: main
	./main 

clean:
	rm -f baseline threaded  