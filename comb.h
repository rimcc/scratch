#include <iostream>
#include <string>
#include <vector>

typedef std::vector<int> IdxVec;

/* The base class that takes care of generating 
	the combinations that subclasses are tracking.
*/
struct Combinational
{
  Combinational(unsigned int const&);

  //
  bool
    more();

  // Can use this combo to generate more from?
  virtual bool
    valid();

  // 
  virtual void
    build() {};

  // Reset the counters
  virtual void
    reset() {}; 

  // Get the next combination or if no more
  // then increment k and try again.
  bool
    next();

  // Does this combination contain member m?
  bool
    has_member(int const& m);

  void
    print(std::string const&) const;

  void
    print_idx() const;

  private:

  bool
    get_combination();

  unsigned int k_;				      // Select k from 
  unsigned int const num_opt_;	// n
  IdxVec indices_; 				      // max index into indices is k-1;
  bool valid_;					        // Got another combo?
};


