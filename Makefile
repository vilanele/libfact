CC=gcc
CCFLAGS=-Wall
AR=ar
ARFLAGS=-r
LDFLAGS=-lpari
OBJ=pord.o opord.o rpord.o utils.o misc.o quad.o
SHAREDLIB=libfact.so
STATICLIB=libfact.a
GPLIB=libfact.gp
GPLIB_NOPATH=libfact_nopath.gp
TEST=test
TESTSRC=test.c
TARGETS=sharedlib staticlib gplib test
PWD=`pwd`
SHAREDLIB_PATH=$(PWD)/$(SHAREDLIB)

all: $(TARGETS)

test: $(TESTSRC) $(STATICLIB)
	$(CC) $(CCFLAGS) $(TESTSRC) -o $(TEST) $(STATICLIB) $(LDFLAGS)

sharedlib: $(OBJ)
	$(CC) $(CCFLAGS) -shared -o $(SHAREDLIB) $(OBJ)

staticlib: $(OBJ)
	$(AR) $(ARFLAGS) $(STATICLIB) $(OBJ)
	
gplib: $(GPLIB_NOPATH)
	
	@echo "libfact_abspath=\"$(SHAREDLIB_PATH)\";" > temp
	@cat temp $(GPLIB_NOPATH) > $(GPLIB)
	@rm -f temp
	@echo "$(GPLIB) : absolute path to $(SHAREDLIB) writen in $(GPLIB)"
	@echo "    $(SHAREDLIB_PATH)" 

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm -f $(SHAREDLIB) $(STATICLIB) $(GPLIB) $(TEST)

