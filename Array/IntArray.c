#include "IntArray.h"

JNIEXPORT jint JNICALL _Java_IntArray_sumArray(JNIEnv *env, jclass cla, jintArray arr) {
    jint buf[10];
    (*env)->GetIntArrayRegion(env, arr, 0, 10, buf);
    jint sum = 0;
    for(int i = 0; i < 10; ++i) {
        sum += buf[i];
    }
    return sum;
}
