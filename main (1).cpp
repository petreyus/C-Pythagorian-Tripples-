#include <vector>    
#include <algorithm> 
#include <iostream>  
// form used to calc each side; taken from wiki: a=m^{2}-n^{2},b=2mn,c=m^{2}+n^{2} 



// init of my vars
struct triple
{
  int a;
  int b;
  int c;
  bool operator< (triple& t) { return c < t.c; } 
};

// Function to order the results column a, b ,c etc
std::ostream& operator << (std::ostream& o, triple& t)
{
  return o << "a: " << t.a << "\tb: " << t.b << "\tc: " << t.c << std::endl;
}

// Basically elimnating the non-interger results that satisfy the equation
bool primeCO(int m, int n)
{
  for (int i = 2; i < n/2; ++i)
    if (m%i==0 && n%i==0) 
      return false;	
  return true;
}

void getTriples(int max, std::vector<triple>& set)
{
  for (int m = 2; m <= max; ++m)
  {
    for (int n = 1; n < m; ++n) 
    {
      if ( primeCO(m,n) && ((m-n)%2==1)) 
      {
        triple temp;
        temp.a = m*m - n*n; // taken from wikipedia
        temp.b = 2*m*n;
        temp.c = m*m + n*n;
        
        if (temp.c > max) return; // Stop Condition 
        
        set.push_back(temp);	  
      }
    }
  }
}

int main()
{
  // a container
  std::vector<triple> Triples;
  
  // Fill container 
  getTriples(500, Triples);
  
  // Sort 
  std::sort(Triples.begin(), Triples.end());
  
  // Print 
  for (std::vector<triple>::iterator it = Triples.begin(); it != Triples.end(); ++it)
    std::cout << *it;
  
  return 0;
}


