#ifndef __TOOLS_H__
#define __TOOLS_H__

#include "android/log.h"
#include "jni.h"
#include "stdlib.h"
#include <string.h>

// define android log tools
#define LOGD(tag, message) __android_log_print(ANDROID_LOG_DEBUG, tag, message)
#define LOGI(tag, message) __android_log_print(ANDROID_LOG_INFO, tag, message)
#define LOGW(tag, message) __android_log_print(ANDROID_LOG_WARN, tag, message)
#define LOGE(tag, message) __android_log_print(ANDROID_LOG_ERROR, tag, message)


/*
 * @brief: convert jbyteArray to char*, input byte data
 * @param[in] jbyteArray : input data
 * @return: char*
 */
char* JbyteArray2CStr(JNIEnv *env, jbyteArray bytes);

/*
 * @brief: convert char* to jbyteArray, output byte data
 * @param[in] cStr : native data
 * @return: output data
 */
jbyteArray CStr2JbyteArray(JNIEnv *env, const char* cStr);

/*
 * @brief: convert jstring to char*, input jString data
 * @param[in] jstring : input data
 * @return: char*
 */
char* JStr2CStr(JNIEnv *env, jstring jStr);

/*
 * @brief: convert char* to jstring, output jString data
 * @param[in] char* : native data
 * @return: output data
 */
jstring CStr2JStr(JNIEnv *env, const char* cStr);


#endif // __TOOLS_H__
