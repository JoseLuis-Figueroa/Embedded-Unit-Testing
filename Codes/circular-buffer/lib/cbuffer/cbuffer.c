#include "cbuffer.h"

void cbuffer_init(cbuffer_t* buf) 
{
    buf->head = 0;
    buf->tail = 0;
}

bool cbuffer_empty(cbuffer_t* buf) 
{
    return buf->head == buf->tail;
}

void cbuffer_add(cbuffer_t* buf, uint8_t item) 
{
    if (cbuffer_full(buf)) 
    {
        // Buffer is full, overwrite the oldest data
        buf->tail = (buf->tail + 1) & BUFFER_MASK;
    }

    buf->buffer[buf->head] = item;
    buf->head = (buf->head + 1) & BUFFER_MASK;
}

uint8_t cbuffer_get(cbuffer_t* buf) 
{
    if(cbuffer_empty(buf))
    {
        // Buffer is empty, return 0 or handle underflow as needed
        return 0;
    }
    return buf->buffer[buf->tail++];
}


bool cbuffer_full(cbuffer_t* buf) {
    return (buf->head - buf->tail) & BUFFER_MASK == BUFFER_MASK;
}


void cbuffer_clear(cbuffer_t* buf) {}