#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MSG_SIZE 100

struct message {
    long msg_type;
    char msg_text[MSG_SIZE];  // No sender PID here, since we can't change sender
};

// Function to get process name from PID
void get_process_name(pid_t pid) {
    char path[40], name[100];
    snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
    FILE *f = fopen(path, "r");
    if (f) {
        fgets(name, sizeof(name), f);
        fclose(f);
        printf("Sender Process Name: %s\n", name);
    } else {
        printf("Could not determine process name for PID: %d\n", pid);
    }
}

int main() {
    key_t key = ftok("msgqueue", 65);  // Generate key
    int msgid = msgget(key, 0666 | IPC_CREAT);  // Get message queue

    struct message msg;
    
    // Receive message (no PID included)
    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);
    printf("Message Received: %s\n", msg.msg_text);

    // Get last sender PID using msgctl()
    struct msqid_ds buf;
    msgctl(msgid, IPC_STAT, &buf);
    printf("Message Sent by PID: %d\n", buf.msg_lspid);

    // Get process name from PID
    get_process_name(buf.msg_lspid);

    // Remove message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
