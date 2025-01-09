#include <cs50.h>
#include <stdio.h>

void version_1();
void version_2();
void version_3();
void version_4();

int main(){
  printf("Version 1\n");
  version_1();
  printf("-----------------------\n");

  printf("Version 2\n");
  version_2();
  printf("-----------------------\n");

  printf("Version 3\n");
  version_3();
  printf("-----------------------\n");

  printf("Version 4\n");
  version_4();
  printf("-----------------------\n");
}

void version_1(){
  int score1 = 72;
  int score2 = 73;
  int score3 = 33;

  printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
}

void version_2(){
  int scores[] = {72, 73, 33};

  printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}

void version_3(){
  // Get number of scores
  const int SIZE = get_int("How many scores do you want to save? ");

  // Get Scores
  int scores[SIZE];
  for(int i = 0; i < SIZE; i++){
    scores[i] = get_int("Score %i: ", i + 1);
  }

  // Calculate Average
  float average = 0;
  for(int i = 0; i < SIZE; i++){
    average += scores[i];
  }
  average /= (float) SIZE;

  printf("Average: %f\n", average);
}
