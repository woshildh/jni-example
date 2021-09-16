#include "ObjectArrayTest.h"
#include <stdio.h>

JNIEXPORT jobjectArray JNICALL _Java_ObjectArrayTest_initInt2DArray(JNIEnv *env, jclass cls, jint size) {
    jobjectArray result;
    jclass intArrCls = env->FindClass("[I");
    if(!intArrCls) {
        return NULL;
    }
    result = env->NewObjectArray(size, intArrCls, NULL);
    if(!result) {
        return NULL;
    }
    for(int i = 0; i < size; ++i) {
        jint tmp[256];
        // 这个仅仅是指针
        jintArray iarr = env->NewIntArray(size);
        if(!iarr) {
            return NULL;
        }
        for(int j = 0; j < size; ++j) {
            tmp[j] = i + j;
        }
        env->SetIntArrayRegion(iarr, 0, size, tmp);
        env->SetObjectArrayElement(result, i, iarr);
        // 在退出之前要手动释放新建的对象
        env->DeleteLocalRef(iarr);
    }
    return result;
}