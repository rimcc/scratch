#include "comb.h"

Combinational::Combinational(unsigned int const& n)
  :
    k_(0),
    num_opt_(n),
    indices_(IdxVec(n, -1)),
    valid_(true)
{
  if (num_opt_ == 0)
    valid_ = false; // no more combinations to go
}

bool
Combinational::more()
{
  return k_ < num_opt_ && valid_ ;
}

// It means we can use this combo 
bool
Combinational::valid()
{
//  std::cout << "Valid(): " << valid_ <<  "k " << k_ << std::endl;
  return valid_;
}

// Return true 
bool
Combinational::next()
{
  bool r = false;

  // If we have no optional members we have nothing to do,
  // so we will bail, if we do have more then we should try
  // and get a combination out of them.
  if (num_opt_ > 0)
  {
    // Try and get the next combination. If that fails then
    // let's try again with a new k_
    r = get_combination();

    while (!r && ++k_ <= num_opt_)
    {
      // Re-init indices_ and return this combination, 
      // and if k is still <= num_opts then return true.
      for (size_t i = 0; i < k_; i++)
        indices_[i] = i;

      print_idx();
      this->reset(); // What should be reset?

      if (k_ <= num_opt_)
        r = true;
    }
  }

  //std::cout << "next returning: " << r <<" " << k_ << " " << num_opt_ << std::endl;
  valid_ = r;
  return r;
}

bool
Combinational::get_combination()
{
  // If we've got no options to pick (k == 0) 
  // or we've exceed the number (k > num_opt_)
  // then nothing to do or return
  if (k_ == 0 || k_ > num_opt_) 
    return false;

  int max_j = k_ - 1;
  int j = max_j;

  while (indices_[j] == (num_opt_ - k_ + j))
    --j;

  if (j < 0)
  {
    //std::cout << "J<0 " << j << "k " << k_ << std::endl;
    return false;
  }

  ++indices_[j];

  for (int i = j + 1; i <= max_j ; i++)
    indices_[i] = indices_[i-1]+1;

  return true;
}


void
Combinational::print_idx() const
{
#if 0
  for (size_t i = 0; i < indices_.size(); i++)
    std::cout << "[" << indices_[i] << "]"; 
  std::cout << std::endl;
#endif
}

/*
   Check the set of subobject flags for a match.
   */
bool
Combinational::has_member(int const& m)
{
 // std::cout << "has_member(" << m  << ")";
  for (size_t i = 0; i < indices_.size(); i++)
  {
    if (indices_[i] == m)
    {
   //   std::cout << ":true {" << i << "}" << std::endl;
      return true;
    }
  }
  //std::cout << ":false" << std::endl;
  return false;
}

void
Combinational::print(std::string const& s) const
{
#ifdef DEBUG
  std::cout
    << s << " "
    << "Comb: "
    << "k: " << k_ << " "
    << "num_opt: " <<num_opt_ << " "
    << "valid: " << valid_
    << std::endl;

  std::cout << "Indices:[";
  for (size_t i = 0; i < indices_.size(); i++)
  {
    std::cout << indices_[i] << ",";
  }
  std::cout << "]" << std::endl;
#endif
}

