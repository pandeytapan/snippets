#include <assert.h>
#include <string.h>
#include <iostream>

// Test buffers
void test_case_one_char_len()
{
    const char8_t * test_name = "Test with one character length";

    const uint8_t k_MAXLEN = 1;
    uint8_t u8_dest_buf[k_MAXLEN] = {'#'};
    const char *u8_src_buf = "Amigos";

    memcpy(u8_dest_buf, u8_src_buf,  safe_min(sizeof(u8_dest_buf), strlen(u8_src_buf)));
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << c << std::endl;});
    
    assert(u8_dest_buf[0] == 'A');
}


TEST_CASE("Test with offset", "[mem_cpy_offset]")
{
    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "Amigos";
    
    // Starts from 4th location in the buffer
    memcpy(u8_dest_buf + 3, u8_src_buf, safe_min(sizeof(u8_dest_buf), strlen(u8_src_buf)));
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << '[' << c << ']'; });

    std::cout << std::endl;
    REQUIRE(u8_dest_buf[0] == '#');
    REQUIRE(u8_dest_buf[5] == 'i');
    REQUIRE(u8_dest_buf[6] == 'g' );
    REQUIRE(u8_dest_buf[k_MAXLEN - 1] == '#');

    std::cout << std::endl;
}


TEST_CASE("Test with length more than buffer", "[mem_cpy_one_plus_len]")
{
    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "La casa de papel"; // 15 characters

    memcpy(u8_dest_buf, u8_src_buf, safe_min(sizeof(u8_dest_buf), strlen(u8_src_buf)));
    
    std::cout << std::endl;
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << '[' << c << ']';});
    REQUIRE(u8_dest_buf[0] == 'L');
    REQUIRE(u8_dest_buf[5] == 's');
    
    REQUIRE(u8_dest_buf[k_MAXLEN - 1] == 'e');

    std::cout << std::endl;
}


TEST_CASE("Test with length more than buffer and offset", "[mem_cpy_one_plus_len]")
{
    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "La casa de papel"; // 15 characters

    memcpy(u8_dest_buf + 4, u8_src_buf, safe_min(sizeof(u8_dest_buf) - 4, strlen(u8_src_buf)));
    
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << '[' << c << ']';});
    std::cout << std::endl;
    REQUIRE(u8_dest_buf[0] == '#');
    REQUIRE(u8_dest_buf[3] == '#');

    REQUIRE(u8_dest_buf[4] == 'L');
    REQUIRE(u8_dest_buf[k_MAXLEN - 1] == 's');

    std::cout << std::endl;
}


TEST_CASE("Test with length more than buffer and offset in source", "[mem_cpy_one_plus_len]")
{
    const uint8_t k_MAXLEN = 10;
    uint8_t u8_dest_buf[] = "##########";
    const char * u8_src_buf  = "La casa de papel"; // 15 characters

    memcpy(u8_dest_buf + 2, u8_src_buf + 10, safe_min(sizeof(u8_dest_buf) - 2, strlen(u8_src_buf) - 10));
    
    std::for_each(u8_dest_buf, u8_dest_buf + k_MAXLEN, [](uint8_t &c) { std::cout << '[' << c << ']';});
    std::cout << std::endl;
    REQUIRE(u8_dest_buf[0] == '#');
    REQUIRE(u8_dest_buf[3] == 'p');

    REQUIRE(u8_dest_buf[k_MAXLEN - 1] == '#');

    std::cout << std::endl;
}