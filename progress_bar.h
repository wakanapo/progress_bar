#pragma once
#include <cstdio>
#include <iostream>

namespace {
  std::string makeBar(std::string b) {
    std::string bar;
    for (int i = 0; i < 100; ++i) {
      bar += b;
    }
    return bar;
  }
  std::string null_bar;
  std::string fill_bar;
}  // namespace

bool progressBar(int i, int n, std::string fill, std::string null) {
  if (null_bar.size() == 0)
    null_bar = makeBar(null);
  if (fill_bar.size() == 0)
    fill_bar = makeBar(fill);
  if (i < n) {
    int progress = ((i+1)*100)/n;
    printf("\r%d%%|", progress);
    std::cout << fill_bar.substr(0, fill.size()*progress)
              << null_bar.substr(0, null.size()*(100 - progress));
    printf("| %d/%d", i+1, n);
    progress == 100 ? std::cout << std::endl : std::cout << std::flush;
    return true;
  }
  null_bar = "";
  fill_bar = "";
  return false;
}

bool progressBar(int i, int n) {
  return progressBar(i, n, "█", "░");
}
