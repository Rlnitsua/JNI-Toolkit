#include "tools.h"

const char* TOOLS_TAG = "tools";

// todo : release all var
// convert char* to jbyteArray
jbyteArray CStr2JbyteArray(JNIEnv *env, const char* cStr) {
    jbyteArray jarray = env->NewByteArray((jsize)strlen(cStr));
    env->SetByteArrayRegion(jarray, 0, (jsize)strlen(cStr), (jbyte*)cStr);
    return jarray;
}

// convert jbyteArray to char*
char* JbyteArray2CStr(JNIEnv *env, jbyteArray bytes) {
    // jbyteArray -> jbyte*
    jbyte* bytesPtr = env->GetByteArrayElements(bytes, JNI_FALSE);
    // jbyte* -> char*
    char* rtn = NULL;
    jsize arrayLen = env->GetArrayLength(bytes);
    if (arrayLen > 0) {
        rtn = (char*)malloc(arrayLen + 1); 
        memcpy(rtn, bytesPtr, arrayLen);
        rtn[arrayLen] = '\0';
    }
    env->ReleaseByteArrayElements(bytes, bytesPtr, 0);
    return rtn;
}

// convert jstring to char*
char* JStr2CStr(JNIEnv *env, jstring jStr) {
    // jstring -> jbyteArray
    jclass strClass = env->FindClass("java/lang/String");
    jmethodID mid = env->GetMethodID(strClass, "getBytes", "(Ljava/lang/String;)[B");
    jstring encode = env->NewStringUTF("GB2312");
    jbyteArray bytes = (jbyteArray)env->CallObjectMethod(jStr, mid, encode);
    // jbyteArray -> char*
    return JbyteArray2CStr(env, bytes);
}

// convert char* to jstring
jstring CStr2JStr(JNIEnv *env, const char* cStr) {
    // char* -> jbyteArray
    jbyteArray jarray = CStr2JbyteArray(env, cStr);
    // jbyteArray -> jstring
    jclass strClass = env->FindClass("java/lang/String");
    jmethodID mid = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jstring encode = env->NewStringUTF("GB2312");
    return (jstring)env->NewObject(strClass, mid, jarray, encode);
}
