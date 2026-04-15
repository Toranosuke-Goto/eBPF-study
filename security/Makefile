TARGET = Security
ARCH = $(shell uname -m | sed 's/x86_64/x86' | sed 's/arrch64/arm64/')

BPF_OBJ = ${TARGET:=.bpf.o}



%.bpf.o: %.bpf.c
        clang -target bpf \
          -I/usr/include/$(shell uname -m)-linux-gnu \
          -I/usr/include \
          -g -O2 -c $< -o $@
