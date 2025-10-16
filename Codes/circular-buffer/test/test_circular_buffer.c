#include <unity.h>
#include "cbuffer.h"

/*****************************************************************************
* Default setUp and tearDown functions
*****************************************************************************/
void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


/*****************************************************************************
* Test cases
*****************************************************************************/
/* Test case 1*/
void test_circular_buffer_empty_after_init(void) 
{
    cbuffer_t buff;
    cbuffer_init(&buff);
    TEST_ASSERT_TRUE(cbuffer_empty(&buff));
}


/*****************************************************************************
* Main
*****************************************************************************/
int main( int argc, char **argv) {
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_circular_buffer_empty_after_init);

    UNITY_END();
}