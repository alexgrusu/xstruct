PROJ:= nptq_refl

CC = gcc
CFLAGS := -I.

LDLIBS :=

DEPS = ntpq.h struct.h functions.h

OBJ = main.o functions.o ntpq.o ../unix_monitor/unix_monitor.o ../my_alloc/my_alloc.o

%.o: %.c %(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ntpq_refl: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

.PHONY: clean

clean:
	rm -rf main.o
	rm -rf ntpq.o
	rm -rf ntpq_refl
	rm -rf functions.o
	rm -rf ../my_alloc/my_alloc.o
	rm -rf ../unix_monitor/unix_monitor.o