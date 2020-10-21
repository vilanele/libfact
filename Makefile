CC=gcc
CCFLAGS=-Wall
AR=ar
ARFLAGS=-r
LDFLAGS=-lpari
OBJ=pord.o opord.o rpord.o utils.o misc.o quad.o
SHAREDLIB=libfact.so
STATICLIB=libfact.a
GPLIB0=gp/libfact0.gp
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

gplib: 
	@echo "libfact=\"$(SHAREDLIB_PATH)\";" > temp
	@echo "install(\"replace_eol\",\"vs\",\"replace_eol\",libfact);" >> temp
	@cat temp gp/*.gp > libfact.gp 
	@rm -f temp

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY: clean cleanobj cleanlibs cleantest
clean: cleanobj cleanlibs cleantest

cleanobj:
	rm -f $(OBJ)
		
cleanlibs:
	rm -f $(SHAREDLIB) $(STATICLIB) $(GPLIB)

cleantest:
	rm -f $(TEST)
