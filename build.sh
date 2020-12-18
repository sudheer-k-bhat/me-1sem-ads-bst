gcc -D QUEUE_CONTENT_TYPE="void*" -I headers/ -I ../adaptive-queue/headers sources/bst.c sources/main.c "../adaptive-queue/sources/queue.c" -o bin/out
bin/out