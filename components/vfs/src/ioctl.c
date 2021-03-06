// Copyright 2018-2019 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdarg.h>
#include <sys/ioctl.h>

int ioctl(int fd, int request, ...)
{
    int ret;
    void *p;
    va_list va;

    va_start(va, request);
    
    p = va_arg(va, void *);
    ret = lwip_ioctl(fd, request, p);

    va_end(va);

    return ret;
}

