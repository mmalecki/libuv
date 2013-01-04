/* Copyright Joyent, Inc. and other Node contributors. All rights reserved.
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "uv.h"
#include "internal.h"

#include <errno.h>
#include <string.h>
#include <sys/utsname.h>


uv_err_t uv_hostname(char* hostname, size_t size) {
  int r;

  r = gethostname(hostname, size);

  if (r < 0)
    return uv__new_sys_error(errno);

  return uv_ok_;
}


uv_err_t uv_os_type(char* type, size_t size) {
  int r;
  struct utsname info;

  r = uname(&info);

  if (r < 0)
    return uv__new_sys_error(errno);

  uv_strlcpy(type, info.sysname, size);

  return uv_ok_;
}


uv_err_t uv_os_release(char* release, size_t size) {
  int r;
  struct utsname info;

  r = uname(&info);

  if (r < 0)
    return uv__new_sys_error(errno);

  uv_strlcpy(release, info.release, size);

  return uv_ok_;
}
