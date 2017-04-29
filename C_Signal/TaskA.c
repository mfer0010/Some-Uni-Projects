#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//Global signal handler
void signal_handler (int sig) {
	if (sig == SIGCONT)
		printf("Nice_try...\n");
	else 
		printf("Received signal %d which shouldn't be handled by this handler\n", sig);
}

int main() {
	int i = 0;
	int seconds = 5;

	if(signal(SIGCONT, signal_handler) == SIG_ERR) {
		fprintf(stderr, "Can't catch SIGINT\n");
	}

	while (1) {
		printf("Iteration No %d\n", i++);
		int remaining = seconds;

		do {
			int ret = sleep(remaining);
			remaining = (ret == 0) ? 0 : remaining - ret;
		} while (remaining > 0);
	}
}