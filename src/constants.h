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

#include "os.h"

#ifndef __EMERALDOS_CONSTANTS__
    #define __EMERALDOS_CONSTANTS__

    const char *VERSION = "0.1.0";

    #ifdef __EMERALDOS_PLATFORM_WIN32__
        const char *CONF_FILE = "C:\\emeraldos\\emeraldos.conf";
    #elif defined __EMERALDOS_PLATFORM_MACOS__
        const char *CONF_FILE = "/usr/emeraldos/emeraldos.conf";
    #else
        const char *CONF_FILE = "/usr/emeraldos/emeraldos.conf";
    #endif
#endif
