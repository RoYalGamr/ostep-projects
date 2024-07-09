#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[]){
	FILE *stream ;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread ;
	if (argc ==1){
		printf("wgrep: searchterm [file ...]\n");
		exit(EXIT_FAILURE);
	}else if (argc == 2){
		stream = stdin;
		if (stream == NULL){
			printf("wgrep: cannot open file\n");
			exit(EXIT_FAILURE);
		}
		while ((nread = getline(&line, &len, stream)) != -1) {
			if (strstr(line,argv[1])!= NULL){
				printf("%s",line);
			}
		}

	}else{
		for(int i=2;i<argc;i++){
			stream = fopen(argv[i],"r");
			if (stream == NULL){
				printf("wgrep: cannot open file\n");
				exit(EXIT_FAILURE);
			}
			while ((nread = getline(&line, &len, stream)) != -1) {
				if (strstr(line,argv[1])!= NULL){
					printf("%s",line);
				}
			}
		}
	}
	free(line);
	return 0;
}



