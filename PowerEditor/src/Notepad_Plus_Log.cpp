#include "Notepad_Plus_Log.h"

//int g_log_level = LOG_DEBUG;

void log_stdout(const char *prefix, const char *fmt, va_list args) {
    char line[1024] = {0};
    FILE *fp = NULL;

    strcpy(line, prefix); // zxqin: danger of out of range
    strcpy(line + strlen(line), " ");
    //strcpy(line + strlen(line), stamp);
    vsnprintf(line + strlen(line), 1024 - strlen(line), fmt, args);
    printf(line);
    
    fp = fopen("test.log", "a+");
    if (fp) {
        fprintf(fp, "%s\n",line);
        fclose(fp);
    }
}

void pre_log(const char *prefix, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log_stdout(prefix, fmt, args);
    //log_file(prefix, fmt, args);
    va_end(args);
}

bool set_log_level(int level) {
    if (LOG_ALL >= level && LOG_ERROR <= level) {
         //g_log_level = level;
         return true;
    }
    return false;
}