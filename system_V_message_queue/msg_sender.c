#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 100

struct message {
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main() {
    key_t key = ftok("msgqueue", 65);  // Generate unique key
    int msgid = msgget(key, 0666 | IPC_CREAT);  // Create message queue

    struct message msg;
    msg.msg_type = 1;  // Message type
    strcpy(msg.msg_text, "Hello from sender!");

    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);  // Send message
    sleep(5);
    printf("Message Sent: %s\n", msg.msg_text);
    return 0;
}

