//
// Copyright 2023 ThreeToads
//

#ifndef SOURCE_REPOS_PPC_2023_MPI_TASKS_TASK_1_KOKIN_I_COUNT_SENTENCE_IN_SRTING_COUNT_SENTENCE_STRING_H_
#define SOURCE_REPOS_PPC_2023_MPI_TASKS_TASK_1_KOKIN_I_COUNT_SENTENCE_IN_SRTING_COUNT_SENTENCE_STRING_H_

#include <string>
#include <vector>

std::vector<std::string> parseText(std::string str, int proc_num);

int computeSenteceCount(std::string str);

int parallelSentenceCount(const std::string& str);

#endif  // SOURCE_REPOS_PPC_2023_MPI_TASKS_TASK_1_KOKIN_I_COUNT_SENTENCE_IN_SRTING_COUNT_SENTENCE_STRING_H_
