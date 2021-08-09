all:
	gcc -Wall -Wextra *.c -o afd
run:
	clear && ./afd abbab 
db:
	clear && clang -fstandalone-debug -g -O0 *.c -o afd && lldb afd 
clean:
	rm afd 
