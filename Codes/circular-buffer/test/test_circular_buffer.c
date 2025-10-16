#include <unity.h>
#include "cbuffer.h"

/*****************************************************************************
* global variables
*****************************************************************************/
cbuffer_t buff;

/*****************************************************************************
* Default setUp and tearDown functions
*****************************************************************************/
void setUp(void) 
{
    cbuffer_init(&buff);
}

void tearDown(void) 
{
    cbuffer_clear(&buff);
}


/*****************************************************************************
* Test cases
*****************************************************************************/
/* Test case 1*/
void test_circular_buffer_empty_after_init(void) 
{
    TEST_ASSERT_TRUE(cbuffer_empty(&buff));
}

/* Test case 2*/
void test_circular_buffer_not_empty_after_new_element_added(void) 
{
    cbuffer_add(&buff, 42);
    TEST_ASSERT_FALSE(cbuffer_empty(&buff));
}

/*Test case 3*/
void test_circular_buffer_read_element_successful(void)
{
    uint8_t value = 55;
    cbuffer_add(&buff, value);

    TEST_ASSERT_EQUAL(value, cbuffer_get(&buff));
}

/*Test case 4*/
void test_circular_buffer_cleaned_succesfully()
{
    for(uint8_t i=0; i<BUFFER_SIZE/2; i++)
    {
        cbuffer_add(&buff, i);
    }
    cbuffer_clear(&buff);
    TEST_ASSERT_TRUE(cbuffer_empty(&buff));
}

/*****************************************************************************
* Main
*****************************************************************************/
int main( int argc, char **argv) {
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_circular_buffer_empty_after_init);
    RUN_TEST(test_circular_buffer_not_empty_after_new_element_added);
    RUN_TEST(test_circular_buffer_read_element_successful);
    RUN_TEST(test_circular_buffer_cleaned_succesfully);

    UNITY_END();
}