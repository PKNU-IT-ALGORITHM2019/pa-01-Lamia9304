#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX 352300
#define CMD_SIZE 2500


int main() {

	/*char str[] = "now is the new bus";
	char delim[] = " ";
	char *token;

	token = strtok(str, delim);

	while (token != NULL) {
		printf("next token is: %s %d\n", token, strlen(token));
		token = strtok(NULL, delim);
	}*/

	/*char data[MAX];



	FILE *fp = fopen("dict.txt", "w");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}

	int i = 0;

	while ((fscanf(fp, "%s", &data[i]) != EOF)) {
		fscanf(fp, "%s", &data[i]);
		i++;
	}

	for (int i = 0; i < MAX; i++) {
		printf("%s\n", data[i]);
	}

	fclose(fp);*/

}

void process_command() {
	char command_line[CMD_SIZE];
	char *command, *cmd;

	while (1) {
		printf("$: ");

		if (read_line(command_line, CMD_SIZE) <= 0)
			continue;
		command = strtok(command_line, " ");

		if (command == NULL)continue;

		if (strcmp(command, "read") == 0) {

			cmd = strtok(NULL, " ");
			if (cmd == NULL) {
				printf("File name required.\n");
				continue;
			}

			read(cmd);

		}
		else if (strcmp(command, "size") == 0)
			size();
		else if (strcmp(command, "find") == 0) {
			cmd = strtok(NULL, " ");
			if (cmd == NULL) {
				printf("Invalid commands.\n");
				continue;
			}
			find(cmd);
		}
		else if (strcmp(command, "exit") == 0)
			break;
	}
}

void read(char *fileName) {


	char buf[CMD_SIZE];


	FILE *fp = fopen(fileName, "r");


	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	else
		printf("File loaded.\n\n");


	while ((fscanf(fp, "%s", buf) != EOF)) {
		fscanf(fp, "%s", buf);
	}
	fclose(fp);
}


int read_line(FILE *fp, char str[], int limit) {
	int ch, i = 0;
	while ((ch = fgetc(fp)) != '\n'&&ch != EOF)
		if (i < limit - 1)
			str[i++] = ch;
	str[i] = '\0';
	return i;


}

void find(char *cmd) {


}

void size() { printf("%d\n"), size; }





