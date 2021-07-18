
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

testHash: testHash.o lib_hash_function.a
	@$(CC) $^ -o $@

lib_hash_function.a: lib/hash_function.o lib/hash_function.h
	@$(AR) $(ARFLAGS) $@ $^

cleanall :
	@rm -f *.txt *.a *.o lib/*.o lib/*.a
	@rm -f testHash

