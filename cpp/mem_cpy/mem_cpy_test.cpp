#include <gtest/gtest.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "safe_comparators.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);

}


TEST(mem_cpy_test, test_case_one_char_len)
{
    const uint8_t k_MAXLEN = 1;
    uint8_t u8_dest_buf[k_MAXLEN] = {'#'};
    const char *u8_src_buf = "Amigos";

    memcpy(u8_dest_buf, u8_src_buf,  safe_min(sizeof(u8_dest_buf), strlen(u8_src_buf)));
    
    EXPECT_TRUE(u8_dest_buf[0] == 'A');
}


TEST(mem_cpy_test, test_case_with_offset)
{
    
    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "Amigos";
    
    // Starts from 4th location in the buffer
    memcpy(u8_dest_buf + 3, u8_src_buf, safe_min(sizeof(u8_dest_buf), strlen(u8_src_buf)));

    EXPECT_TRUE(u8_dest_buf[0] == '#');
    EXPECT_TRUE(u8_dest_buf[5] == 'i');
    EXPECT_TRUE(u8_dest_buf[6] == 'g' );
    EXPECT_TRUE(u8_dest_buf[k_MAXLEN - 1] == '#');

    std::cout << std::endl;
}


TEST(mem_cpy_test, test_case_buffer_over)
{
    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "La casa de papel"; // 15 characters

    memcpy(u8_dest_buf, u8_src_buf, safe_min(sizeof(u8_dest_buf), strlen(u8_src_buf)));
    
    EXPECT_TRUE(u8_dest_buf[0] == 'L');
    EXPECT_TRUE(u8_dest_buf[5] == 's');
    
    EXPECT_TRUE(u8_dest_buf[k_MAXLEN - 1] == 'e');
}


TEST(mem_cpy_test, test_case_buffer_over_offset)
{
    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "La casa de papel"; // 15 characters

    memcpy(u8_dest_buf + 4, u8_src_buf, safe_min(sizeof(u8_dest_buf) - 4, strlen(u8_src_buf)));
    
    EXPECT_TRUE(u8_dest_buf[0] == '#');
    EXPECT_TRUE(u8_dest_buf[3] == '#');

    EXPECT_TRUE(u8_dest_buf[4] == 'L');
    EXPECT_TRUE(u8_dest_buf[k_MAXLEN - 1] == 's');

}


TEST(mem_cpy_test, test_case_buffer_over_offset_source)
{
    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "La casa de papel"; // 15 characters

    memcpy(u8_dest_buf + 2, u8_src_buf + 10, safe_min(sizeof(u8_dest_buf) - 2, strlen(u8_src_buf) - 10));
    
    EXPECT_TRUE(u8_dest_buf[0] == '#');
    EXPECT_TRUE(u8_dest_buf[3] == 'p');

    EXPECT_TRUE(u8_dest_buf[k_MAXLEN - 1] == '#');
}