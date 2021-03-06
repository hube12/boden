#pragma once

#include <bdn/android/appEntry.h>
#include <bdn/platform/androidplatform.h>

#include <bdn/jni.h>

#define BDN_APP_INIT_WITH_CONTROLLER_CREATOR(appControllerCreator)                                                     \
    extern "C" JNIEXPORT void JNICALL Java_io_boden_android_NativeInit_nativeLaunch(JNIEnv *env, jclass cls,           \
                                                                                    jobject rawIntent)                 \
    {                                                                                                                  \
        bdn::platform::AndroidHooks::init();                                                                           \
        bdn::ui::android::appEntry(appControllerCreator, env, rawIntent);                                              \
    }

#define BDN_APP_INIT(appControllerClass)                                                                               \
    BDN_APP_INIT_WITH_CONTROLLER_CREATOR((([]() { return std::make_shared<appControllerClass>(); })))
