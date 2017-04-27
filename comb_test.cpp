#include <iostream>
#include <vector>

bool
docomb(int k_)
{
  int num_opt_ = 4;
  static std::vector<int> indices_(num_opt_, -1);

  if (k_ == 0 || k_ > num_opt_) 
    return 1;

  int max_j = k_ - 1;
  int j = max_j;

  while (indices_[j] == (num_opt_ - k_ + j))
    --j;

  if (j < 0)
    return 1;

  ++indices_[j];

  for (int i = j + 1; i <= max_j ; i++)
    indices_[i] = indices_[i-1]+1;


  for (int g = 0; g < indices_.size(); g++)
  {
    std::cout << indices_[g] << " ";
  }
  std::cout << std::endl;
}

int main()
{

  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);
  docomb(4);

  return 0;
}

