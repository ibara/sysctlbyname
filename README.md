libsysctl
=========
Compat library for
[OpenBSD](https://www.openbsd.org/).

This library provides a simple and stripped-down version of `sysctlbyname(3)`,
which is provided on all other BSDs, including macOS.

It is suitable for the few OpenBSD ports that use `sysctlbyname`, to simplify
the patches. It's probably not suitable for much more than that.

Why?
----
OpenBSD is the only \*BSD not to provide `sysctlbyname`. Non-BSD people looking
to provide compatability through the `sysctl` interface probably aren't going
to look up the MIB defines or even necessarily know what they are. As such the
`sysctlbyname` function provides a useful abstraction layer to make porting to
\*BSD easier. I've only ever seen relatively basic usage of `sysctlbyname`,
usually to get some stats under hw.* making this implementation sufficient to
handle probably all use cases.
