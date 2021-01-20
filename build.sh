#!/bin/sh
gcc -D QUEUE_CONTENT_TYPE="void*" \
-I headers/ \
-I ../../linear-ds/adaptive-queue/headers \
sources/bst.c sources/main.c "../../linear-ds/adaptive-queue/sources/queue.c" \
-o bin/out
bin/out