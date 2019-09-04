#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "diff.h"
#include "utils.h"

int main(int argc, char* argv[]) {
  if(!validate_args(argc, argv)) {
      std::cout<<"USAGE: xdiff <path_to_file_1> <path_to_file_2>"<<std::endl;
      exit(EXIT_FAILURE);
  }

  double res = doc_similarity(argv[1], argv[2]);
  std::cout<<argv[1]<<" and "<<argv[2]<<" are "<<res<<"% similar."<<std::endl;
  return 0;
}
