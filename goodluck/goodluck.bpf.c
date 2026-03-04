#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

int counter = 0;

SEC("xdp")
int goodluck(struct xdp_md *ctx) {
	bpf_printk("Good luck %d", counter);
	counter++;
	return XDP_PASS;
}

char LICENSE[] SEC("license") = "Dual BSD/GPL";
