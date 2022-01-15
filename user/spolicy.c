//
// system program for scheduler policy control
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int policy = 0;
    int preemptive = 0;
    int alpha[2];
    int options = 0;

    for (int i = 1; i < argc; i++) {
        switch (i) {
            case 1:
                policy = atoi(argv[i]);
                printf("%d\n", policy);
                break;
            case 2:
                preemptive = atoi(argv[i]);
                printf("%d\n", preemptive);
                break;
            case 3:
                if(strlen(argv[3]) == 1){
                    alpha[0] = atoi(argv[3]);
                    alpha[1] = 1;
                }else{
                    alpha[0] = atoi(argv[3] + 2);
                    alpha[1] = strlen(argv[3] + 1);
                }
                printf("%d %d\n", alpha[0], alpha[1]);
                options = (alpha[0]<<8) + alpha[1];
                printf("%d\n", options);
                options = (options<<8) + preemptive;
                printf("%d\n", options);
                break;
            default:
                break;
        }
    }
    printf("Calling spolicy \n");
    spolicy(policy, options);
    exit(0);
}
