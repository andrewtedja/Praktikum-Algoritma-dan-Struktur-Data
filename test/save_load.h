#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H
#include "../adt/mesinkata.h"
#include "../adt/boolean.h"

extern Word emailConfig;
extern Word penggunaConfig;
extern Word umumConfig;

void loadUserConfig(const char *filePath);
void saveUserConfig(const char *filePath);
void freeUserConfig();

#endif