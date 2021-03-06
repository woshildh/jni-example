/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class StaticMethodCall */

#ifndef _Included_StaticMethodCall
#define _Included_StaticMethodCall
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     StaticMethodCall
 * Method:    nativeMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL _Java_StaticMethodCall_nativeMethod(JNIEnv *env, jobject obj) {
    jclass clsid = env->GetObjectClass(obj);
    jmethodID mid = env->GetStaticMethodID(clsid, "callback", "()V");
    if(!mid) {
        return ;
    }
    printf("In C\n");
    env->CallStaticVoidMethod(clsid, mid);
}

#ifdef __cplusplus
}
#endif
#endif
