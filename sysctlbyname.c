/*
 * Copyright (c) 2019 Brian Callahan <bcallah@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>
#include <sys/sysctl.h>

#include <errno.h>
#include <string.h>

#include "sysctlbyname.h"

int
sysctlbyname(const char *name, void *oldp, size_t *oldlenp,
    void *newp, size_t newlen)
{
	int mib[3];
	u_int n;

	for (size_t i = 0; i < sizeof(sn) / sizeof(sn[0]); i++) {
		if (name[0] != sn[i].name[0])
			continue;

		if (!strcmp(name, sn[i].name)) {
			mib[0] = sn[i].mib0;
			mib[1] = sn[i].mib1;
			mib[2] = sn[i].mib2;

			/*
			 * We need to know how many mibs we used.
			 */
			if (mib[2] == 0)
				n = 2;
			else
				n = 3;

			return sysctl(mib, n, oldp, oldlenp, newp, newlen);
		}
	}

	errno = ENOENT;

	return (-1);
}
