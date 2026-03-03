TARGETS = goodluck goodluck_fix

all: $(TARGETS)
.PHONY: all

$(TARGETS): %: %.bpf.o 

%.bpf.o: %.c
	clang \
	    -target bpf \
		-I/usr/include/$(shell uname -m)-linux-gnu \
		-g \
	    -O2 -o $@ -c $<

clean: 
	- rm *.bpf.o
	- rm -f /sys/fs/bpf/goodluck 
	- rm -f /sys/fs/bpf/goodluck_fix
