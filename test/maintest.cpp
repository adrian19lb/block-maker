#ifndef MAINTEST_CPP_INCLUDED
#define MAINTEST_CPP_INCLUDED

// #define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE "C++ Unit Test for block-maker"
#include <boost/test/unit_test.hpp>
#include <gmock/gmock.h>

struct InitGmock {

    InitGmock() {
        ::testing::GTEST_FLAG(throw_on_failure) = true;
        ::testing::InitGoogleMock( &boost::unit_test::framework::master_test_suite().argc,
                                    boost::unit_test::framework::master_test_suite().argv);
    }

    ~InitGmock() = default;
};

BOOST_GLOBAL_FIXTURE(InitGmock);

#endif // MAINTEST_CPP_INCLUDED
