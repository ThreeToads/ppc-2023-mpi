//
// Copyright 2023 ThreeToads
//

#include <gtest/gtest.h>#
include <mpi.h>
#include <string>
#include <iostream>
#include <fstream>
#include "./count_sentence_string.h"


TEST(Parallel_Operations_MPI, Test_1) {
    std::string test_string =
        "The four seasons of the year are beautiful and pleasant!"
        "Summer is the most colourful season."
        "There are a lot of flowers at this time.";

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int global_sum = parallelSentenceCount(test_string);

    if (rank == 0) {
        int local_cnt = computeSenteceCount(test_string);
#ifdef debug
        std::cout << "Res=" << computeSenteceCount(test_string) << std::endl;
        std::cout << "Res parallel =" << global_sum << std::endl;
#endif
        ASSERT_EQ(local_cnt, global_sum);
    }
}

// Test if string sentences is ""
TEST(Parallel_Operations_MPI, Test_2) {
    std::string test_string = "";
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int global_sum = parallelSentenceCount(test_string);

    if (rank == 0) {
        int local_cnt = computeSenteceCount(test_string);
#ifdef debug
        std::cout << "Res=" << computeSenteceCount(test_string) << std::endl;
        std::cout << "Res parallel =" << global_sum << std::endl;
#endif
        ASSERT_EQ(local_cnt, global_sum);
    }
}

// Test if string is a single word
TEST(Parallel_Operations_MPI, Test_3) {
    std::string test_string = "A!";
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int global_sum = parallelSentenceCount(test_string);

    if (rank == 0) {
        int local_cnt = computeSenteceCount(test_string);
#ifdef debug
        std::cout << "Res=" << computeSenteceCount(test_string) << std::endl;
        std::cout << "Res parallel =" << global_sum << std::endl;
#endif
        ASSERT_EQ(local_cnt, global_sum);
    }
}

// A sentence contains line ending characters typeof ?! or ... or !! and so on
TEST(Parallel_Operations_MPI, Test_4) {
    std::string test_string = "One was a car!? Two was a car?!"
        "Three was a car... Four was a car!?";
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int global_sum = parallelSentenceCount(test_string);

    if (rank == 0) {
        int local_cnt = computeSenteceCount(test_string);
#ifdef debug
        std::cout << "Res=" << computeSenteceCount(test_string) << std::endl;
        std::cout << "Res parallel =" << global_sum << std::endl;
#endif
        ASSERT_EQ(local_cnt, global_sum);
    }
}

// A sentence made of digits
TEST(Parallel_Operations_MPI, Test_5) {
    std::string test_string = "1921!22231.123?1222!!";
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int global_sum = parallelSentenceCount(test_string);

    if (rank == 0) {
        int local_cnt = computeSenteceCount(test_string);
#ifdef debug
        std::cout << "Res=" << computeSenteceCount(test_string) << std::endl;
        std::cout << "Res parallel =" << global_sum << std::endl;
#endif
        ASSERT_EQ(local_cnt, global_sum);
    }
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    MPI_Init(&argc, &argv);

    ::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
    ::testing::TestEventListeners& listeners =
        ::testing::UnitTest::GetInstance()->listeners();

    listeners.Release(listeners.default_result_printer());
    listeners.Release(listeners.default_xml_generator());

    listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);
    return RUN_ALL_TESTS();
}
