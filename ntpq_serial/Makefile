PROJ:= nptq

CC = gcc
CFLAGS := -I. 

LDLIBS :=

DEPS = ntpq.h

OBJ = main.o ntpq.o ../unix_monitor/unix_monitor.o ../my_alloc/my_alloc.o

%.o: %.c %(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ntpq_serial: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

.PHONY: clean

clean:
	rm -rf main.o
	rm -rf ntpq.o
	rm -rf ntpq_serial
	rm -rf ../my_alloc/my_alloc.o
	rm -rf ../unix_monitor/unix_monitor.o