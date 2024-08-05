SOURCES := writer.c

ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	cc = aarch64-none-linux-gnu-gcc
	cxx = aarch64-none-linux-gnu-g++
else
	cc = gcc
	cxx = g++
endif

writer: $(SOURCES)
	$(cc) $(SOURCES) -o writer

clean:
	rm -f writer


