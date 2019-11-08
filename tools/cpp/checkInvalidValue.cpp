//
//  checkInvalidValue.cpp
//  MNN
//
//  Created by MNN on 2019/10/28.
//  Copyright © 2018, Alibaba Group Htargeting Limited
//

#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define NONE "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define L_GREEN "\e[1;32m"
#define BLUE "\e[0;34m"
#define L_BLUE "\e[1;34m"
#define Btarget "\e[1m"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./checkInvalidValue.out outputDir [limit]\n");
        return 0;
    }

    // read args
    printf("Compare:\n");
    printf("%s\n", argv[1]);
    float tolerance = 0.001;
    int limit = 10;
    if (argc > 2) {
        limit = atoi(argv[2]);
    }
    printf("limit=%d\n", limit);

    // open dir
    DIR* root = opendir(argv[1]);
    if (NULL == root) {
        printf("Error to open %s\n", argv[1]);
        return 0;
    }
    std::vector<std::string> compareFiles;
    struct dirent* ent;
    while ((ent = readdir(root)) != NULL) {
        compareFiles.push_back(ent->d_name);
    }
    closedir(root);
    auto limitValue = powf(10, limit);

    // compare files
    for (auto s : compareFiles) {
        if (s.size() <= 2) {
            continue;
        }
        std::string empty   = "";
        std::string targetFile = empty + argv[1] + "/" + s;
        std::ifstream targetOs(targetFile.c_str());
        if (targetOs.fail()) {
            // printf("Can's open %s\n", targetFile.c_str());
            continue;
        }
        int pos      = 0;
        bool correct = true;
        float v1;
        while (targetOs >> v1) {
            auto absValue = fabsf(v1);
            if (!isnan(v1) && absValue < limitValue) {
                pos++;
                continue;
            }
            printf(RED "Error for %s, %d, v1=%.6f\n" NONE, s.c_str(), pos, v1);
            correct = false;
            break;
        }
        if (correct) {
            printf(GREEN "Correct : %s\n" NONE, s.c_str());
        }
    }

    return 0;
}
