/*
 * Copyright (C) 2021 Sora Tonami
 *
 * This file is part of Emerald OS.
 *
 * Emerald OS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Emerald OS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Emerald OS.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "error.h"

int getparam(char *key, char **ret) {
    int i = 0;
    int j = 0;
    char str[256];
    char param[256];
    FILE *fin;
    if(key == "") {
        exit(EMOS_ERROR_CONFIG_READ_KEY_EMPTY);
    }
    if((fin = fopen(CONF_FILE, "r")) == NULL) {
        printf("\e[38;2;255;0;0mError: File input Error: Config file not found.\n");
        exit(EMOS_ERROR_CONFFILE_READ_FAILURE);
    }
    while(true) {
        if(fgets(str, 256, fin) == NULL) {
            fclose(fin);
            return EMOS_ERROR_CONFIG_READ_KEY_NOT_FOUND;
        }
        if(!strncmp(str, key, strlen(key))) {
            while(str[i++] != '=');
            while(str[i] != '\n') param[j++] = str[i++];
            param[j] = '\0';
            sprintf(ret, param);
            fclose(fin);
            return EMOS_SUCCESS;
        }
    }
    fclose(fin);
    return EMOS_ERROR_OTHER;
}
