package com.example.v8runtime;

import android.content.Context;
import android.os.Environment;

public class JSRuntime {

    static String rootDir = "";

    static {
        System.loadLibrary("v8runtime");
    }

    public static JSRuntime instance;
    private boolean isInitialized = false;

    private JSRuntime(Context context){

        rootDir = context.getExternalFilesDir(null).getAbsolutePath();
        isInitialized = initialize();
    }

    // 初始化V8引擎
    public boolean initializeV8Engine(){
        return initializeCppJSRuntime(rootDir,"--expose_gc");
    }

    // 初始化JS运行时
    public boolean initialize(){
        // 初始化V8引擎
        if(!initializeV8Engine())
            return false;

        return true;
    }

    public static JSRuntime getInstance(Context context){

        if(instance == null)
            instance = new JSRuntime(context);
        return instance;
    }

    private native static boolean initializeCppJSRuntime(String appRootPath,String startupFlags);

}
