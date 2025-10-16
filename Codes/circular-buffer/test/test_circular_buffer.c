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

/* Test case 2*/
void test_circular_buffer_not_empty_after_new_element_added(void) 
{
    cbuffer_t buff;
    cbuffer_init(&buff);
    cbuffer_add(&buff, 42);
    TEST_ASSERT_FALSE(cbuffer_empty(&buff));
}

/*Test case 3*/
void test_circular_buffer_read_element_successful(void)
{
    cbuffer_t buff;
    cbuffer_init(&buff);

    uint8_t value = 55;
    cbuffer_add(&buff, value);

    TEST_ASSERT_EQUAL(value, cbuffer_get(&buff));
}

/*****************************************************************************
* Main
*****************************************************************************/
int main( int argc, char **argv) {
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_circular_buffer_empty_after_init);
    RUN_TEST(test_circular_buffer_not_empty_after_new_element_added);

    UNITY_END();
}