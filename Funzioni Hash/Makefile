
AR       = ar
ARFLAGS  = rvs

CC       = gcc


TARGETS   =  testHash

.PHONY: cleanall

%: %.c
	@$(CC) -o $@ $<

%.o: %.c
	@$(CC) -c -o $@ $<

all: $(TARGETS)

testHash: testHash.o lib_dbj2.a
	@$(CC) $^ -o $@

lib_dbj2.a: lib/djb2.o lib/djb2.h
	@$(AR) $(ARFLAGS) $@ $^

cleanall :
	@rm -f *.txt *.a *.o lib/*.o lib/*.a
	@rm -f testHash

