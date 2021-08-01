
AR       = ar
ARFLAGS  = rvs

CC       = gcc


TARGETS   =    MainTest

.PHONY: cleanall

%: %.c
	@$(CC) -o $@ $<

%.o: %.c
	@$(CC) -c -o $@ $<

all: $(TARGETS)

MainTest: MainTest.o lib_count_min.a
	@$(CC) $^ -o $@

lib_count_min.a: lib/count_min_sketch.o lib/count_min_sketch.h
	@$(AR) $(ARFLAGS) $@ $^


cleanall :
	@rm -f *.txt *.a *.o lib/*.o lib/*.a
	@rm -f testHash

