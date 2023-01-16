#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "safe_comparators.hpp"

// Test buffers
void test_case_one_char_len()
{
    const char * p_test_name = "Test with one character length";
    
    printf("\033[0;32m"); 
    printf("\nTest case: %s\n", p_test_name);
    printf("\033[0;0m");

    const uint8_t k_MAXLEN = 1;
    uint8_t u8_dest_buf[k_MAXLEN] = {'#'};
    const char *u8_src_buf = "Amigos";

    memcpy(u8_dest_buf, u8_src_buf,  safe_min(sizeof(u8_dest_buf), strlen(u8_src_buf)));
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << c << std::endl;});
    
    assert(u8_dest_buf[0] == 'A');
}


void test_case_with_offset()
{
    const char * p_test_name = "Test with offset";
    printf("\033[0;32m"); 
    printf("\nTest case: %s\n", p_test_name);
    printf("\033[0;0m"); 
    
    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "Amigos";
    
    // Starts from 4th location in the buffer
    memcpy(u8_dest_buf + 3, u8_src_buf, safe_min(sizeof(u8_dest_buf), strlen(u8_src_buf)));
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << '[' << c << ']'; });

    std::cout << std::endl;
    assert(u8_dest_buf[0] == '#');
    assert(u8_dest_buf[5] == 'i');
    assert(u8_dest_buf[6] == 'g' );
    assert(u8_dest_buf[k_MAXLEN - 1] == '#');

    std::cout << std::endl;
}


void test_case_buffer_over()
{
    const char *p_test_name = "Test with length more than buffer";
    
    printf("\033[0;32m"); 
    printf("\nTest case: %s\n", p_test_name);
    printf("\033[0;0m");

    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "La casa de papel"; // 15 characters

    memcpy(u8_dest_buf, u8_src_buf, safe_min(sizeof(u8_dest_buf), strlen(u8_src_buf)));
    
    std::cout << std::endl;
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << '[' << c << ']';});
    assert(u8_dest_buf[0] == 'L');
    assert(u8_dest_buf[5] == 's');
    
    assert(u8_dest_buf[k_MAXLEN - 1] == 'e');

    std::cout << std::endl;
}


void test_case_buffer_over_offset()
{
    const char *p_test_name = "Test with length more than buffer and offset";
    printf("\033[0;32m"); 
    printf("\nTest case: %s\n", p_test_name);
    printf("\033[0;0m");

    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "La casa de papel"; // 15 characters

    memcpy(u8_dest_buf + 4, u8_src_buf, safe_min(sizeof(u8_dest_buf) - 4, strlen(u8_src_buf)));
    
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << '[' << c << ']';});
    std::cout << std::endl;
    assert(u8_dest_buf[0] == '#');
    assert(u8_dest_buf[3] == '#');

    assert(u8_dest_buf[4] == 'L');
    assert(u8_dest_buf[k_MAXLEN - 1] == 's');

    std::cout << std::endl;
}


void test_case_buffer_over_offset_source()
{
    const char *p_test_name = "Test with length more than buffer and offset in source";
    printf("\033[0;32m"); 
    printf("\nTest case: %s\n", p_test_name);
    printf("\033[0;0m");

    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "La casa de papel"; // 15 characters

    memcpy(u8_dest_buf + 2, u8_src_buf + 10, safe_min(sizeof(u8_dest_buf) - 2, strlen(u8_src_buf) - 10));
    
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << '[' << c << ']';});
    std::cout << std::endl;
    assert(u8_dest_buf[0] == '#');
    assert(u8_dest_buf[3] == 'p');

    assert(u8_dest_buf[k_MAXLEN - 1] == '#');

    std::cout << std::endl;
}


int main(int argc, char **argv)
{

    test_case_one_char_len();
    test_case_with_offset();
    test_case_buffer_over();
    test_case_buffer_over_offset();
    test_case_buffer_over_offset_source();

    return EXIT_SUCCESS;
}
