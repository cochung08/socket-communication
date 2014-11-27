#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int sockfd;
	int len;

	struct sockaddr_in address;

	int result;

	char* ch;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("143.89.173.91");
	address.sin_port = htons(24399);
	len = sizeof(address);
	result = connect(sockfd, (struct sockaddr *) &address, len);
	if (result == -1) {
		perror("oops:client\n");
		exit(1);
	}

	int recv_num, recv_num_total = 0;

	char recv_buf[50];

	char* apid = "sMobile";
	char* channel = "21";
	char* power = "38";

	while (1)

	{

		printf("%s%s\n", "current_channel: ", channel);
		printf("%s%s\n", "current_power: ", power);

		char* info;
		info = malloc(30);
		strcpy(info, apid);
		strcat(info, "_");
		strcat(info, channel);
		strcat(info, "_");
		strcat(info, power);

//		int leng=strlen(apid)+strlen('_')+strlen(channel)+strlen('_')+strlen(power)-2strlen()

		int a = send(sockfd, info, strlen(info), 0);

//		printf("%s\n", "sent");

		memset(recv_buf, 0, sizeof(recv_buf));

		recv_num = recv(sockfd, recv_buf, 26, 0);

		if (recv_num < 0)
			printf("recv_num < 0\n");

		else if (recv_num > 0)

		{
//			printf("recv_num > 0\n");
			recv_num_total += recv_num;

//			printf("%s", recv_buf);

			sync();

		}

		else

		{
			printf("accept\n");
			//newfd = accept(sockfd, NULL, NULL);

		}

		char *token = "_";

		// Token will point to "SEVERAL".
		channel = strtok(recv_buf, token);
		printf("%s%s\n", "modified_channel: ", channel);

		// Token will point to "WORDS".
		power = strtok(NULL, token);
		printf("%s%s\n", "modified_power: ", power);

//		int b = send(sockfd, current_power, strlen(current_power), 0);
//
//		printf("%s\n", "sent");
//
//		memset(recv_buf, 0, sizeof(recv_buf));
//
//		recv_num = recv(sockfd, recv_buf, 26, 0);
//
//		if (recv_num < 0)
//			printf("recv_num < 0\n");
//
//		else if (recv_num > 0)
//
//		{
//			printf("recv_num > 0\n");
//			recv_num_total += recv_num;
//
//			printf("%s", recv_buf);
//
//			sync();
//
//		}
//
//		else
//
//		{
//
//			printf("accept\n");
//
//			//newfd = accept(sockfd, NULL, NULL);
//
//		}
//
//		sleep(1);
	}

	exit(0);
	return 0;

}
