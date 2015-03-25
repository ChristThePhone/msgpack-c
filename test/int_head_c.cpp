#include <msgpack.h>
#include <gtest/gtest.h>

TEST(int_head_c, uint8)
{
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint8_t v = 0x7fu;
        msgpack_pack_uint8(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0x7fu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint8_t v = 0x80u;
        msgpack_pack_uint8(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xccu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint8_t v = 0xffu;
        msgpack_pack_uint8(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xccu));

        msgpack_sbuffer_destroy(&sbuf);
    }
}

TEST(int_head_c, uint16)
{
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint16_t v = 0x7fu;
        msgpack_pack_uint16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0x7fu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint16_t v = 0x80u;
        msgpack_pack_uint16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xccu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint16_t v = 0xffu;
        msgpack_pack_uint16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xccu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint16_t v = 0x100u;
        msgpack_pack_uint16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcdu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint16_t v = 0xffffu;
        msgpack_pack_uint16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcdu));

        msgpack_sbuffer_destroy(&sbuf);
    }
}

TEST(int_head_c, uint32)
{
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint32_t v = 0x7fu;
        msgpack_pack_uint32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0x7fu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint32_t v = 0x80u;
        msgpack_pack_uint32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xccu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint32_t v = 0xffu;
        msgpack_pack_uint32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xccu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint32_t v = 0x100u;
        msgpack_pack_uint32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcdu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint32_t v = 0xffffu;
        msgpack_pack_uint32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcdu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint32_t v = 0x10000u;
        msgpack_pack_uint32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xceu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint32_t v = 0xffffffffu;
        msgpack_pack_uint32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xceu));

        msgpack_sbuffer_destroy(&sbuf);
    }
}

TEST(int_head_c, uint64)
{
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint64_t v = 0x7fu;
        msgpack_pack_uint64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0x7fu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint64_t v = 0x80u;
        msgpack_pack_uint64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xccu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint64_t v = 0xffu;
        msgpack_pack_uint64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xccu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint64_t v = 0x100u;
        msgpack_pack_uint64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcdu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint64_t v = 0xffffu;
        msgpack_pack_uint64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcdu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint64_t v = 0x10000u;
        msgpack_pack_uint64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xceu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint64_t v = 0xffffffffu;
        msgpack_pack_uint64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xceu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint64_t v = 0x100000000LLu;
        msgpack_pack_uint64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcfu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        uint64_t v = 0xffffffffffffffffLLu;
        msgpack_pack_uint64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcfu));

        msgpack_sbuffer_destroy(&sbuf);
    }
}

TEST(int_head_c, int8)
{
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int8_t v = 0x7fu;
        msgpack_pack_int8(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0x7fu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int8_t v = -32;
        msgpack_pack_int8(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xe0u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int8_t v = -128;
        msgpack_pack_int8(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd0u));

        msgpack_sbuffer_destroy(&sbuf);
    }
}

TEST(int_head_c, int16)
{
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = 0x7fu;
        msgpack_pack_int16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0x7fu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = -32;
        msgpack_pack_int16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xe0u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = -128;
        msgpack_pack_int16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd0u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = 128;
        msgpack_pack_int16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = -129;
        msgpack_pack_int16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = 32767;
        msgpack_pack_int16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = -32768;
        msgpack_pack_int16(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
}

TEST(int_head_c, int32)
{
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = 0x7fu;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0x7fu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = -32;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xe0u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = -128;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd0u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = 128;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = -129;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = 32767;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = -32768;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = 32768;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd2u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = -32769;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd2u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = 2147483647;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd2u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = -2147483648;
        msgpack_pack_int32(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd2u));

        msgpack_sbuffer_destroy(&sbuf);
    }
}

TEST(int_head_c, int64)
{
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = 0x7fuLL;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0x7fu));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = -32;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xe0u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = -128;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd0u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = 128;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int16_t v = -129;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = 32767;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = -32768;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = 32768;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd2u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int32_t v = -32769;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd2u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = 2147483647;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd2u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = -2147483648;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd2u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = 2147483648LL;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd3u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = -2147483649LL;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd3u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = 0x7fffffffffffffffLL;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd3u));

        msgpack_sbuffer_destroy(&sbuf);
    }
    {
        msgpack_sbuffer sbuf;
        msgpack_sbuffer_init(&sbuf);
        msgpack_packer pk;
        msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

        int64_t v = 0x8000000000000000LL;
        msgpack_pack_int64(&pk, v);
        EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd3u));

        msgpack_sbuffer_destroy(&sbuf);
    }
}

TEST(int_head_c, fix_uint8)
{
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);
    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    uint8_t v = 0;
    msgpack_pack_fix_uint8(&pk, v);
    EXPECT_EQ(sbuf.data[0], static_cast<char>(0xccu));

    msgpack_sbuffer_destroy(&sbuf);
}

TEST(int_head_c, fix_uint16)
{
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);
    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    uint16_t v = 0;
    msgpack_pack_fix_uint16(&pk, v);
    EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcdu));

    msgpack_sbuffer_destroy(&sbuf);
}

TEST(int_head_c, fix_uint32)
{
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);
    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    uint32_t v = 0;
    msgpack_pack_fix_uint32(&pk, v);
    EXPECT_EQ(sbuf.data[0], static_cast<char>(0xceu));

    msgpack_sbuffer_destroy(&sbuf);
}

TEST(int_head_c, fix_uint64)
{
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);
    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    uint64_t v = 0;
    msgpack_pack_fix_uint64(&pk, v);
    EXPECT_EQ(sbuf.data[0], static_cast<char>(0xcfu));

    msgpack_sbuffer_destroy(&sbuf);
}

TEST(int_head_c, fix_int8)
{
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);
    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    int8_t v = 0;
    msgpack_pack_fix_int8(&pk, v);
    EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd0u));

    msgpack_sbuffer_destroy(&sbuf);
}

TEST(int_head_c, fix_int16)
{
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);
    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    int16_t v = 0;
    msgpack_pack_fix_int16(&pk, v);
    EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd1u));

    msgpack_sbuffer_destroy(&sbuf);
}

TEST(int_head_c, fix_int32)
{
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);
    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    int32_t v = 0;
    msgpack_pack_fix_int32(&pk, v);
    EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd2u));

    msgpack_sbuffer_destroy(&sbuf);
}

TEST(int_head_c, fix_int64)
{
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);
    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    int64_t v = 0;
    msgpack_pack_fix_int64(&pk, v);
    EXPECT_EQ(sbuf.data[0], static_cast<char>(0xd3u));

    msgpack_sbuffer_destroy(&sbuf);
}
