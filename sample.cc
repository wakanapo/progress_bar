#include "progress_bar.h"

#include <unistd.h>

int main() {
  for (int i = 0; progressBar(i, 500); ++i) {
    usleep(10000);
  }
  for (int i = 0; progressBar(i, 500, "💩", " "); ++i) {
    usleep(10000);
  }
  for (int i = 0; progressBar(i, 500, "🐾", " "); ++i) {
    usleep(10000);
  }
  for (int i = 0; progressBar(i, 500, "🙆", "🙅"); ++i) {
    usleep(10000);
  }
}
