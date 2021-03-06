#ifndef INCLUDE_READ_CSV_H
#define INCLUDE_READ_CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baseball_struct.h"

#define LINE_LENGTH 128

char team_name[6][64] = {
  "広島東洋カープ",
  "阪神タイガース",
  "読売ジャイアンツ",
  "中日ドラゴンズ",
  "DeNAベイスターズ",
  "ヤクルトスワローズ"
};

Player read_csv(char line[], int team_num) {
  Player ret;
  sscanf(line, "%d,%[^,],%d,%d,%d,%d,%[^,],%[^,\n]", &ret.uniform_number, ret.player_name
      , &ret.years, &ret.age, &ret.height, &ret.weight, ret.hand, ret.school_name);
  strcpy(ret.team_name, team_name[team_num]);

  return ret;
}

/*
int main(void) {
  char filename[] = "./data/carp.csv";
  char readline[LINE_LENGTH];
  Player player;
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("error: Can not file open");
    return EXIT_FAILURE;
  }
  while (fgets(readline, LINE_LENGTH, fp) != NULL) {
    printf("%s\n", readline);
    player = read_csv(readline, "hoge");
    printf("1: %d\n", player.uniform_number);
  }

  return (0);
}
*/

#endif

