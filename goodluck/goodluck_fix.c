BPF_PERF_OUTPUT(study);

	struct data_t{
	u32 pid;
	u32 uid;
	char command[16];
	char message[15];
};

int good(void *ctx) {
	struct data_t data = {};
	char message[15] = "Good Luck";

	data.pid = (u32)(bpf_get_current_pid_tgid() >> 32);
	data.uid = (u32)bpf_get_current_uid_tgid();

	bpf_get_current_comm(&data.command, sizeof(data.command));
	__builtin_memcpy(&data.message, msg, sizeof(data.message));

	study.perf_submit(ctx,&data, sizeof(data));

	return 0;
}
