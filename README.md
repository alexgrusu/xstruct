# xstruct

This is a demo project that presents structure referecing in C language.

As it is well known, the access to structure members by index is not possible according to C language standard. In C++ this functionality can be emulated by using a C++ specific pointer type, known as "pointer-to-data-member". C language has no such type, but it can be emulated by using the standard `offsetof` macro and pointer arithmetics. 

Suppose that an API responds with the same structure of data (e.g., a string that consists different types of data) for each specific request, then the main idea is to initialize a structure with the received data (each data having a different type).

In this demo project, two different methods of structure referencing are depicted. The first method(\*) exploits structure referencing through dynamic memory allocation and pointer synchronization. The second variant(+) is a more fashion approach, tailored with pre-processing techniques and macros. These two methods can be found in the `ntpq_serial(*)` and `ntpq_refl(+)` folders.

Both methods read the output of the following command:

    $ ntpq -np | grep -i "\*"

that returns

    93.190.144.28   .GCC.            1 u   69 1024  377   37.091  -18.992   3.993

where each data is designated below
     
    remote           refid          st t when poll  reach delay   offset   jitter.

As a result, the unix command output is load in a ntpq structure that contains the fields:

- `remote`  (`int8_t[128]`);
- `refid`   (`int8_t[128]`);
- `stratum` (`int32_t`);
- `type`    (`int8_t`);
- `when`    (`int32_t`);
- `poll`    (`int32_t`);
- `reach`   (`int32_t`);
- `delay`   (`float`);
- `offset`  (`float`);
- `jitter`  (`float`)

Therefore, all data can be used in certain ways.
