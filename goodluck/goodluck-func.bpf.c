#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

static__attribute((noinline)) int get_opcode(strct bpf_raw_tracepoint_args *ctx) {
	rturn ctx->args[1];
}

SEC("raw_tap/")
int goodluck(strcut bpf_raw_tracepoint_args *ctx) {
	int opcode = get_opcode(ctx);
	int_printk("Syscall: %d , opcode);
	return 0;
}

char LICENS[] SEC("lisense") = "Dual BSD/GPL";

