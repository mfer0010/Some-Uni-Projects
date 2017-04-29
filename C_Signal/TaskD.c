#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal);
void handle_sigalrm(int signal);
void do_sleep(int seconds);

int main() {
	struct sigaction sa;

	printf("My pid is: %d\n", getpid());

	//Setup the sighub handler
	sa.sa_handler = &handle_signal;

	//Restart the system call, if at all possible
	sa.sa_flags = SA_RESTART;

	//Block every signal during the handler
	sigfillset(&sa.sa_mask);

	//HINT: Signal handler conditions here using sigaction()
	if (sigaction(SIGHUP, &sa, NULL) == -1)
        perror("Error: cannot handle SIGHUP"); // Should not happen

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        perror("Error: cannot handle SIGUSR1"); // Should not happen

    if (sigaction(SIGINT, &sa, NULL) == -1)
    	perror("Error: cannot handle SIGINT");

	while (1) {
		printf("Sleeping for 3 seconds\n");
		do_sleep(3); //Later to be replaced with a SIGALRM
	}
}

//Generic signal handler
void handle_signal(int signal) {
	/*
	 * Please note that printf et al. are NOT safe to use in signal handlers
	 * Look for async safe functions
	 */
	const char *signal_name;
	sigset_t pending;

	//Find out which signal we're handling
	//don't forget to handle SIGINT signal appropriately
	switch (signal) 
    {
        case SIGHUP:
            signal_name = "SIGHUP";
            break;
        case SIGUSR1:
            signal_name = "SIGUSR1";
            break;
        case SIGINT:
            signal_name = "SIGINT";
            break;
        default:
            fprintf(stderr, "Caught wrong signal: %d\n", signal);
            return;
    }


	printf("Caught %s sleeping for 3 seconds\n"
		   "Try sending another SIGHUP / SIGINT / SIGALRM"
		   "(or more) meanwhile\n", signal_name);

	do_sleep(3);
	printf("Done sleeping for %s\n", signal_name);

	//So what did you send me while I was asleep?
	//Use sigpending and sigismember to get the list of signals waiting to be handled
	sigpending(&pending);
    if (sigismember(&pending, SIGHUP))
        printf("A SIGHUP is waiting\n");

    if (sigismember(&pending, SIGUSR1))
        printf("A SIGUSR1 is waiting\n");

    if (sigismember(&pending, SIGINT))
        printf("A SIGINT is waiting\n");

	printf("Done handling %s\n\n", signal_name);
}

//SIGALRM signal handler
void handle_sigalrm(int signal) {
	if (signal != SIGALRM)
		fprintf(stderr, "Caught wrong signal: %d\n", signal);

	printf("Got sigalrm, do_sleep() will end\n");
}

//Function to go to sleep
void do_sleep(int seconds) {
	struct sigaction sa;
	sigset_t mask;

	sa.sa_handler = &handle_sigalrm; //intercept and ignore SIGALRM
	sa.sa_flags = SA_RESETHAND; //Remove the handler after first signal
	sigfillset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, NULL);

	//Get the current signal mask
	sigprocmask(0, NULL, &mask);

	//Unblock SIGALRM
	sigdelset(&mask, SIGALRM);

	//Wait with this mask
	alarm(seconds);
	sigsuspend(&mask);

	printf("sigsuspend() returned\n");
}