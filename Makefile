CC=gcc
CCFLAGS=-Wall
AR=ar
ARFLAGS=-r
LDFLAGS=-lpari
OBJ=pord.o opord.o rpord.o utils.o misc.o quad.o
OBJ_PIC=pord_pic.o opord_pic.o rpord_pic.o utils_pic.o misc_pic.o quad_pic.o
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
	$(CC)  $(TESTSRC) -o $(TEST)  $(LDFLAGS)  libfact.a

sharedlib: $(OBJ_PIC)
	$(CC) -shared -o $(SHAREDLIB) $(OBJ_PIC)

staticlib: $(OBJ)
	$(AR) $(ARFLAGS) $(STATICLIB) $(OBJ)

gplib: 
	@echo "libfact=\"$(SHAREDLIB_PATH)\";" > temp
	@echo "install(\"replace_eol\",\"vs\",\"replace_eol\",libfact);" >> temp
	@cat temp gp/*.gp > libfact.gp 
	@rm -f temp

pord.o: pord.c pord.h
	$(CC) $(CCFLAGS) -c pord.c -o pord.o

pord_pic.o: pord.c pord.h
	$(CC) $(CCFLAGS) -fPIC -c pord.c -o pord_pic.o

opord.o: opord.c opord.h
	$(CC) $(CCFLAGS) -c opord.c -o opord.o

opord_pic.o: opord.c opord.h
	$(CC) $(CCFLAGS) -fPIC -c opord.c -o opord_pic.o

rpord.o: rpord.c rpord.h
	$(CC) $(CCFLAGS) -c rpord.c -o rpord.o

rpord_pic.o: rpord.c rpord.h
	$(CC) $(CCFLAGS) -fPIC -c rpord.c -o rpord_pic.o

utils.o: utils.c utils.h
	$(CC) $(CCFLAGS) -c utils.c -o utils.o

utils_pic.o: utils.c utils.h
	$(CC) $(CCFLAGS) -fPIC -c utils.c -o utils_pic.o
	
misc.o: misc.c misc.h
	$(CC) $(CCFLAGS) -c misc.c -o misc.o

misc_pic.o: misc.c misc.h
	$(CC) $(CCFLAGS) -fPIC -c misc.c -o misc_pic.o

quad.o: quad.c quad.h
	$(CC) $(CCFLAGS) -c quad.c -o quad.o

quad_pic.o: quad.c quad.h
	$(CC) $(CCFLAGS) -fPIC -c quad.c -o quad_pic.o


.PHONY: clean cleanobj cleanlibs cleantest
clean: cleanobj cleanlibs cleantest 

cleanobj:
	rm -f $(OBJ) $(OBJ_PIC)
		
cleanlibs:
	rm -f $(SHAREDLIB) $(STATICLIB) $(GPLIB)

cleantest:
	rm -f $(TEST)
