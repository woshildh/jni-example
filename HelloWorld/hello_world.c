#include "HelloWorld.h"
#include <stdio.h>

JNIEXPORT void JNICALL _Java_HelloWorld_hello_1world(JNIEnv *env, jclass cla) {
    printf("Hello world!\n");
}