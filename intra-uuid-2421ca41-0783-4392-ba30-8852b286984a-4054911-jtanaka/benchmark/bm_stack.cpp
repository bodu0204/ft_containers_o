#include <unistd.h>

#include <stack>

#include "benchmarks.hpp"
#include "stack.hpp"
#include "timer.hpp"

namespace {
template <class T>
inline void add_nums_into_stack(std::stack<T>& std_stack,
                                ft::stack<T>& ft_stack,
                                const int default_stack_size) {
  for (int i = 0; i < default_stack_size; ++i) {
    std_stack.push(i);
    ft_stack.push(i);
  }
}

void measure_stack_constructor_and_assignation();
void measure_stack_element_access_and_capacity();
void measure_stack_modifiers();
}  // namespace

void measure_stack() {
  measure_stack_constructor_and_assignation();
  measure_stack_element_access_and_capacity();
  measure_stack_modifiers();
}

namespace {
void measure_stack_constructor_and_assignation() {
  HEADER("measure_stack_constructor_and_assignation");

  typedef std::stack<int> std_stack_type;
  typedef ft::stack<int> ft_stack_type;

  const int default_stack_size = 1000000;

  std_stack_type std_stack;
  std_stack_type std_stack_for_copy;
  ft_stack_type ft_stack;
  ft_stack_type ft_stack_for_copy;

  add_nums_into_stack(std_stack_for_copy, ft_stack_for_copy,
                      default_stack_size);

  {
    TIMER("std::stack constructor");
    std_stack_type tmp;
  }
  {
    TIMER("ft::stack constructor");
    ft_stack_type tmp;
  }

  {
    TIMER("std::stack copy constructor");
    std_stack_type tmp = std_stack_for_copy;
  }
  {
    TIMER("ft::stack copy constructor");
    ft_stack_type tmp = ft_stack_for_copy;
  }

  {
    TIMER("std::stack assignation operator");
    std_stack = std_stack_for_copy;
  }
  {
    TIMER("ft::stack assignation operator");
    ft_stack = ft_stack_for_copy;
  }
}

void measure_stack_element_access_and_capacity() {
  HEADER("measure_stack_element_access_and_capacity");

  typedef std::stack<int> std_stack_type;
  typedef ft::stack<int> ft_stack_type;

  const int default_stack_size = 1000000;

  std_stack_type std_stack;
  ft_stack_type ft_stack;

  add_nums_into_stack(std_stack, ft_stack, default_stack_size);

  {
    TIMER("std::stack top");
    std_stack.top();
  }
  {
    TIMER("ft::stack top");
    ft_stack.top();
  }

  {
    TIMER("std::stack empty");
    std_stack.empty();
  }
  {
    TIMER("ft::stack empty");
    ft_stack.empty();
  }

  {
    TIMER("std::stack size");
    std_stack.size();
  }
  {
    TIMER("ft::stack size");
    ft_stack.size();
  }
}

void measure_stack_modifiers() {
  HEADER("measure_stack_modifiers");

  typedef std::stack<int> std_stack_type;
  typedef ft::stack<int> ft_stack_type;

  const int default_stack_size = 1000000;

  std_stack_type std_stack;
  ft_stack_type ft_stack;

  {
    TIMER("std::stack push");
    for (int j = 0; j < default_stack_size; ++j) {
      std_stack.push(j);
    }
  }
  {
    TIMER("ft::stack push");
    for (int j = 0; j < default_stack_size; ++j) {
      ft_stack.push(j);
    }
  }

  {
    TIMER("std::stack pop");
    for (int j = 0; j < default_stack_size; ++j) {
      std_stack.pop();
    }
  }
  {
    TIMER("ft::stack pop");
    for (int j = 0; j < default_stack_size; ++j) {
      ft_stack.pop();
    }
  }
}
}  // namespace