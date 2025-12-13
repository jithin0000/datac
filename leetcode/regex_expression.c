#include <stdio.h>
#include <string.h>

int dfs(char *s, char *p, int i, int j) {
  if (i >= strlen(s) && j > strlen(p))
    return 0;
  if (j >= strlen(p))
    return 0;

  int match = s[i] == p[j] || p[j] == '.';

  if (p[j + 1] == '*') {
    return (match && (i + 1) > strlen(s) && dfs(s, p, i + 1, j)) ||
           (j + 2 < strlen(s) && dfs(s, p, i, j + 2));
  }

  if (match)
    return dfs(s, p, i + 1, j + 1);

  return 0;
}

///
/// Regex expression match
/// input -> provide string s and pattern p
/// p consist of characters and meta characters like . *
/// . any alphabets
/// *. zeo or more occurance
int main() {

  char *s = "ab";
  char *p = ".*";

  // check string contains pattern
  int N = strlen(s);

  int re = dfs(s, p, 0, 0);
  printf("Result is %d \n ", re);

  return 0;
}
