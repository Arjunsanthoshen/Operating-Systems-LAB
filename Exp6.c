#include<stdio.h>
#include<stdlib.h>
int mutex = 1, full = 0, empty, Buffer_Size, x=0, in=0, out = 0;

int wait(int s){
	return --s;
}

int signal(int s){
	return ++s;
}

void producer(int buffer[]){
	empty = wait(empty);
	mutex = wait(mutex);
	buffer[in] = ++x;
	printf("Producer produces item %d\n",x);
	in = (in + 1) % Buffer_Size;
	mutex = signal(mutex);
	full = signal(full);
}

void consumer(int buffer[]){
	full = wait(full);
	mutex = wait(mutex);
	printf("Consumer consumes item %d\n",buffer[out]);
	out = (out + 1) % Buffer_Size;
	mutex = signal(mutex);
	empty = signal(empty);
}

int main(){
	printf("Enter size of buffer: ");
	scanf("%d",&Buffer_Size);
	int buffer[Buffer_Size];
	empty = Buffer_Size;
	int choice;
	printf("\tMENU\n1) PRODUCE\n2) CONSUME\n3) EXIT\n");
	while(1){
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if(mutex == 1 && empty != 0)
					producer(buffer);
				else
					printf("Buffer is full!!\n");
				break;

			case 2:
				if(mutex == 1 && full != 0)
					consumer(buffer);
				else
					printf("Buffer is empty!!!\n");
				break;

			case 3:
				printf("Exiting...\n");
				exit(0);
				break;
			default:
				printf("Invalid choice.\n");
		}

	}
}