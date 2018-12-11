#include <iostream>
#include <type_traits>

namespace bode{
  struct has_momoka_function_impl{
    template<class F>
    static constexpr auto check(F&& f)->decltype(f.momoka(), std::true_type{});
    
    template<class F>
    static constexpr auto check(...)->std::false_type;
  };

  template<class F>
  struct has_momoka_function :
    public decltype(has_momoka_function_impl::check<F>(std::declval<F>())){};

  class idol{
    public:
      void momoka(){}
  };

  class bode{};
}

int main(){
  static_assert(bode::has_momoka_function<bode::idol>::value == true, "no momoka");
  static_assert(bode::has_momoka_function<bode::bode>::value == false, "yes momoka");
}