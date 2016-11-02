#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void fileSizer(long bytes){
	printf("File Size: ");
	long workbytes = bytes;
	if (bytes > 1024 * 1024 * 1024){
		printf("%li gigabytes, ", workbytes>>30);
		workbytes = workbytes%1024;
	}
	if (bytes > 1024 * 1024){
		printf("%li megabytes, ", workbytes>>20);
		workbytes = workbytes%1024;
	}
	if (bytes > 1024){
		printf("%li kilobytes, ", workbytes>>10);
		workbytes = workbytes%1024;
	}
	printf("%li bytes\n", workbytes);
}

int main(){
	printf("Statistics for Directory: \n\n");

	struct stat buffer;
	int debug; //= stat("..", &buffer);

	//while ()

	long total;

	struct dirent *pdirent;
	DIR *pDir;
	pDir = opendir(".");
	if (pDir)
	{
		printf("Directories: \n------------\n");
		while ((pdirent = readdir(pDir)) != NULL)
		{
			if (pdirent->d_type == 4){
				printf("%s\n", pdirent->d_name);
				debug = stat(pdirent->d_name, &buffer);
				total += buffer.st_size;
			}
		}
		printf("\n");
		pDir = opendir(".");
		printf("Files: \n------\n");
		while ((pdirent = readdir(pDir)) != NULL)
		{
			if (pdirent->d_type == 8){
				printf("%s\n", pdirent->d_name);
				debug = stat(pdirent->d_name, &buffer);
				total += buffer.st_size;
			}
		}

		closedir(pDir);
	}
	fileSizer(total);
	return(0);
}