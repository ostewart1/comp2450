1.) Running log after running search a few times:
	1. began session as "Olivia"
	(newest first; chain length 15)

2.) After running search a few times and then running log:
	(the chain is empty nothing to remember yet)
	After running selftest iterator:
		the lens does not recognize ''.
3.) In one sentence - what invariant of the iterator contract did the broken end() violate?
The iterator must always point to a valid element or indicate that it has reached the end

4.) Compiler Error: >------ Build started: Project: CMakeLists, Configuration: Debug ------
  [1/2] Building CXX object CMakeFiles\the_descent.dir\main.cpp.obj
  FAILED: [code=2] CMakeFiles/the_descent.dir/main.cpp.obj 
  C:\PROGRA~1\MIB055~1\18\COMMUN~1\VC\Tools\MSVC\1451~1.362\bin\Hostx64\x64\cl.exe  /nologo /TP   /DWIN32 /D_WINDOWS /GR /EHsc /Zi /Ob0 /Od /RTC1 -std:c++17 -MDd /W4 /showIncludes /FoCMakeFiles\the_descent.dir\main.cpp.obj /FdCMakeFiles\the_descent.dir\ /FS -c C:\Users\Admin\Documents\GitHub\comp2450\project\floor-05-starter\main.cpp
C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9085): error C2676: binary '-': 'const _InIt' does not define this operator or a conversion to a type acceptable to the predefined operator
          with
          [
              _InIt=dungeon::Chain<std::string>::iterator
          ]
  C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\xutility(4711): note: could be 'unknown-type std::operator -(const std::move_iterator<_Iter> &,const std::move_iterator<_Iter2> &) noexcept(<expr>)'
  C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9085): note: 'unknown-type std::operator -(const std::move_iterator<_Iter> &,const std::move_iterator<_Iter2> &) noexcept(<expr>)': could not deduce template argument for 'const std::move_iterator<_Iter> &' from 'const _InIt'
          with
          [
              _InIt=dungeon::Chain<std::string>::iterator
          ]
  C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\xutility(2176): note: or       'unknown-type std::operator -(const std::reverse_iterator<_BidIt> &,const std::reverse_iterator<_BidIt2> &) noexcept(<expr>)'
  C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9085): note: 'unknown-type std::operator -(const std::reverse_iterator<_BidIt> &,const std::reverse_iterator<_BidIt2> &) noexcept(<expr>)': could not deduce template argument for 'const std::reverse_iterator<_BidIt> &' from 'const _InIt'
          with
          [
              _InIt=dungeon::Chain<std::string>::iterator
          ]
  C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9085): note: the template instantiation context (the oldest one first) is
  C:\Users\Admin\Documents\GitHub\comp2450\project\floor-05-starter\main.cpp(109): note: see reference to function template instantiation 'void std::sort<dungeon::Chain<std::string>::iterator>(const _RanIt,const _RanIt)' being compiled
          with
          [
              _RanIt=dungeon::Chain<std::string>::iterator
          ]
  C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9090): note: see reference to function template instantiation 'void std::sort<_RanIt,std::less<void>>(const _RanIt,const _RanIt,_Pr)' being compiled
          with
          [
              _RanIt=dungeon::Chain<std::string>::iterator,
              _Pr=std::less<void>
          ]
C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9085): error C2672: 'std::_Sort_unchecked': no matching overloaded function found
  C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9051): note: could be 'void std::_Sort_unchecked(_RanIt,_RanIt,iterator_traits<_Iter>::difference_type,_Pr)'
  C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9085): note: 'void std::_Sort_unchecked(_RanIt,_RanIt,iterator_traits<_Iter>::difference_type,_Pr)': expects 4 arguments - 3 provided
  ninja: build stopped: subcommand failed.

  - void std::sort<_RanIt,std::less<void>>(const _RanIt,const _RanIt,_Pr)
  - Which operation is the standard library asking for that your iterator doesn't provide? 
    The operation that the standard library is asking for that my iterator doesn't provide is the subtraction operator (-) to calculate the distance between 2 iterators

5.) In two sentences: Which verstion is easier to maintain when you later change the container type, and why?
    The version using auto is easier to maintain when the container type changes.
    This is because auto automatically determines the correct iterator type, so you do not have to change the iterator declaration when the container type changes.
6.) The iterator type provides an abstraction for moving through a container without the function needing to know how the container is actually implemented. In the two versions of printLog, 
the same basic operations were being performed, but the starting and ending positions were different. The iterator lets the function work with the current position 
in the container while hiding the details of how the chain is connected. Because of this, the forward and backward versions can be combined into one function instead of 
needing separate functions with nearly identical code.