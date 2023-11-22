#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void intHandler();
void intHandler2();

int main(){
	int password = 123;
	int correct = 0;
        
	signal(SIGALRM, intHandler);
	signal(SIGINT, intHandler2);
        alarm(10);

	while(!correct){
		if(getchar() == '1'){
			if(getchar() == '2'){
				if(getchar() == '3'){
					if(getchar() == '\n'){
						correct = 1;
					}
				}
			}
		}
	}
	printf("Correct!\n");

		

}

void intHandler(int signo){
        printf("Fire!\n");
        exit(0);
}

void intHandler2(int signo){
	printf("10 sec reset...\n");
	alarm(10);
}
