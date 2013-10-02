#include "../servers/string_stream.hpp"

#include <iostream>
#include <string.h>

using namespace Mangle::Stream;
using namespace std;

int main()
{
  StreamPtr inp = StringStream::Open("hello world!");

  cout << "Size: " << inp->size() << endl;
  cout << "Pos: " << inp->tell() << "\nSeeking...\n";
  inp->seek(3);
  cout << "Pos: " << inp->tell() << endl;
  char data[12];
  memset(data, 0, 12);
  cout << "Reading: " << inp->read(data, 4) << endl;
  cout << "Four bytes: " << data << endl;
  cout << "Eof: " << inp->eof() << endl;
  cout << "Pos: " << inp->tell() << "\nSeeking again...\n";
  inp->seek(33);
  cout << "Pos: " << inp->tell() << endl;
  cout << "Eof: " << inp->eof() << "\nSeek to 6\n";
  inp->seek(6);
  cout << "Eof: " << inp->eof() << endl;
  cout << "Pos: " << inp->tell() << endl;
  cout << "Over-reading: " << inp->read(data, 200) << endl;
  cout << "Result: " << data << endl;
  cout << "Eof: " << inp->eof() << endl;
  cout << "Pos: " << inp->tell() << endl;
  inp->seek(0);
  cout << "Finally, reading the entire string: " << inp->read(data,11) << endl;
  cout << "Result: " << data << endl;
  cout << "Eof: " << inp->eof() << endl;
  cout << "Pos: " << inp->tell() << endl;

  cout << "Entire stream from pointer: " << (char*)inp->getPtr() << endl;
  
  return 0;
}
