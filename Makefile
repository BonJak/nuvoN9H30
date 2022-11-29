.SUFFIXES : .x .o .c .s

CC = arm-linux-gcc
CFLAGS = -MD -O2 -std=c99
LDFLAGS =  -ldl -pthread -static


APPDIR = .
# $(info $(SRCHEADERDIRS))


# all sources files except main.c
# APPSRC = $(shell find $(APPDIR) -name "*.c" -not -name "main.c")
APPSRC = $(shell find $(APPDIR) -name "*.c")
APPOBJ = $(APPSRC:.c=.o)
APPDEP = $(APPSRC:.c=.d)

# all header files
#APPHEADER = $(shell find $(APPDIR) -name "*.h")
#APPOBJ = $(APPSRC:.c=.o)
#APPDEP = $(APPSRC:.c=.d)
#
## get directory of all source files
#LIBSRCDIRS = $(shell find $(LIBSRCSDIR) -name "*.c" -exec dirname {} \; | sort | uniq)
## $(info $(LIBSRC))
#LIBOBJ = $(shell find $(LIBSRCSDIR) -name "*.c" | sed 's/\.c/\.o/g')
#LIBDEP = $(shell find $(LIBSRCSDIR) -name "*.c" | sed 's/\.c/\.d/g')
#
##$(info $(LIBOBJ))
##
INCLUDES = -I$(APPDIR)
#
#
BINARY= APP
#
all: $(BINARY)
$(APPDIR)/%.o : (APPDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES)  -c $< -o $@
$(BINARY): $(APPOBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(APPOBJ) $(LDFLAGS) -o $@
clean:
	rm -f $(BINARY) $(APPOBJ) $(LIBOBJ) $(APPDEP) $(LIBDEP)