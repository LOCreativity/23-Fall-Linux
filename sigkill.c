#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void intHandler(int signo);
void intHandler2(int signo);
void intHandler3(int signo);
void print_gugu(){
	for(int i = 1; i <= 20; i++){
                for(int j = 1; j < 20; j++){
                        printf("%d x %d = %d\n", i, j, i*j);
                }
		if (i >= 9)
			signal(SIGINT, intHandler3);
                sleep(1);
        }
}
int child_id;
int main(){
	int pid;
	int signo;

	if ((pid == fork()) == 0){ // 자식 프로세스
		signal(SIGINT, intHandler2);
		print_gugu();
		pause();
	}else{ // 부모 프로세스
		child_id = pid;
		signal(SIGINT, intHandler);
		wait();
	}

	return 0;
}

void intHandler(int signo){
	kill(child_id, SIGINT);
}

void intHandler2(int signo){
	printf("cannot terminate...\n");
}

void intHandler3(int signo){
	kill(-getppid(), SIGKILL);
}
