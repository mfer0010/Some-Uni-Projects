#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//Global signal handler
void signal_handler(int sig) {
	printf("signal handler() has gained control\n");
}

int main (int argc, char * argv[]) {
	struct sigaction sigact;
	sigset_t sigset;

	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigact.sa_handler = signal_handler;
	sigaction(SIGUSR1, &sigact, NULL);


	printf("Before first kill()\n");
	kill(getpid(), SIGUSR1); //send signal
	//set signal set here
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1); //add siguser1 to sigset
	//Block here
	sigprocmask(SIG_SETMASK, &sigset, NULL); //block all signals in sigset from interrupting
	

	printf("Before second kill()\n");
	//int kill(pid_t pid, int sig)
	kill(getpid(), SIGUSR1);
	printf("After second kill()\n");

	sleep(2);
	printf("After Sleep\n");
	//Unblock here
	sigprocmask(SIG_UNBLOCK, &sigset, NULL);
	printf("After unblocking signal\n");

	return 0;
}