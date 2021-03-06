/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class Prompt */

#ifndef _Included_Prompt
#define _Included_Prompt
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     Prompt
 * Method:    getLine
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL _Java_Prompt_getLine(JNIEnv *env, jobject obj, jstring prompt) {
    char buf[128];
    const char *c_prompt = env->GetStringUTFChars(prompt, NULL);
    printf("%s", c_prompt);
    // 释放内存
    env->ReleaseStringUTFChars(prompt, c_prompt);
    // 获取输入
    scanf("%s", buf);
    return env->NewStringUTF(buf);
}

#ifdef __cplusplus
}
#endif
#endif
