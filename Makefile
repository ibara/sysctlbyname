# libsysctl Makefile

LIB=	libsysctl.a
OBJS=	sysctlbyname.o

CFLAGS+=-std=c99

all: ${OBJS}
	${AR} cru ${LIB} ${OBJS}
	ranlib ${LIB}

install:
	install -d -m 755 ${PREFIX}/include
	install -c -m 644 libsysctl.h ${PREFIX}/include
	install -d -m 755 ${PREFIX}/lib
	install -c -m 644 ${LIB} ${PREFIX}/lib
	install -d -m 755 ${PREFIX}/man/man3
	install -c -m 644 sysctlbyname.3 ${PREFIX}/man/man3

test:
	@echo No tests

clean:
	rm -f ${LIB} ${OBJS}
