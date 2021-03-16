#include <stdint.h>
#include <stdio.h>

static uint8_t output[8], input[8];
// static uint64_t output, input;

static inline void dump_8bits(uint8_t _data)
{   
    for (int i = 0; i < 8; ++i)
        printf("%d", (_data & (0x80 >> i)) ? 1 : 0);
}

static inline void dump_binary(uint8_t *_buffer, size_t _length)
{   
    for (int i = 0; i < _length; ++i)
        dump_8bits(*_buffer++);
}

static inline void dump_64bits(uint64_t _data)
{   
    for (int i = 0; i < 64; ++i)
        printf("%d", (_data & (0x8000000000000000 >> i)) ? 1 : 0);
}

/*read from src and write to dest*/
void bitcpy(void *_dest,      /* Address of the buffer to write to */
            size_t _write,    /* Bit offset to start writing to */
            const void *_src, /* Address of the buffer to read from */
            size_t _read,     /* Bit offset to start reading from */
            size_t count)
{
    uint64_t data;
    const uint64_t *source = (const uint64_t *)_src;
    uint64_t *dest = (uint64_t *)_dest;
    data = *source;
    data = data << _read;
    // data >> _read + (63 - (_read + count) + 1)
    data = data >> (64 - count);
    data = data << (64 - (_read + count));
    if(_read > _write){
        data = data << (_read - _write);
    }else{
        data = data >> (_write - _read);
    }
    *dest |= data;
    dump_64bits(*dest);
}
