#include "../servers/file_stream.hpp"
#include <iostream>

using namespace Mangle::Stream;
using namespace std;

int main()
{
  StreamPtr inp = FileStream::Open("file_server_test.cpp");

  char buf[21];
  buf[20] = 0;
  cout << "pos=" << inp->tell() << " eof=" << inp->eof() << endl;
  inp->read(buf, 20);
  cout << "First 20 bytes: " << buf << endl;
  cout << "pos=" << inp->tell() << " eof=" << inp->eof() << endl;
  return 0;
}
