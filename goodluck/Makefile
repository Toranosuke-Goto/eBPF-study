TARGETS = goodluck goodluck_fix
BPF_OBJS := $(addsuffix .bpf.o,$(TARGETS))

all: $(TARGETS)
.PHONY: all clean

%.bpf.o: %.bpf.c
	clang -target bpf \
	  -I/usr/include/$(shell uname -m)-linux-gnu \
	  -I/usr/include \
	  -g -O2 -c $< -o $@

clean: 
	- rm *.bpf.o
	- rm -f /sys/fs/bpf/goodluck 
	- rm -f /sys/fs/bpf/goodluck_fix
