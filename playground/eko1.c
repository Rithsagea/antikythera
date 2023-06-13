#include "stdio.h"
#include "string.h"
#include "ctype.h"

void split_vowels(char* str, char* vowels) {
  char allVowels[] = "aeiou";
  int vowelCount = 0, len = strlen(str);

  for (int i = 0; i < len; i++) {
    str[i - vowelCount] = str[i];
    for (int j = 0; j < 5; j++)
      if (tolower(str[i]) == allVowels[j])
        vowels[vowelCount++] = str[i];
  }

  for (int i = len - vowelCount; i < len; i++)
    str[i] = '\0';

}

int main() {
  char word[] = "Hello There, I'm Hatsune Miku!";
  char vowels[1000] = "";

  split_vowels(word, vowels);

  printf("%s\n%s\n", word, vowels);
}