ifeq ($(shell uname), Darwin)
  LIBSO=-undefined dynamic_lookup
else
  LDFLAGS=-rdynamic
endif
LDLIBS=-ldl
CFLAGS=-fPIC
BINS=m
SHLIBS=lib/s.so lib/l.so
all: lib $(BINS) $(SHLIBS)
test: clean all ; ./m lib/s.so lib/l.so lib/l.so lib/l.so
lib: ; mkdir -p lib
lib/%.so: %.o ; $(CC) -shared $(LIBSO) -o $@ $^
clean: ; rm -fr *.o *.so *~ lib $(BINS) Dockerfile
DOPTS=run -it --rm -w `pwd` -v `pwd`:`pwd`
docker: Dockerfile ; docker build . && docker $(DOPTS) `docker images -q | head -1`
Dockerfile:
	echo >>Dockerfile 'FROM ubuntu'
	echo >>Dockerfile 'RUN apt-get -y update && apt-get -y install apt-utils'
	echo >>Dockerfile 'RUN apt-get -y install build-essential libncurses-dev'

