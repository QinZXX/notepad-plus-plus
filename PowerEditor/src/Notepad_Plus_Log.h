/* This file is part of Notepad++ project
 * Copyright (C)2022 QinZXX <zxqin@hillstone.com>
 */

#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>

enum {
    LOG_ALL = 0,
    LOG_DEBUG,
    LOG_WARN,
    LOG_ERROR
};

//extern int g_log_level;

void pre_log(const char *prefix, const char *fmt, ...);
void log_stdout(const char *prefix, const char *fmt, va_list args);
bool set_log_level(int level);

/*
#define LOG(level, prefix, format, ...)\
    do {\
        if (g_log_level <= level)\
            pre_log(prefix, format, ##__VA_ARGS__);\
    } while (0);
*/

#define LOG(level, prefix, format, ...)\
    do {\
        pre_log(prefix, format, ##__VA_ARGS__);\
    } while (0);

#define log_debug(fmt,...) LOG(LOG_DEBUG,"[debug]",fmt,##__VA_ARGS__)
#define log_warn(fmt,...) LOG(LOG_WARN,"[warn]",fmt,##__VA_ARGS__)
#define log_error(fmt,...) LOG(LOG_DEBUG,"[error]",fmt,##__VA_ARGS__)



//log_debug("reload npp params, and try to change menu language now %s", "ni");

