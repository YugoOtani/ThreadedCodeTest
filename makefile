baseline: baseline.cpp
	g++ -O2 -std=c++17 -o baseline baseline.cpp

token: token.cpp
	g++ -O2 -std=c++17 -o token token.cpp

call: call.s call_exec.s
	g++ -O2 -std=c++17 -o call call.s call_exec.s

call.s: call.cpp
	g++ -O2 -std=c++17 -S call.cpp

call_exec.s: call.s gen_call_asm
	./gen_call_asm 

gen_call_asm: gen_call_asm.cpp
	g++ -O2 -std=c++17 -o gen_call_asm gen_call_asm.cpp

execution: execution_time.cpp
	g++ -std=c++17 -o execution execution_time.cpp -I/opt/homebrew/opt/llvm/include -L/opt/homebrew/opt/llvm/lib -mmacosx-version-min=13.6 /opt/homebrew/opt/llvm/lib/liblldb.dylib

stepi: execution
	./execution

run: main
	./main 

clean:
	rm -f baseline token call call.s