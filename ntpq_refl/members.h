#include <inttypes.h>

MAC(int8_t, [128], remote, copy_string)

MAC(int8_t, [128], refid, copy_string)

MAC(int32_t, , stratum, copy_int)

MAC(int8_t, [1], type, copy_string)

MAC(int32_t, , when, copy_int)

MAC(int32_t, , poll, copy_int)

MAC(int32_t, , reach, copy_int)

MAC(float, , delay, copy_float)

MAC(float, , offset, copy_float)

MAC(float, , jitter, copy_float)
