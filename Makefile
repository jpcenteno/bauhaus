SDIR = src
ODIR = bin
OBJS = $(ODIR)/bauhaus.o $(ODIR)/blocks/jobs.o $(ODIR)/blocks/pwd.o $(ODIR)/blocks/exitcode.o
CFLAGS = -g
bin/bauhaus: $(OBJS)
	@mkdir -p $(shell dirname $@)
	$(CC) $(LFLAGS) $(CFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(ODIR)
