// C program to implement one side of FIFO 
// This side writes first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd; 

	// FIFO file path 
	char * myfifo = "./mypipe"; 

	char arr1[80]; 
	while (1) 
	{ 
		// Open FIFO for write only 
		fd = open(myfifo, O_WRONLY); 

		// Take an input arr2ing from user. 
		// 80 is maximum length 
		fgets(arr1, 80, stdin); 

		// Write the input arr2ing on FIFO 
		// and close it 
		write(fd, arr1, strlen(arr1)+1); 
		close(fd); 
	} 
	return 0; 
} 
