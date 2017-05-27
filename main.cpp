#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <QString>

#define  BUFF_SIZE   1024

int main()
{
  const QString enteredKey = "echotest";
  int client_socket;
  struct sockaddr_in  server_addr;

  char buff[BUFF_SIZE+5];
  client_socket = socket(PF_INET, SOCK_STREAM, 0);
  if ( client_socket == -1 )
    return -1;

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(4000);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if ( connect(client_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
    return -1;

  QByteArray tempString;
  tempString.append(enteredKey);

  write(client_socket, tempString.data(), strlen(tempString.data()+1));
  read(client_socket, buff, BUFF_SIZE);

  printf("SetText: %s\n", buff);
  printf("SetSubText: %s\n", tempString.data());

  close(client_socket);
}