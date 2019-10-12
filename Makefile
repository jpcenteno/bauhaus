PREFIX = /usr/local
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Wno-unused-parameter -Werror

SDIR = src
ODIR = bin
OBJS = $(ODIR)/bauhaus.o $(ODIR)/blocks/jobs.o $(ODIR)/blocks/pwd.o $(ODIR)/blocks/exitcode.o

all: bin/bauhaus

bin/bauhaus: $(OBJS)
	@mkdir -p $(shell dirname $@)
	$(CC) $(LFLAGS) $(CFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(ODIR) vgcore.*

install: all
	mkdir -p ${PREFIX}/bin
	cp -f bin/bauhaus ${PREFIX}/bin
	chmod 755 ${PREFIX}/bin/bauhaus

uninstall:
	rm -f ${PREFIX}/bin
