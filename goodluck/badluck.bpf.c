BPF_PERF_OUTPUT(study);

struct data_t{
	int pid;
	int uid;
	char command[16];
	char message[15];
};

int good(void *ctx) {
	struct data_t data ={};
	char message[10] = "Good Look";

	data.pid = bpf_get_current_pid_tgid() >> 32;
	data.uid = bpf_get_current_uid_tgid() & 0xFFFFFFFF;

	bpf_get_current_pid_comm(&data.command, sizeof(data.command));
	bpf_get_current_uid_kernel(&data.massage, sizeof(data.message), message);

	study.perf_submit(ctx, &data, sizeof(data));

	return 0;
}
